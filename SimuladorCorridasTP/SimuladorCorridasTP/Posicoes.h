#pragma once
#include <string>
#include <sstream>

using namespace std;

class Posicoes {
	string nome;
	char idCar;
	int posicao; //lugar na classificacao
	int posAnterior;// metros anteriores de posPista
	int posPista; //metros na pista
	int posx;

public:
	Posicoes(string n, char id, int p);

	int returnPosX() const {
		return posx;
	}

	int returnPosAnterior() const {
		return posAnterior;
	}

	int returnPosAtual() const {
		return posPista;
	}

	void MexePosEcra();

	void setPosicaoPista(int val);

	char returnCharCarro() const {
		return idCar;
	}

	string getAsString() const;
};

