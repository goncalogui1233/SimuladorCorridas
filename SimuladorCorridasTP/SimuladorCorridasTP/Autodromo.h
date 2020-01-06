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
	Pista* pista;
	vector<Piloto*> garagem; //garagem do autodromo

public:

	Autodromo(int maxcarros, int tamPista, string n);

	string getNome() const;

	int returnMaxCarros() const {
		return pista->returnMaxCarros();
	}

	int returnTamPista() const {
		return pista->returnTamPista();
	}

	size_t returnNumPilotosPista() const {
		return pista->returnNumPilotosPista();
	}

	string returnNomePiloto(int i)const {
		return pista->returnNomePiloto(i);
	}

	char returnIDCarro(int i)const {
		return pista->returnIDCarro(i);
	}

	void inserePilotoNaPista(Piloto* aux);

	void inserePilotoNaGaragem(Piloto* aux);

	void retiraPilotoDaPista(char id);

	Piloto* returnPilotoPista(int pos);

	/*void mostraPista() {
		pista->representarPista();
	}*/

	void printGaragem();

	string getAsString() const;

	~Autodromo();
	//garagem 

};
