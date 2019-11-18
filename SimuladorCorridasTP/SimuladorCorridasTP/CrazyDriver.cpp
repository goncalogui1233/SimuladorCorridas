#include "CrazyDriver.h"
#include <random>

CrazyDriver::CrazyDriver(string name)
	:Piloto(name), desatento(1){}

void CrazyDriver::setDesatento() {
	default_random_engine val;
	uniform_int_distribution<int> aleatorio(1, 5);
	desatento = aleatorio(val);
	//desatento = rand() % 5 + 1;
}

int CrazyDriver::getDesatento() const {
	return desatento;
}
