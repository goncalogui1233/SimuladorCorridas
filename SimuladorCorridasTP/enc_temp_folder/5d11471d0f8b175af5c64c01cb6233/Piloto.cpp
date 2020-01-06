#include "Piloto.h"
#include "CrazyDriver.h"
#include "FastDriver.h"
#include "SurpriseDriver.h"
#include <iostream>
#include <random>

vector<string> Piloto::usados;

int gerarRandom();


Piloto::Piloto(string name)
	:nome(name), car(nullptr) {}

Piloto::Piloto(const Piloto& aux)
	: nome(aux.nome), car(aux.car) {}


string Piloto::getNome() const {
	return nome;
}

Carro* Piloto::returnCarro() {
	return car;
}

void Piloto::acelera(int val) {
	if (car != nullptr)
		car->acelerar(val);
}

void Piloto::desacelerar() {
	if (car != nullptr)
		car->desacelerar();
}

void Piloto::trava() {
	if (car != nullptr)
		car->travar();
}

void Piloto::danificaCarro() {
	if (car != nullptr)
		car->setDanificado();
}

void Piloto::ativarBotaoEmergencia() {
	if (car != nullptr) {
		car->setEmergencia();
	}
}

bool Piloto::manivela(double mAh) {
	if (car != nullptr && mAh > 0) {
		return car->manivela(mAh);
	}
	return false;
}

void Piloto::drenaEnergia() {
	car->drenaEnergia();
}

void Piloto::carregaMaxBateria() {
	if(car != nullptr){
		double max = car->getMaxCarregamento();
		double at = car->getEnergiaAtual();
		car->manivela(max - at);
	}
}

char Piloto::getIDCar() const {
	if (car != nullptr)
		return car->getID();
	return -1;
}

bool Piloto::temCarroAtribuido() const {
	if (car != nullptr)
		return true;

	return false;
}

void Piloto::atribuiCarro(Carro* c) {
	car = c;
}

void Piloto::retiraCarro() {
	car->setDisponibilidade();
	car = nullptr;
}

string Piloto::getAsString() const {
	ostringstream os;
	if (car != nullptr)
		os << "Nome: " << nome << " ID Carro: " << car->getID() << endl;
	else
		os << "Nome: " << nome << " ID Carro: " << endl;

	return os.str();
}

string Piloto::getInfoCarro() const {
	return car->getAsString();
}

Piloto* Piloto::fabrica(string tipo, string nome) {
	string name = nome;
	bool existe = true, alterado = false;
	while (existe == true) {
		for (unsigned int i = 0; i < usados.size(); i++)
			if (usados[i] == name) {
				name += 32;					//adiciona espaco
				name += gerarRandom() + 97;	//coloca letra
				alterado = true;
			}
		if (alterado == false)
			existe = false;
	}

	if (tipo == "CRAZY") {
		usados.push_back(name);
		return new CrazyDriver(name);
	}
	else if (tipo == "RAPIDO") {
		usados.push_back(name);
		return new FastDriver(name);
	}
	else if (tipo == "SURPRESA") {
		//return new SurpriseDriver();
		return nullptr;
	}
	else
		return nullptr;
}


int gerarRandom() {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 23);

	return dist(mt);
}

Piloto::~Piloto() {
	car = nullptr;
}
