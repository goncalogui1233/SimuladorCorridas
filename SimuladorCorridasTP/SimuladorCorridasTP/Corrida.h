#pragma once
#include "Autodromo.h"
#include "Posicoes.h"
#include "Piloto.h"

class Corrida {
	const int repPista;
	int contaPosicao;
	Autodromo* aut;
	vector<Posicoes*> classificacao;
	int tempoCorrida;

	int returnPosicaoEmPista(string nomePil);

public:

	Corrida(Autodromo* aux, int rep);

	void atualizaPosCorrida(const vector<Piloto*> aux);

	void aceleraCarrosInit(vector<Piloto*> aux);

	void passaTempo();

	int returnPosX(int i) const {
		return classificacao[i]->returnPosX();
	}

	void verificaSeMudouPos();

	string mostraPosicoes() const;
};

