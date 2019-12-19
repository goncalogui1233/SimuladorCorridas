#pragma once
#include "Piloto.h"
#include "Consola.h"
#include <vector>
#include <iostream>

using namespace std;

class Pista {

	int maxCar;
	int metros;
	vector <Piloto*> pilotosPista;

public:
	Pista(int maxCar, int metros);

	~Pista();

	int returnTamPista() const {
		return metros;
	}

	int returnMaxCarros() const {
		return maxCar;
	}

	size_t returnNumPilotosPista() const {
		return pilotosPista.size();
	}

	string returnNomePiloto(int i)const {
		return pilotosPista[i]->getNome();
	}

	char returnIDCarro(int i)const {
		return pilotosPista[i]->getIDCar();
	}

	void inserePilotoNaPista(Piloto* aux);

	Piloto* retiraPiloto(char id);

	// Se ligar sinal de emergencia, sai da pista, move to garagem

};

