#pragma once
#include "Pista.h"
#include "Garagem.h"
#include <string>
#include <vector>

using namespace std;

class Autodromo {
	// Nome do Autodromo unico, validado pela class
	static vector<string> nomesAuto;
	string nome;

	Pista *pista;
	Garagem *garage;

public:

	Autodromo(int maxcarros, int tamPista, string n);

	string getNome() const;

	~Autodromo();
	//garagem 

};
