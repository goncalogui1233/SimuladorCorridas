#pragma once
#include "Autodromo.h"
#include "Pontuacoes.h"
#include "Piloto.h"
#include "Corrida.h"
#include <algorithm>

using namespace std;

class Campeonato{
	static int autodromoAtual;
	vector<Autodromo*> autodromos;
	vector<Piloto*> participantes;
	vector<Pontuacoes> tabelaGeral;
	Corrida* c;

public:

	Campeonato(){
		c = nullptr;
	}

	/*void mostraPista() const {
		autodromos[0]->mostraPista();
	}*/

	size_t returnNumCarrosPista() const {
		return autodromos[autodromoAtual]->returnNumCarrosPista();
	}

	char returnIDCarroPista(int i) const {
		return autodromos[autodromoAtual]->returnIdCarroPista(i);
	}

	int returnPosX(int i) const {
		return c->returnPosX(i);
	}

	string adicionaParticipantes(Piloto* aux);

	void adicionarAutodromos(Autodromo *aux);

	void criarCorrida(int rep);

	void aceleraCarrosInit();

	void avancarTempo(int s);

	void insereCarrosEmPista();

	string listaCarrosCampeonato() const;

	string listaClassificacaoCorrida() const {
		return c->mostraPosicoes();
	}
};

