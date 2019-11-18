#include "Jogo.h"
#include <iostream>
#include <algorithm>

Jogo::Jogo() {
	dgv = new DGV();
}

void Jogo::carregaPilotos(string fich) {
	dgv->carregaPilotosFich(fich);
}

void Jogo::carregaCarrosFich(string fich) {
	dgv->carregaCarrosFich(fich);
}

string Jogo::criaItensJogo(vector <string> vec) {
	if (vec[1] == "p"){
		transform(vec[2].begin(), vec[2].end(), vec[2].begin(), ::toupper); //letra identificadora do piloto passa a maiuscula
		return dgv->inserePiloto(vec[2], vec[3]);
	}

	else if (vec[1] == "c")
		return dgv->insereCarro(vec);

	else
		return "Nao foi possivel criar nenhum item, verifique a letraTipo e tente novamente\n";
	
}

string Jogo::inserePilotoEmCarro(string car, string pil) {
	return dgv->inserePilotoEmCarro(car, pil);
}

string Jogo::eliminaItemJogo(vector <string> vec) {
	transform(vec[1].begin(), vec[1].end(), vec[1].begin(), ::tolower); //1-onde comecar , 2 - onde terminar, 3-onde guardar nova string, 4-o que fazer
	transform(vec[2].begin(), vec[2].end(), vec[2].begin(), ::tolower);

	if (vec[1] == "p")
		return dgv->eliminaPiloto(vec[2]);

	else if (vec[1] == "c")
		return dgv->eliminaCarro(vec[2]);
	else
		return "Opcao nao encontrada, tente novamente";
}

string Jogo::retiraPilotoDeCarro(string pil) {
	transform(pil.begin(), pil.end(), pil.begin(), ::tolower);
	return dgv->retiraPilotoDeCarro(pil);
}

string Jogo::listagem() const {
	return dgv->listagem();
}

Jogo::~Jogo() {
	delete dgv;
}
