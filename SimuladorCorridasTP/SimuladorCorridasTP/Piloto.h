#pragma once
#include "Carro.h"
#include <string>
#include <vector>

using namespace std;

class Piloto {
	//nome usados
	static vector<string> usados;
	const string nome; //unico, a classe altera caso ja exista
	Carro* car;

public:

	Piloto(string name);

	Piloto(const Piloto& aux);

	virtual Piloto* clone() const = 0;

	void desacelerar();

	void acelera(int val = 1);

	void trava();

	void danificaCarro();

	Carro* returnCarro();

	string getNome() const;

	char getIDCar() const;

	bool getCarroParado() const {
		return car->returnParado();
	}

	int getVelocidadeAtual() const {
		return car->getVelocidadeAtual();
	}

	bool manivela(int mAh);

	void carregaMaxBateria();

	bool temCarroAtribuido() const;

	void atribuiCarro(Carro* c);

	void retiraCarro();

	void drenaEnergia();

	string getAsString() const;

	string getInfoCarro() const;

	virtual void passaTempoCrazy(int posPista, int numCorredores) {};

	virtual void passaTempoFast() {};

	virtual string tipoPiloto() const = 0;

	static Piloto* fabrica(string tipo, string nome);

	// Pure virtual destructor
	virtual ~Piloto() = 0;
};