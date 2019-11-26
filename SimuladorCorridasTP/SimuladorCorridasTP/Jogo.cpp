#include "Jogo.h"
#include <iostream>
#include <algorithm>

Jogo::Jogo() {
	dgv = new DGV();
	campeonato = nullptr;
}

//Funções de apoio

bool verificaNumeros(string str1, string str2) { //verifica se as posições que deveriam ter numeros realmente os têm
	
	if (str1.find_first_not_of("0123456789") == -1 && str2.find_first_not_of("0123456789") == -1) // 0 se falhar, 1 se estiver tudo bem
		return true;

	return false;
}

string juntaNome(vector<string> vec, int id) { //faz junção dos nomes inseridos
	string nome = "";
	unsigned int i = 0;
	if (id == 1) //criar piloto
		i = 3;
	else if (id == 2) //eliminar piloto
		i = 2;
	else if (id == 4) //juntar nome no inserePilotoEmCarro
		i = 2;
	else if (id == 5) //junta nome no retiraPilotoDeCarro
		i = 1;
	else if (id == 6) //junta nome no escolhePilotosCampeonato
		i = 0;

	for (; i < vec.size(); i++)
		nome += vec[i] + " ";

	transform(nome.begin(), nome.end(), nome.begin(), ::tolower); //coloca o nome em letras minusculas

	return nome;
}

//MODO 1

//Funções realização comandos


void Jogo::carregaPilotos(string fich) {
	dgv->carregaPilotosFich(fich);
}

void Jogo::carregaCarrosFich(string fich) {
	dgv->carregaCarrosFich(fich);
}

string Jogo::criaItensJogo(vector <string> vec) {
	if (vec[1] == "p"){
		string nome = juntaNome(vec, 1);
		transform(vec[2].begin(), vec[2].end(), vec[2].begin(), ::toupper); //letra identificadora do piloto passa a maiuscula
		return dgv->inserePiloto(vec[2], nome);
	}

	else if (vec[1] == "c"){
		if (verificaNumeros(vec[3], vec[4]) == true)
			return dgv->insereCarro(vec);
		else
			return "Argumentos não válidos, tente novamente\n";
	}

	else if (vec[1] == "a") {
		if (verificaNumeros(vec[2], vec[3]) == true) {
			autodromos.push_back(new Autodromo(stoi(vec[2]), stoi(vec[3]), vec[4]));
			return "Autodromo criado\n";
		}
		else
			return "Argumentos não válidos, tente novamente\n";
	}

	else
		return "Nao foi possivel criar nenhum item, verifique a letraTipo e tente novamente\n";
	
}

string Jogo::inserePilotoEmCarro(vector<string>vec) {
	string pil = juntaNome(vec, 4);

	return dgv->inserePilotoEmCarro(vec[1], pil);
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

		return "Autodromo não encontrado, tente novamente";
	}

	return "Opcao nao encontrada, tente novamente";
}

string Jogo::retiraPilotoDeCarro(vector<string>vec) {
	string pil = juntaNome(vec, 5);
	return dgv->retiraPilotoDeCarro(pil);
}

string Jogo::listagem() const {
	string aux = "";
	aux += dgv->listagem();
	
	for (int i = 0; i < autodromos.size(); i++)
		aux += autodromos[i]->getAsString();

	return aux;
}

string Jogo::escolhePilotosCampeonato(vector<string> vec) {
	string nome = juntaNome(vec, 6);

	Piloto* p = dgv->retornaPiloto(nome);
	if (p == nullptr)
		return "Piloto nao existe, tente novamente com outro nome";

	else{
		return campeonato->adicionaParticipantes(p);
	}
}

//Modo2

void Jogo::criaCampeonato() {
	campeonato = new Campeonato();
}

string Jogo::adicionarAutodromoCamp(vector<string>vec) {
	if (vec[1] == "")
		return "Vazio";
	
	for (unsigned int i = 0; i < autodromos.size(); i++) {
		if (autodromos[i]->getNome() == vec[1]) {
			campeonato->adicionarAutodromos(autodromos[i]);
			return "Autodromo adicionado";
		}
	}
	return "Autodromo nao existe";
}

void Jogo::colocaCarrosEmPista() {
	campeonato->insereCarrosEmPista();
}

int Jogo::returnPosX(int i) const {
	return campeonato->returnPosX(i);
}

void Jogo::iniciaCorrida(int rep) {
	campeonato->criarCorrida(rep);
	campeonato->aceleraCarrosInit();
}

string Jogo::listaCarrosCampeonato() {
	return campeonato->listaCarrosCampeonato();
}

size_t Jogo::returnNumCarrosPista() const {
	return campeonato->returnNumCarrosPista();
}

char Jogo::returnIDCarrosPista(int i) const {
	return campeonato->returnIDCarroPista(i);
}


void Jogo::passarTempo(int s) {
	for(int i = 0; i < s; i++)
		campeonato->avancarTempo(s);
}

Jogo::~Jogo() {
	delete dgv;
}
