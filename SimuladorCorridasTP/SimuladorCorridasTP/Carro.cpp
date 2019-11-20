#include "Carro.h"

int Carro::idcar = 'a';

Carro::Carro(double initCap, double maxe, int maxv, string mar, string mod)
	:marca(mar), modelo(mod), id(idcar++), maxenergia(maxe), maxvelocidade(maxv), initenergia(initCap) {}

// Destrutor
Carro::~Carro(){}

void Carro::setDanificado(bool estragado) {
	this->danificado = estragado;
}
Carro::Carro(const Carro& aux) 
:id(aux.id), maxvelocidade(aux.maxvelocidade), marca(aux.marca), modelo(aux.modelo), maxenergia(aux.maxenergia), initenergia(aux.initenergia) {}

string Carro::getAsString() const {
	ostringstream oss;
	oss << "Marca: " << marca << " | Modelo: " << modelo << " | Vel. Maxima: " << maxvelocidade << " | Cap. Inicial "<< initenergia << " | Max. Energia: " << maxenergia << endl;
	oss << "Danificado: " << danificado << " | Energia: " << energia << endl << endl;
	return oss.str();
}

bool Carro::manivela(int quantEnergia) {
	if (parado && (energia + quantEnergia) < maxenergia) {
		energia += quantEnergia;
		return true;
	}
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

void Carro::acelerar(int val) {
	if (velocidadeAtual < maxvelocidade) {
		this->velocidadeAtual += val;
	}
}

void Carro::travar() {
	acelerar(-1);
}

