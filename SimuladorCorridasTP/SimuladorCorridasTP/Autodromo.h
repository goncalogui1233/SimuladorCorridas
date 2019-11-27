#pragma once
#include "Pista.h"
#include "Carro.h"
#include <string>
#include <vector>

using namespace std;

class Autodromo {
	// Nome do Autodromo unico, validado pela class
	static vector<string> nomesAuto;
	string nome;
	Pista *pista;
	vector<Carro*> garagem; //garagem do autodromo

public:

	Autodromo(int maxcarros, int tamPista, string n);

	string getNome() const;

	int returnMaxCarros() const {
		return pista->returnMaxCarros();
	}

	int returnTamPista() const {
		return pista->returnTamPista();
	}

	size_t returnNumCarrosPista() const {
		return pista->returnNumCarrosPista();
	}

	char returnIdCarroPista(int i) const {
		return pista->returnIdCar(i);
	}

	void insereCarroNaPista(Carro* aux);

	void insereCarroNaGaragem(Carro* aux);

	/*void mostraPista() {
		pista->representarPista();
	}*/

	string getAsString() const;

	~Autodromo();
	//garagem 

};
