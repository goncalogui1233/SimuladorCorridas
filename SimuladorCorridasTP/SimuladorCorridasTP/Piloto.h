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

	double getCapacidadeMax() const {
		if (car != nullptr)
			return car->getMaxCarregamento();
		return -1;
	}

	double getEnergiaAtual() const {
		if (car != nullptr)
			return car->getEnergiaAtual();
		return -1;
	}

	bool getEmergencia() const {
		if (car != nullptr) {
			return car->getEmergencia();
		}
		return true;
	}

	bool getDanificado() const {
		if (car != nullptr)
			return car->getDanificado();
		return true;
	}

	bool manivela(double mAh);

	void carregaMaxBateria();

	bool temCarroAtribuido() const;

	void atribuiCarro(Carro* c);

	void retiraCarro();

	void drenaEnergia();

	void ativarBotaoEmergencia();

	string getAsString() const;

	string getInfoCarro() const;

	/*
	*Recebe posição piloto na pista
	*Recebe numero de corredores
	*Recebe o tempo de corrida
	*/

	virtual void passaTempo(int posPista, int numCorredores, int tempo) = 0; //recebe posicao

	virtual string tipoPiloto() const = 0;

	static Piloto* fabrica(string tipo, string nome);

	// Pure virtual destructor
	virtual ~Piloto() = 0;
};