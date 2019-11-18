#include "Jogo.h"
#include <iostream>
#include <algorithm>

Jogo::Jogo() {
	dgv = new DGV();
}

//#	    #  ####  ###   ####		###
//# # # #  #  #  #  #  #  #	   # ##
//#  #  #  #  #  #  #  #  #	     ##
//#     #  ####  ###   ####		####

void Jogo::carregaPilotos(string fich) {
	dgv->carregaPilotosFich(fich);
}

void Jogo::carregaCarrosFich(string fich) {
	dgv->carregaCarrosFich(fich);
}

string juntaNome(vector<string> vec, int id) { //faz junção dos nomes inseridos
	string nome = "";
	int i=0;
	if (id == 1)
		i = 3;
	else if (id == 2)
		i = 2;
	for (;i < vec.size(); i++)
		nome += vec[i] + " ";

	transform(nome.begin(), nome.end(), nome.begin(), ::tolower);

	return nome;
}

string Jogo::criaItensJogo(vector <string> vec) {
	if (vec[1] == "p"){
		string nome = juntaNome(vec, 1);
		transform(vec[2].begin(), vec[2].end(), vec[2].begin(), ::toupper); //letra identificadora do piloto passa a maiuscula
		return dgv->inserePiloto(vec[2], nome);
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

	if (vec[1] == "p") {
		string nome = juntaNome(vec, 2);
		return dgv->eliminaPiloto(nome);
	}

	else if (vec[1] == "c") {
		return dgv->eliminaCarro(vec[2]);
		transform(vec[2].begin(), vec[2].end(), vec[2].begin(), ::tolower);
	}

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

void Jogo::passarTempo(int s) {

}

Jogo::~Jogo() {
	delete dgv;
}
