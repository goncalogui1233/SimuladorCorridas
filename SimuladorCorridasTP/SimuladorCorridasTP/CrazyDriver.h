#pragma once
#include "Piloto.h"
#include <string>

using namespace std;

class CrazyDriver : public Piloto{
	int desatento; //1 a 5 seg - aleatorio

public:

	CrazyDriver(string name);

	void setDesatento();

	int getDesatento() const;
};

