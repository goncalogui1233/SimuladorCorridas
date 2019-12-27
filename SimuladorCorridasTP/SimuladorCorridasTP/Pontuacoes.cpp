#include "Pontuacoes.h"
#include <sstream>

Pontuacoes::Pontuacoes(string n, int pontos)
	:nome(n), pontuacao(pontos){}

void Pontuacoes::setPontuacao(int val) {
	pontuacao += val;
}

string Pontuacoes::getAsString() const {
	ostringstream os;
	os << "Piloto: " << nome << " Pontuacao: " << pontuacao << "\n";
	return os.str();
}