#pragma once
#include "Carro.h"
#include "Piloto.h"
#include "CrazyDriver.h"
#include "FastDriver.h"
#include <vector>
#include <fstream>

class DGV {
	vector <Carro*> carros;
	vector <Piloto*> pilotos;

public:

	void carregaPilotosFich(string fich);

	void carregaCarrosFich(string fich);

	string insereCarro(vector <string> vec);

	string inserePiloto(string tipo, string nome);

	string eliminaCarro(string ident);

	string eliminaPiloto(string ident);

	string inserePilotoEmCarro(string car, string pil);

	string retiraPilotoDeCarro(string pil);

	string listagem() const;

	string listaCarros() const;

	~DGV();

};