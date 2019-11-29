#include "Jogo.h"
#include <iostream>
#include <algorithm>

Jogo::Jogo() {
	dgv = new DGV();
	campeonato = nullptr;
}

//Funções de apoio

bool verificaNumeros(string str) { //verifica se as posições que deveriam ter numeros realmente os têm
	
	if (str.find_first_not_of("0123456789") == -1) // 0 se falhar, 1 se estiver tudo bem
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


string Jogo::carregaPilotos(string fich) {
	return dgv->carregaPilotosFich(fich);
}

string Jogo::carregaCarrosFich(string fich) {
	return dgv->carregaCarrosFich(fich);
}

string Jogo::carregaAutodromosFich(string fich) {
	ifstream f;
	int maxcarros, tampista;
	string nome;
	f.open(fich);
	if (!f)
		return "Erro na abertura do ficheiro\n";
	
	while (!f.eof()) {
		try {


			f >> maxcarros;
			f >> tampista;
			f >> nome;

			if (maxcarros <= 0 || tampista <= 0 || nome.empty()) {
				throw exception("Erro a ler o ficheiro, Confirme os dados\n");
			}

			autodromos.push_back(new Autodromo(maxcarros, tampista, nome));
		}
		catch (exception & e) {
			f.close();
			return e.what();
		}
	}

	f.close();
	return "Ficheiro Lido com Sucesso\n";
}

string Jogo::criaItensJogo(vector <string> vec) {
	if (vec[1] == "p"){
		string nome = juntaNome(vec, 1);
		transform(vec[2].begin(), vec[2].end(), vec[2].begin(), ::toupper); //letra identificadora do piloto passa a maiuscula
		return dgv->inserePiloto(vec[2], nome);
	}

	else if (vec[1] == "c") {
		if (vec.size() >= 5 && vec.size() < 8) {
			if (verificaNumeros(vec[2]) && verificaNumeros(vec[3]) && verificaNumeros(vec[4]))
				return dgv->insereCarro(vec);
		}
		else
			return "Argumentos nao validos, tente novamente\n";
	}

	else if (vec[1] == "a") {
		if (vec.size() >= 3 && vec.size() < 6) {
			if (verificaNumeros(vec[2]) && verificaNumeros(vec[3])) {
				autodromos.push_back(new Autodromo(stoi(vec[2]), stoi(vec[3]), vec[4]));
				return "Autodromo criado\n";
			}
		}
		return "Argumentos nao validos, tente novamente\n";
	}

	else
		return "Nao foi possivel criar nenhum item, verifique a letraTipo e tente novamente\n";
	
}

string Jogo::inserePilotoEmCarro(vector<string>vec) {
	if (vec.size() >= 3) {
		string pil = juntaNome(vec, 4);

		return dgv->inserePilotoEmCarro(vec[1], pil);
	}
	return "Argumentos nao validos, tente novamente\n";
}

string Jogo::eliminaItemJogo(vector <string> vec) {

	// 3 parametros no minimo - command letraTipo (identificador) + que 1 no piloto 
	if (vec.size() < 3)
		return "Argumentos nao validos, tente novamente\n";

	transform(vec[1].begin(), vec[1].end(), vec[1].begin(), ::tolower); //1-onde comecar , 2 - onde terminar, 3-onde guardar nova string, 4-o que fazer

	if (vec.size() >= 3 && vec[1] == "p") {
		string nome = juntaNome(vec, 2);
		return dgv->eliminaPiloto(nome);
	}

	else if (vec.size() == 3 && vec[1] == "c") {
		if (vec.at(2).size() == 1) {
			transform(vec[2].begin(), vec[2].end(), vec[2].begin(), ::tolower);
			return dgv->eliminaCarro(vec[2]);
		}
		return "Argumentos nao validos, verifique o nome do carro\n";
	}

	else if (vec.size() == 3 && vec[1] == "a") {
		vector<Autodromo*>::iterator it;

		for (it = autodromos.begin(); it != autodromos.end(); )
			if ((*it)->getNome() == vec[2]) {
				delete* it;
				it = autodromos.erase(it);
				return "Autodromo eliminado com sucesso\n";
			}
			else
				it++;

		return "Autodromo nao encontrado, tente novamente\n";
	}

	return "Opcao nao encontrada, tente novamente\n";
}

string Jogo::retiraPilotoDeCarro(vector<string>vec) {
	if (vec.size() == 2 && vec[1].size() == 1)
		return dgv->retiraPilotoDeCarro(vec.at(0).at(1));
	return "Argumentos nao validos, tente novamente\n";
}

string Jogo::listagem() const {
	string aux = "";
	aux += dgv->listagem();
	
	if (autodromos.size() != 0) {
		aux += "Autodromos: \n";
		for (int i = 0; i < autodromos.size(); i++)
			aux += autodromos[i]->getAsString();
	}
	else
		aux += "Nao existem autodromos\n";
	

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
	if (vec.size() == 1)
		return "Vazio";
	
	if (campeonato->returnSeExisteCorrida() == false) {
		for (unsigned int i = 0; i < autodromos.size(); i++) {
			if (autodromos[i]->getNome() == vec[1]) {
				campeonato->adicionarAutodromos(autodromos[i]);
				return "Autodromos adicionados\n";
			}
		}
		return "Autodromo nao existe\n";
	}
	else
		return "Ja existe uma corrida a decorrer, nao e possivel adicionar autodromos\n";
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
	for(int i = 0; i < s; i++){
		campeonato->avancarTempo();
	}
}

Jogo::~Jogo() {
	delete dgv;
}
