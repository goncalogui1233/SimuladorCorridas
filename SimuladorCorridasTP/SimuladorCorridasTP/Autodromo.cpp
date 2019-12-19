#include "Autodromo.h"
#include <random>

vector<string> Autodromo::nomesAuto;

int geraRandom() {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 23);

	return dist(mt);

}

Autodromo::Autodromo(int maxcarros, int tamPista, string n) {
	string no = n;
	bool existe = true, alterado = false;
	while (existe == true) {
		for (int i = 0; i < nomesAuto.size(); i++)
			if (nomesAuto[i] == no) {
				no += 32;					//adiciona espaco
				no += geraRandom() + 97;	//coloca letra
				alterado = true;
			}
		if (alterado == false)
			existe = false;
	}
	nome = no;
	pista = new Pista(maxcarros, tamPista);
	nomesAuto.push_back(no);
}

void Autodromo::inserePilotoNaPista(Piloto* aux) {
	pista->inserePilotoNaPista(aux);
}

void Autodromo::inserePilotoNaGaragem(Piloto* aux) {
	garagem.push_back(aux);
}

void Autodromo::retiraPilotoDaPista(char id) {
	Piloto* aux  = pista->retiraPiloto(id);
	garagem.push_back(aux);
}

string Autodromo::getNome() const {
	return nome;
}

string Autodromo::getAsString() const {
	ostringstream os;
	os << "Nome: " << nome << " Cap. Pista: " << pista->returnMaxCarros()<< endl;
	return os.str();
}

Autodromo::~Autodromo() {
	delete pista;
}


