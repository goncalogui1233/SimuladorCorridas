#pragma once

#include <vector>
#include "Carro.h"

using namespace std;

class Pista
{
	int maxCar;
	int metros;
	vector <Carro*> carros;

	public:
		Pista(int maxCar, int metros);

		~Pista();

		// Inserir piloto em carro
		bool inserirPilotoCarro();

		void startCorrida();

		void avancarTempo();

		// Se ligar sinal de emergencia, sai da pista, move to garagem

};


