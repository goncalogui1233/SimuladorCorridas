#pragma once
#include "Carro.h"
#include "Consola.h"
#include <vector>
#include <iostream>

using namespace std;

class Pista
{
	const int representacaoPista = 50; //calcular "andamento" das letras: metrosPista / representação
	int maxCar;
	int metros;
	vector <Carro*> carros;

public:
	Pista(int maxCar, int metros);

	~Pista();

	void representarPista() {
		char a = 96;
		Consola::clrscr();
		cout << "Pista de Corridas" << endl;

		for (unsigned int i = 0; i < carros.size(); i++) {
			
			Consola::gotoxy(0, (2 * i)+2);
			for (int j = 0; j < representacaoPista; j++){ //coloca os traços entre os ID's dos carros
				cout << (char)45;
			}
			cout << "\n";
			Consola::gotoxy(1, (2*i)+3);
			cout << carros[i]->getID();
			cout << "\n";
		}

		for (int i = 0; i < metros; i++) //necessário para fazer a última linha
			cout << (char)45;
		cout << "\n";
		
	}

	int returnMaxCarros() const {
		return maxCar;
	}

	void insereCarroNaPista(Carro* aux);

	void startCorrida();

	void avancarTempo();

	// Se ligar sinal de emergencia, sai da pista, move to garagem

};

