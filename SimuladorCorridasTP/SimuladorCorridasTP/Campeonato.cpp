#include "Campeonato.h"

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

string Campeonato::carregaCarro(char id, int mAh) {
	vector<Piloto*>::iterator it;
	for (it = participantes.begin(); it != participantes.end(); it++)
		if((*it)->getIDCar() == id){
			if ((*it)->manivela(mAh) == true)
				return "Bateria do carro carregada";
			else
				return "Não foi possivel carregar a bateria";
		}

}

string Campeonato::carregaTodosCarros() {
	vector<Piloto*>::iterator it;
	for (it = participantes.begin(); it != participantes.end(); it++)
		(*it)->carregaMaxBateria();

	return "Todos os carros foram carregados";
}

void Campeonato::retiraPilotoCorrida(char id) {
	autodromos[autodromoAtual]->retiraPilotoDaPista(id);
}

void Campeonato::inserePilotosEmPista() {
	if (autodromos[autodromoAtual]->returnMaxCarros() >= participantes.size()) // se a capacidade da pista for maior ou igual aos participantes
		for (unsigned int i = 0; i < participantes.size(); i++)
			autodromos[autodromoAtual]->inserePilotoNaPista(participantes[i]);
	else{												//caso a pista não consiga ter os carros todos, coloca os outros na garagem
		unsigned int j = 0;
		for (; j < autodromos[autodromoAtual]->returnMaxCarros(); j++)
			autodromos[autodromoAtual]->inserePilotoNaPista(participantes[j]);

		for (; j < participantes.size(); j++)
			autodromos[autodromoAtual]->inserePilotoNaGaragem(participantes[j]);
	}
}

void Campeonato::criarCorrida(int rep) {
	c = new Corrida(autodromos[0], rep);
}

void Campeonato::aceleraCarrosInit() {
	c->aceleraCarrosInit(participantes);
}

string Campeonato::listaCarrosCampeonato() const {
	ostringstream os;
	for (int i = 0; i < participantes.size(); i++)
		os << "Piloto: " << participantes[i]->getNome() << "Carro: " << participantes[i]->getInfoCarro();
	
	return os.str();
}