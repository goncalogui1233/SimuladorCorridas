#pragma once
#include "Carro.h"
#include "Consola.h"
#include <vector>
#include <iostream>

using namespace std;

class Pista{
	
	int maxCar;
	int metros;
	vector <Carro*> carros;

public:
	Pista(int maxCar, int metros);

	~Pista();

	int returnTamPista() const {
		return metros;
	}

	int returnMaxCarros() const {
		return maxCar;
	}

	size_t returnNumCarrosPista() const {
		return carros.size();
	}

	char returnIdCar(int i) const {
		return carros[i]->getID();
	}

	void insereCarroNaPista(Carro* aux);

	// Se ligar sinal de emergencia, sai da pista, move to garagem

};

