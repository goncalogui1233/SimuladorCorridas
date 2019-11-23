#pragma once
#include "Carro.h"
#include "Piloto.h"
#include "CrazyDriver.h"
#include "FastDriver.h"
#include "SurpriseDriver.h"
#include <vector>
#include <fstream>

using namespace std;

class DGV {
	vector <Carro*> carros;
	vector <Piloto*> pilotos;

public:

	DGV(){}

	DGV(const DGV& aux);

	int getCarrosTam() const;

	int getPilotosTam() const;

	void carregaPilotosFich(string fich);

	void carregaCarrosFich(string fich);

	string insereCarro(vector <string> vec);

	string inserePiloto(string tipo, string nome);

	string eliminaCarro(string ident);

	string eliminaPiloto(string ident);

	string inserePilotoEmCarro(string car, string pil);

	string retiraPilotoDeCarro(string pil);

	Piloto* retornaPiloto(string nome);

	string listagem() const;

	~DGV();

};