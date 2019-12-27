#pragma once
#include "Autodromo.h"
#include "Posicoes.h"
#include "Piloto.h"
#include <algorithm>

class Corrida {
	const int repPista;
	int contaPosicao;
	Autodromo* aut;
	vector<Posicoes*> classificacao;
	int tempoCorrida;
	string infoLog = "";

	int returnPosicaoEmPista(string nomePil);
	void atualizaVecClass();
	bool finalCorrida();
	void eliminarDaClassificacao(string n1, string n2 = "");
	void atualizarMetrosPista(string piloto, int m);
	void verificaSeMudouPos();

public:

	Corrida(Autodromo* aux, int rep);

	//void atualizaPosCorrida(const vector<Piloto*> aux);

	//void aceleraCarrosInit(vector<Piloto*> aux);

	bool passaTempo();

	int returnPosX(int i) const {
		return classificacao[i]->returnPosX();
	}

	string getInfoToLog() const {
		return infoLog;
	}

	string getNomePodio(int pos) const {
		if (classificacao.size() >= pos)
			return classificacao[pos]->returnNome();
	}

	string mostraPosicoes() const;
};

