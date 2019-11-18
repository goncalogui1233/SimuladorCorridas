#pragma once
#include "Piloto.h"
#include <string>

class CrazyDriver : public Piloto{
	int desatento; //1 a 5 seg - aleatorio

public:

	CrazyDriver(string name);

	~CrazyDriver();

	void setDesatento();

	int getDesatento() const {
		return desatento;
	}

	/*	Probabilidade de ter um acidente
	*	
	*	Condutor ter 5% de ter um acidente
	*	Se probabilidade for 5% -> True
	*	Senão -> False
	*/
	//bool probAcidente();
};

