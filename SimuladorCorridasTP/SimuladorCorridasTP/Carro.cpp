#include "Carro.h"

int Carro::idcar = 'a';

Carro::Carro(double initCap, double maxe, int maxv, string mar, string mod)
	:marca(mar), modelo(mod), id(setIDs(idcar)), maxenergia(maxe), maxvelocidade(maxv), energia(initCap) {}

// Destrutor
Carro::~Carro(){}

char Carro::setIDs(int idcar) {
	if (idcar > 'z') {
		return '?';
	}
	return Carro::idcar++;
}

void Carro::setDanificado() {
	if (danificado == true)
		danificado = false;
	else {
		danificado = true;
		velocidadeAtual = 0;
	}

}
Carro::Carro(const Carro& aux) 
:id(aux.id), maxvelocidade(aux.maxvelocidade), marca(aux.marca), modelo(aux.modelo), maxenergia(aux.maxenergia), energia(aux.energia) {}

string Carro::getAsString() const {
	ostringstream oss;
	oss << "Marca: " << marca <<" | ID: "<< id <<" | Modelo: " << modelo << " | Vel. Maxima: " << maxvelocidade << " | Max. Energia: " << maxenergia << endl;
	oss << "Danificado: " << danificado << " | Energia: " << energia << endl << endl;
	return oss.str();
}

void Carro::setDisponibilidade() {
	if (disponivel == true)
		disponivel = false;
	else
		disponivel = true;
}

bool Carro::manivela(double valCarregamento) {
	if (parado && (energia + valCarregamento) < maxenergia) {
		energia += valCarregamento;
		return true;
	}
	return false;
}

void Carro::drenaEnergia() {
	energia -= 0.1;
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

void Carro::desacelerar() {
	this->velocidadeAtual -= 1;
}

