#pragma once
#include "Carro.h"
#include <string>
#include <vector>

using namespace std;

class Piloto {
	//nome usados
	static vector<string> usados;
	const string nome; //unico, a classe altera caso ja exista
	Carro *car;

public:

	Piloto(string name);

	Piloto(const Piloto& aux);

	virtual Piloto* clone() const = 0;

	void acelera(int val = 1);

	void trava();

	Carro* returnCarro();

	string getNome() const;

	char getIDCar() const;

	bool returnCarroParado() const {
		return car->returnParado();
	}

	int returnVelocidadeAtual() const {
		return car->getVelocidadeAtual();
	}

	bool temCarroAtribuido() const;

	void atribuiCarro(Carro *c);

	void retiraCarro();

	string getAsString() const;

	string getInfoCarro() const;

	static Piloto* fabrica(string tipo, string nome);

	// Pure virtual destructor
	virtual ~Piloto() = 0;
};