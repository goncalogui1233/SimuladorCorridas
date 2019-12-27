#include "Pista.h"

Pista::Pista(int maxcarros, int tamPista)
	:maxCar(maxcarros), metros(tamPista){}

Pista::~Pista() {
	vector<Piloto*>::iterator it;
	for (it = pilotosPista.begin(); it != pilotosPista.end(); it++)
		delete *it;
}

//coloca um piloto no vetor da pista
void Pista::inserePilotoNaPista(Piloto* aux) {
	pilotosPista.push_back(aux);
}

//retira piloto da pista que contem um certo carro!!! :)
Piloto* Pista::retiraPiloto(char id) {
	vector<Piloto*>::iterator it;
	for (it = pilotosPista.begin(); it != pilotosPista.end();)
		if ((*it)->getIDCar() == id) {
			Piloto* aux = (*it);
			it = pilotosPista.erase(it);
			return aux;
		}
		else
			it++;

	return nullptr;
}
