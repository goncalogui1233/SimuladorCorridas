#include "Carro.h"

int Carro::idcar = 'a';

Carro::Carro(string mar, double maxe, int maxv, string mod)
	:marca(mar), modelo(mod), id(idcar++), maxenergia(maxe), maxvelocidade(maxv){}

Carro::Carro(const Carro& aux) 
:id(aux.id), maxvelocidade(aux.maxvelocidade), marca(aux.marca), modelo(aux.modelo), maxenergia(aux.maxenergia){}

string Carro::getAsString() const {
	ostringstream oss;
	oss << "Marca: " << marca << " Modelo: " << modelo << " Vel. Maxima: " << maxvelocidade << " Max. Energia: " << maxenergia;
	oss << "\nDanificado: " << danificado << "Energia: " << energia << "\n";
	return oss.str();
}

bool Carro::manivela(int val) {
	if (parado && (energia + val) >= maxenergia) {
		energia += val;
		return true;
	}
	else
		return false;
}

void Carro::setEmergencia() {
	//!emergencia;
	if (emergencia == false)
		emergencia = true;
	else
		emergencia = false;
}

void Carro::setEstado() {
	//!parado;
	if (parado == false)
		parado = true;
	else
		parado = false;
}

void Carro::acelerador(int vel) {
	if (velocidadeAtual < maxvelocidade) {
		this->velocidadeAtual += vel;
	}
}

void Carro::travao() {
	acelerador(-1);
}

Carro::~Carro(){}

