#pragma once
#include "Piloto.h"
#include <random>

using namespace std;

class FastDriver : public Piloto {
	int tempoAteAcelerar;

	int probEmergencia();

public:

	FastDriver(string name);

	~FastDriver();

	FastDriver(const FastDriver& aux);

	string tipoPiloto() const override {
		return "Fast";
	}

	void passaTempo(int posPista, int numCorredores, int tempo) override;

	Piloto* clone() const override;

};

