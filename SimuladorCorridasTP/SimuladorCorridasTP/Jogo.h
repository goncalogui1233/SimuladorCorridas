#pragma once
#include "DGV.h"
#include "Autodromo.h"
#include "Campeonato.h"

using namespace std;

class Jogo {
	DGV* dgv;
	vector <Autodromo*> autodromos;
	Campeonato *campeonato;

public:
	Jogo();

	//Modo 1
	void carregaPilotos(string fich);

	void carregaCarrosFich(string fich);

	string criaItensJogo(vector <string> vec);

	string eliminaItemJogo(vector <string> vec);

	string inserePilotoEmCarro(vector<string>vec);

	string retiraPilotoDeCarro(vector<string>vec);

	string listagem() const;

	string escolhePilotosCampeonato(vector<string> vec);

	//Modo2

	void criaCampeonato();

	void colocaCarrosEmPista();

	string listaCarrosCampeonato();

	string adicionarAutodromoCamp(vector<string>vec);

	void passarTempo(int s);

	void mostraPista() {
		autodromos[0]->mostraPista();
	}

	~Jogo();
};
