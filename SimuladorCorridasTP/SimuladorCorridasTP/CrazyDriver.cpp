#include "CrazyDriver.h"
#include <random>

using namespace std;

CrazyDriver::CrazyDriver(string name)
	:Piloto(name){}

CrazyDriver::~CrazyDriver(){}

void CrazyDriver::setDesatento() {
	default_random_engine val;
	uniform_int_distribution<int> aleatorio(1, 5);
	desatento = aleatorio(val);
	//desatento = rand() % 5 + 1;
}

//bool CrazyDriver::probAcidente() {
//	return 0.05 > ((float)rand() / RAND_MAX);
//}

