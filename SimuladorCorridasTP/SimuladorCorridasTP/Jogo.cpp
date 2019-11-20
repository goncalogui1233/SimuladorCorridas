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
	if (id == 1) //criar piloto
		i = 3;
	else if (id == 2) //eliminar piloto
		i = 2;
	else if (id == 3)
		i = 4;

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

	else if (vec[1] == "a") {
		string nome = juntaNome(vec, 3);
		autodromos.push_back(new Autodromo(stoi(vec[2]), stoi(vec[3]), nome));
		return "Pista criada";
	}

	else
		return "Nao foi possivel criar nenhum item, verifique a letraTipo e tente novamente\n";
	
}

// É a dgv que insere piloto no carro???
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
		transform(vec[2].begin(), vec[2].end(), vec[2].begin(), ::tolower);
		return dgv->eliminaCarro(vec[2]);
		
	}

	else if (vec[1] == "c") {
		vector<Autodromo*>::iterator it;
		string nome = juntaNome(vec, 3);

		for (it = autodromos.begin(); it != autodromos.end(); )
			if ((*it)->getNome() == nome) {
				delete* it;
				it = autodromos.erase(it);
				return "Autodromo eliminado com sucesso";
			}
			else
				it++;
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
