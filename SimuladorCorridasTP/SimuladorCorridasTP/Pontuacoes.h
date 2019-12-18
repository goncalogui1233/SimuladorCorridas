#pragma once
#include <string>

using namespace std;

class Pontuacoes {

	string nome;
	int pontuacao;

public:

	Pontuacoes(string n);

	string getAsString() const;

	int getPontuacao() const {
		return pontuacao;
	}

	void setPontuacao(int val);

	//bool operator>(const Pontuacoes& p2) const;
};



