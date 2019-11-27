#include "Pontuacoes.h"
#include <sstream>

Pontuacoes::Pontuacoes(string n) 
	:nome(n), pontuacao(0){}

void Pontuacoes::setPontuacao(int val) {
	pontuacao += val;
}

string Pontuacoes::getAsString() const {
	ostringstream os;
	os << "Piloto: " << nome << " Pontuacao: " << pontuacao << "\n";
	return os.str();
}