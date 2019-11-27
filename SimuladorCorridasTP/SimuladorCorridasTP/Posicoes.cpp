#include "Posicoes.h"

Posicoes::Posicoes(string n, char id, int p)
	:nome(n), posicao(p), idCar(id), posAnterior(0),posPista(0), posx(0){}

void Posicoes::setPosicaoPista(int val) {
	posAnterior = posPista;
	posPista += val;
}

void Posicoes::MexePosEcra() {
	posx++;
}

string Posicoes::getAsString() const {
	ostringstream os;

	os << "Posicao: " << posicao << " Piloto: " << nome << " Carro: " << idCar << endl;

	return os.str();
}