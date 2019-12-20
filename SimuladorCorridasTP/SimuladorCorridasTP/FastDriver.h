#pragma once
#include "Piloto.h"

using namespace std;

class FastDriver : public Piloto {
	const int ansioso;

public:

	FastDriver(string name);

	~FastDriver();

	FastDriver(const FastDriver& aux);

	string tipoPiloto() const override {
		return "Fast";
	}

	void passaTempoFast() override;

	Piloto* clone() const override;

};

