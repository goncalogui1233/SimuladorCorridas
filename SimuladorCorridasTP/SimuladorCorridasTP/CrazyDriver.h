#pragma once
#include "Piloto.h"
#include <string>

class CrazyDriver : public Piloto {
	int desatento; //1 a 5 seg - aleatorio
	int ultimaPos; //ultima posicao na pista

public:

	CrazyDriver(string name);

	~CrazyDriver();

	Piloto* clone() const override;

	void setDesatento();

	string tipoPiloto() const override {
		return "Fast";
	}

	int getDesatento() const {
		return desatento;
	}

	void passaTempoCrazy(int posPista, int numCorredores) override;

	/*	Probabilidade de ter um acidente
	*
	*	Condutor ter 5% de ter um acidente
	*	Se probabilidade for 5% -> True
	*	Senão -> False
	*/
	bool probAcidente();

	CrazyDriver(const CrazyDriver& aux);
};

