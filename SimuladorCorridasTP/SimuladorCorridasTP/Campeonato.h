#pragma once
#include "Autodromo.h"
#include "Pontuacoes.h"
#include "Piloto.h"
#include "Corrida.h"
#include <algorithm>
#include <string>

using namespace std;

class Campeonato {
	int autodromoAtual;
	string logRegisto;
	vector<Autodromo*> autodromos;
	vector<Piloto*> participantes;
	vector<Pontuacoes*> tabelaGeral;
	Corrida* c;

	bool verificarSeExiste(string nome, int pontos);

public:

	Campeonato() {
		c = nullptr;
		autodromoAtual = 0;
	}

	/*void mostraPista() const {
		autodromos[0]->mostraPista();
	}*/

	size_t returnNumCarrosPista() const {
		return autodromos[autodromoAtual]->returnNumPilotosPista();
	}

	char returnIDCarroPista(int i) const {
		return autodromos[autodromoAtual]->returnIDCarro(i);
	}

	int returnPosX(int i) const {
		return c->returnPosX(i);
	}

	string returnFraseLog() const {
		return logRegisto;
	}

	string carregaCarro(char id, int mAh);

	string carregaTodosCarros();

	bool returnSeExisteCorrida() const;

	string adicionaParticipantes(Piloto* aux);

	void adicionarAutodromos(Autodromo* aux);

	string criarCorrida(int rep);

	void retiraPilotoCorrida(char id);

	void aceleraCarrosInit();

	bool avancarTempo();

	void inserePilotosEmPista();

	string listaCarrosCampeonato() const;

	string listaClassificacaoCorrida() const {
		return c->mostraPosicoes();
	}
};

