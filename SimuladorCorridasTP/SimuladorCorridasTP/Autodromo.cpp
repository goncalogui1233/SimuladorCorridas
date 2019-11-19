#include "Autodromo.h"
#include <random>

int gerarRandom();

Autodromo::Autodromo(int maxcarros, int tamPista, string n) {
	string no = n;
	bool existe = true, alterado = false;
	while (existe == true) {
		for (int i = 0; i < nomesAuto.size(); i++)
			if (nomesAuto[i] == no) {
				no += 32;					//adiciona espaco
				no += gerarRandom() + 97;	//coloca letra
				alterado = true;
			}
		if (alterado == false)
			existe = false;
	}
	nome = no;
	pista = new Pista(maxcarros, tamPista);
	garage = new Garagem;
	nomesAuto.push_back(no);
}

string Autodromo::getNome() const {
	return nome;
}

Autodromo::~Autodromo() {
	delete pista;
	delete garage;
}



int gerarRandom() {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 23);

	return dist(mt);

}
