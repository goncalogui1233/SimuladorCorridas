#include "FastDriver.h"

FastDriver::FastDriver(string name)
	:Piloto(name), ansioso(1) {}

FastDriver::FastDriver(const FastDriver &aux)
	:Piloto(aux), ansioso(aux.ansioso){}


Piloto* FastDriver::clone() const {
	return new FastDriver(*this);
}

FastDriver::~FastDriver() {}