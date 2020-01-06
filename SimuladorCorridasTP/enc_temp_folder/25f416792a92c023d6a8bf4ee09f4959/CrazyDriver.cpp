#include "CrazyDriver.h"
#include <random>

using namespace std;

CrazyDriver::CrazyDriver(string name)
	:Piloto(name), ultimaPos(0){
	setDesatento();
	}

CrazyDriver::CrazyDriver(const CrazyDriver& aux) 
:Piloto(aux),ultimaPos(aux.ultimaPos), desatento(aux.desatento){}

Piloto * CrazyDriver::clone() const {
	return new CrazyDriver(*this);
}

void CrazyDriver::passaTempo(int posPista, int numCorredores, int tempo) {
	if (tempo < desatento) //verificação para ver quando deve começar a correr (o desatento é preenchido na criação do piloto)
		return;

	if (tempoPressAcelerador != 0) { //caso tenha de acelerar por 2 seg devido a ter perdido posiçoes
		acelera();
		tempoPressAcelerador--;
	}
	else{
		if (posPista == 1)
			desacelerar(); //talvez não desacelerar, uma vez que é dito para manter velocidade
		else if (posPista > 1 && posPista < numCorredores)
			acelera();
		else if (posPista == numCorredores)
			//trava();
			acelera();
		ultimaPos = posPista; //guarda a ultima posição registada

		if (posPista - ultimaPos >= 2) //caso tenha caido 2 ou mais lugares
			tempoPressAcelerador = 2;	//carrega a variavel para acelerar 1m/s em 2 segundos
	}
	drenaEnergia(); //retira 0,1mAH a energia atual

	if (getEnergiaAtual() == 0) //ativa emergencia caso o carro fique sem energia
		ativarBotaoEmergencia();

	if (probAcidente() == true) {//caso tenha acidente
		danificaCarro();
		//return true; //piloto atras fica também sem veiculo(talvez um return e tratar isto na corrida)
	}
}

void CrazyDriver::setDesatento() {
	default_random_engine val;
	uniform_int_distribution<int> aleatorio(1, 5);
	desatento = aleatorio(val);
	//desatento = rand() % 5 + 1;
}

bool CrazyDriver::probAcidente() {
	default_random_engine val;
	uniform_int_distribution<int> aleatorio(1, 100);
	if (aleatorio(val) <= 5)
		return true;

	return false;
}

CrazyDriver::~CrazyDriver() {}