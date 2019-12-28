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

bool Campeonato::avancarTempo() {
	bool term = c->passaTempo();

	if (term == true) { //caso a corrida tenha terminado
		int conta = 0;
		int ptMax = 10;
		while(conta != 2){
			if(verificarSeExiste(c->getNomePodio(conta), (ptMax / conta)) == false)
				tabelaGeral.push_back(new Pontuacoes(c->getNomePodio(conta), 10));
			conta++;
		}
		autodromoAtual++; //passa para o novo autodromo
		c = nullptr; //apaga a corrida
		logRegisto += "Terminou esta corrida\n\n\n";
		return true;
	}
	logRegisto = c->getInfoToLog();

	return false;
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

string Campeonato::criarCorrida(int rep) {
	if (c == nullptr)
		if(autodromoAtual <= autodromos.size())
			c = new Corrida(autodromos[autodromoAtual], rep);
		else { //caso não haja mais autodromos, dispara a classificação do campeonato
			ostringstream os;
			os << "O campeonato terminou, as classificacoes sao as seguintes: \n";

			for (int i = 0; i < tabelaGeral.size(); i++)
				os << tabelaGeral[i]->getAsString();

			return os.str();
		}

	return "";
}

string Campeonato::listaCarrosCampeonato() const {
	ostringstream os;
	for (int i = 0; i < participantes.size(); i++)
		os << "Piloto: " << participantes[i]->getNome() << "Carro: " << participantes[i]->getInfoCarro();
	
	return os.str();
}

//funções auxiliares

//verifica se um determinado piloto já existe e, caso exista, atualiza os seus pontos.
bool Campeonato::verificarSeExiste(string nome, int pontos) {
	for(int i = 0; i < tabelaGeral.size(); i++)
		if (tabelaGeral[i]->getNome() == nome) {
			tabelaGeral[i]->setPontuacao(pontos);
			return true;
		}

	return false;
}