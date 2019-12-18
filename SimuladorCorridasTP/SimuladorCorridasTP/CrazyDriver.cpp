#include "CrazyDriver.h"
#include <random>

using namespace std;

CrazyDriver::CrazyDriver(string name)
	:Piloto(name), desatento(1){}

CrazyDriver::CrazyDriver(const CrazyDriver& aux) 
:Piloto(aux), desatento(aux.desatento){}

Piloto * CrazyDriver::clone() const {
	return new CrazyDriver(*this);
}

void CrazyDriver::setDesatento() {
	default_random_engine val;
	uniform_int_distribution<int> aleatorio(1, 5);
	desatento = aleatorio(val);
	//desatento = rand() % 5 + 1;
}

//bool CrazyDriver::probAcidente() {
//	return 0.05 > ((float)rand() / RAND_MAX);
//}

CrazyDriver::~CrazyDriver() {}