#pragma once
#include "Autodromo.h"
#include "Pontuacoes.h"
#include "Piloto.h"
#include <algorithm>

using namespace std;

class Campeonato{
	static int autodromoAtual;
	vector<Autodromo*> autodromos;
	vector<Piloto*> participantes;
	vector<Pontuacoes> tabelaGeral;

public:

	Campeonato(){}

	string adicionaParticipantes(Piloto* aux);

	void adicionarAutodromos(Autodromo *aux);

	void insereCarrosEmPista();

	string listaCarrosCampeonato() const;
};

