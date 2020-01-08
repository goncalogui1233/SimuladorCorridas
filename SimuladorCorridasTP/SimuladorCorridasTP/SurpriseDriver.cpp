#include "SurpriseDriver.h"

SurpriseDriver::SurpriseDriver(string nome) 
	:Piloto(nome){}

Piloto* SurpriseDriver::clone() const {
	return new SurpriseDriver(*this);
}

SurpriseDriver::~SurpriseDriver(){}


void SurpriseDriver::passaTempo(int posPista, int numCorredores, int tempo) {

}
