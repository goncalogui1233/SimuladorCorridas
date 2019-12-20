#pragma once
#include "DGV.h"
#include "Autodromo.h"
#include "Campeonato.h"

using namespace std;

class Jogo {
	DGV* dgv;
	vector <Autodromo*> autodromos;
	Campeonato* campeonato;

public:
	Jogo();

	//Modo 1
	string carregaPilotos(string fich);

	string carregaCarrosFich(string fich);

	string carregaAutodromosFich(string fich);

	// Cria tipos de Objetos (Carro, Piloto, Autodromo)
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

	int returnPosX(int i) const;

	string adicionarAutodromoCamp(vector<string>vec);

	string carregaBateriaCarro(string id, string mAh);

	string destroiCarro(string id);

	string carregaBateriasCarros();

	void passarTempo(int s);

	void iniciaCorrida(int rep);

	size_t returnNumPilotosPista() const;

	char returnIDCarrosPista(int i) const;

	void apagaCampeonato();

	/*void mostraPista() {
		autodromos[0]->mostraPista();
	}*/

	~Jogo();
};
