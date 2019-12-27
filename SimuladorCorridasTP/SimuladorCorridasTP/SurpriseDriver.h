#pragma once

#include "Piloto.h"

class SurpriseDriver : public Piloto
{

public:
	SurpriseDriver(string nome);

	Piloto* clone() const override;

	void passaTempo();

	~SurpriseDriver();
};

