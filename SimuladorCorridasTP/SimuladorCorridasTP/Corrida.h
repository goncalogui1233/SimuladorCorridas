#pragma once
#include "Autodromo.h"
#include "Posicoes.h"
#include "Piloto.h"

class Corrida {
	const int repPista;
	int contaPosicao;
	Autodromo* aut;
	vector<Posicoes*> classificacao;

public:

	Corrida(Autodromo* aux, vector<Piloto*> part, int rep);

	void atualizaPosCorrida(const vector<Piloto*> aux);

	void aceleraCarrosInit(vector<Piloto*> aux);

	int returnPosX(int i) const {
		return classificacao[i]->returnPosX();
	}

	void verificaSeMudouPos();

	string mostraPosicoes() const;
};

