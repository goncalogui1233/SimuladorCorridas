#include "Pista.h"

Pista::Pista(int maxcarros, int tamPista)
	:maxCar(maxcarros), metros(tamPista){}

Pista::~Pista() {
	vector<Piloto*>::iterator it;
	for (it = pilotosPista.begin(); it != pilotosPista.end(); it++)
		delete *it;
}

void Pista::inserePilotoNaPista(Piloto* aux) {
	pilotosPista.push_back(aux);
}

Piloto* Pista::retiraPiloto(char id) {
	vector<Piloto*>::iterator it;
	for(it = pilotosPista.begin(); it != pilotosPista.end();)
		if((*it)->getIDCar() == id){
			Piloto* aux = (*it);
			it = pilotosPista.erase(it);
			return aux;
		}
		else
			it++
}
