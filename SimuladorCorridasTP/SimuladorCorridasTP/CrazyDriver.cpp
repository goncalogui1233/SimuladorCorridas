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

void CrazyDriver::passaTempoCrazy(int posPista, int numCorredores) {
	if (posPista == 1)
		desacelerar();
	else if (posPista > 1 && posPista < numCorredores)
		acelera();
	else if (posPista == numCorredores)
		trava();

	drenaEnergia();

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