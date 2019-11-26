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

void Campeonato::adicionarAutodromos(Autodromo *aux) {
	autodromos.push_back(aux);
}

void Campeonato::avancarTempo(int s) {
	c->atualizaPosCorrida(participantes);
	c->verificaSeMudouPos();
}

void Campeonato::insereCarrosEmPista() {
	if (autodromos[0]->returnMaxCarros() >= participantes.size()) // se a capacidade da pista for maior ou igual aos participantes
		for (unsigned int i = 0; i < participantes.size(); i++)
			autodromos[0]->insereCarroNaPista(participantes[i]->returnCarro());
	else{												//caso a pista não consiga ter os carros todos, coloca os outros na garagem
		unsigned int j = 0;
		for (; j < autodromos[0]->returnMaxCarros(); j++)
			autodromos[0]->insereCarroNaPista(participantes[j]->returnCarro());

		for (; j < participantes.size(); j++)
			autodromos[0]->insereCarroNaGaragem(participantes[j]->returnCarro());
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