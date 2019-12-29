#pragma once

#include "Piloto.h"

class SurpriseDriver : public Piloto
{

public:
	SurpriseDriver(string nome);

	Piloto* clone() const override;

	void passaTempo(int posPista, int numCorredores, int tempo) override;

	~SurpriseDriver();

	string tipoPiloto() const override {
		return "Surprise";
	}
};

