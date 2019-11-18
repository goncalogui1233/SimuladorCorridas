#include "Piloto.h"
#include "CrazyDriver.h"
#include "FastDriver.h"
#include "SurpriseDriver.h"
#include <iostream>
#include <random>

vector<string> Piloto::usados;

int gerarRandom();


Piloto::Piloto(string name)
	:nome(name){
		car = nullptr;
	}

string Piloto::getNome() const {
	return nome;
}

void Piloto::acelera() {
	if (car != nullptr)
		car->acelerar();
}

void Piloto::trava() {
	if (car != nullptr)
		car->travar();
}

char Piloto::getIDCar() const {
	if(car != nullptr)
		return car->getID();
}

bool Piloto::temCarroAtribuido() const{
	if (car != nullptr)
		return true;

	return false;
}

void Piloto::atribuiCarro(Carro* c) {
	car = c;
}

void Piloto::retiraCarro() {
	car = nullptr;
}

Piloto* Piloto::fabrica(string tipo, string nome) {
	string n = nome;
	bool existe = true, alterado = false;
	while (existe == true) {
		for (int i = 0; i < usados.size(); i++)
			if (usados[i] == n) {
				n += 32;					//adiciona espaco
				n += gerarRandom() + 97;	//coloca letra
				alterado = true;
			}
		if(alterado == false)
			existe = false;
	}

	if (tipo == "C") {
		usados.push_back(n);
		return new CrazyDriver(n);
	}
	else if (tipo == "F") {
		usados.push_back(n);
		return new FastDriver(nome);
	}
	else if (tipo == "S") {
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


