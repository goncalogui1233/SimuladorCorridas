#include "Carro.h"

int Carro::idcar = 'a';
//using namespace Carro;
using namespace std;

// Construtor 
Carro::Carro(string mar, char idd, double maxe, int maxv, string mod) 
	: marca(mar), modelo(mod), id(idd), maxenergia(maxe), maxvelocidade(maxv){}

// Destrutor
Carro::~Carro(){}

void Carro::setDanificado(bool estragado) {
	this->danificado = estragado;
}

string Carro::getMarca() const {
	return marca;
}

string Carro::getAsString() const {
	ostringstream oss;
	oss << "Marca: " << marca << " Modelo: " << modelo << " Vel. Maxima: " << maxvelocidade << " Max. Energia: " << maxenergia;
	oss << "\nDanificado: " << danificado << "Energia: " << energia << "\n";
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

