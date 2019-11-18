#pragma once
#include "Carro.h"
#include <string>
#include <vector>

using namespace std;

class Piloto {
	static vector<string> usados;
	const string nome; //unico, a classe altera caso ja exista
	Carro *car;

public:

	Piloto(string name);

	void acelera();

	void trava();

	string getNome() const;

	char getIDCar() const;

	bool temCarroAtribuido() const;

	void atribuiCarro(Carro *c);

	void retiraCarro();

	static Piloto* fabrica(string tipo, string nome);

};