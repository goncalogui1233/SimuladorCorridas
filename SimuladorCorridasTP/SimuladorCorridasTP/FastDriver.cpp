#include "FastDriver.h"

FastDriver::FastDriver(string name)
	:Piloto(name), tempoAteAcelerar(0){}

FastDriver::FastDriver(const FastDriver &aux)
	:Piloto(aux), tempoAteAcelerar(0){}


Piloto* FastDriver::clone() const {
	return new FastDriver(*this);
}

void FastDriver::passaTempo(int posPista, int numCorredores, int tempo) {
	if (getEnergiaAtual() > (getCapacidadeMax() / 2)) { //enquanto a energia disponivel for maior que a metade da capacidade, acelera
		acelera();
	}
	else { //caso a energia disponivel seja menor que a metade da capacidade
		if (tempoAteAcelerar != 3){ //verificação para saber se deve acelerar ou não
			tempoAteAcelerar++;
			desacelerar();
		}
		else {
			acelera();
			tempoAteAcelerar = 0;
		}
	}
	
	if (probEmergencia() <= 10) {
		ativarBotaoEmergencia();
	}

	drenaEnergia();

}

int FastDriver::probEmergencia() {
	default_random_engine val;
	uniform_int_distribution<int> aleatorio(1, 100);
	return aleatorio(val);
}

FastDriver::~FastDriver() {}