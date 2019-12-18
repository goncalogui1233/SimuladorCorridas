#include "Campeonato.h"

int Campeonato::autodromoAtual = 0;

string Campeonato::adicionaParticipantes(Piloto* aux) {
	vector<Piloto*>::iterator it;
	for (it = participantes.begin(); it != participantes.end(); it++)
		if ((*it)->getNome() == aux->getNome())
			return "Piloto já foi inserido na corrida\n";

	participantes.push_back(aux);
	return "Piloto inserido na corrida\n";
}

bool Campeonato::returnSeExisteCorrida() const {
	if (c == nullptr)
		return false;

	return true;
}

void Campeonato::adicionarAutodromos(Autodromo *autodromo) {
	autodromos.push_back(autodromo);
}

void Campeonato::avancarTempo() {
	c->atualizaPosCorrida(participantes);
	c->verificaSeMudouPos();
}

void Campeonato::insereCarrosEmPista() {
	if (autodromos[autodromoAtual]->returnMaxCarros() >= participantes.size()) // se a capacidade da pista for maior ou igual aos participantes
		for (unsigned int i = 0; i < participantes.size(); i++)
			autodromos[autodromoAtual]->insereCarroNaPista(participantes[i]->returnCarro());
	else{												//caso a pista não consiga ter os carros todos, coloca os outros na garagem
		unsigned int j = 0;
		for (; j < autodromos[autodromoAtual]->returnMaxCarros(); j++)
			autodromos[autodromoAtual]->insereCarroNaPista(participantes[j]->returnCarro());

		for (; j < participantes.size(); j++)
			autodromos[autodromoAtual]->insereCarroNaGaragem(participantes[j]->returnCarro());
	}
}

void Campeonato::criarCorrida(int rep) {
	c = new Corrida(autodromos[0], participantes, rep);
}

void Campeonato::aceleraCarrosInit() {
	c->aceleraCarrosInit(participantes);
}

string Campeonato::listaCarrosCampeonato() const {
	ostringstream os;
	for (int i = 0; i < participantes.size(); i++)
		os << participantes[i]->getInfoCarro();
	
	return os.str();
}