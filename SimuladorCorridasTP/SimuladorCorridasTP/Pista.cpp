#include "Pista.h"

Pista::Pista(int maxcarros, int tamPista)
	:maxCar(maxcarros), metros(tamPista){}

Pista::~Pista() {
	vector<Carro*>::iterator it;
	for (it = carros.begin(); it != carros.end(); it++)
		delete *it;
}
