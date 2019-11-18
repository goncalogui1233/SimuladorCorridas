#pragma once
#include "DGV.h"
#include "Autodromo.h"

using namespace std;

class Jogo {
	DGV* dgv;
	//vector <Autodromo> autodromos;

public:
	Jogo();

	void carregaPilotos(string fich);

	void carregaCarrosFich(string fich);

	string criaItensJogo(vector <string> vec);

	string eliminaItemJogo(vector <string> vec);

	string inserePilotoEmCarro(string car, string pil);

	string retiraPilotoDeCarro(string pil);

	string listagem() const;

	~Jogo();
};
