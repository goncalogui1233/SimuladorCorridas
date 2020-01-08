#pragma once
#include <string>

using namespace std;

class Pontuacoes {

	string nome;
	int pontuacao;

public:
	Pontuacoes(string nome, int pontos);

	string getAsString() const;

	string getNome() const {
		return nome;
	}

	int getPontuacao() const {
		return pontuacao;
	}

	void setPontuacao(int val);

	//bool operator>(const Pontuacoes& p2) const;
};



