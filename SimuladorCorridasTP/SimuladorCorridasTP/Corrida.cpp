#include "Corrida.h"


//função usada para ordenar vetor classificações
bool compare(const Posicoes* p1, const Posicoes* p2) {
	return p1->returnPosAtual() > p2->returnPosAtual();
} //sort(vector.begin(), vector.end(), compare) -> necessario #include <algorithm>



//funções principais

Corrida::Corrida(Autodromo* aux, int rep)
	:repPista(rep){
	contaPosicao = 1;
	tempoCorrida = 0;
	aut = aux;
	for (int i = 0; i < aut->returnNumPilotosPista(); i++) { //percorre vetor dos pilotos na pista para criar a tabela de classificações
		classificacao.push_back(new Posicoes(aut->returnNomePiloto(i), aut->returnIDCarro(i), contaPosicao++));
	}
}

/*
void Corrida::atualizaPosCorrida(const vector<Piloto*> aux) {
	int c = 0;
	for (int i = 0; i < aut->returnNumCarrosPista(); i++){ //vetor dos carros que estão na pista
		for (int j = 0; j < aux.size(); j++){		//percorre o vetor dos participantes, passado por argumento
			if (aut->returnIdCarroPista(i) == aux[j]->getIDCar()){
				for (int k = 0; k < classificacao.size(); k++){ //percorre o vetor das classificacoes
					if (classificacao[k]->returnCharCarro() == aut->returnIdCarroPista(i)){
						classificacao[k]->setPosicaoPista(aux[j]->getVelocidadeAtual());
						break;
					}
				}
			}
		}
	}
}
*/
/*
void Corrida::aceleraCarrosInit(vector<Piloto*> aux) {
	for (int i = 0; i < aut->returnNumCarrosPista(); i++)
		for (int j = 0; j < aux.size(); j++)
			if (aut->returnIdCarroPista(i) == aux[j]->getIDCar()){
				aux[j]->acelera();
				break;
			}
}*/

bool Corrida::passaTempo() { //falta atualizar as posições no vetor classificaçoes
	int pos = 0;
	int maxPilotos;
	if (finalCorrida() == true) { //se algum piloto tiver "ultrapassado" o tamanho da pista, significa que a corrida terminou
		return true;
	}

	infoLog = "Segundo n. " + (tempoCorrida + 1);

 	while (pos < (maxPilotos = aut->returnNumPilotosPista())) {
		Piloto* aux = aut->returnPilotoPista(pos);
		int posicao = returnPosicaoEmPista(aux->getNome());
		aux->passaTempo(posicao, maxPilotos, tempoCorrida);
					
		if (aux->getDanificado() == true){
			aut->retiraPilotoDaPista(aux->getIDCar()); //coloca o piloto na garagem
			if((pos+1) <= maxPilotos){ // caso haja algum carro atras
				Piloto* next = aut->returnPilotoPista(pos + 1);
				next->danificaCarro(); //não tenho certeza que vai funcionar... Talvez, tem que se testar!!!!
				eliminarDaClassificacao(aux->getNome(), next->getNome()); //elimina os pilotos da classificacao
				infoLog += "Piloto " + aux->getNome() + "teve um acidente e danificou o carro ao piloto " + next->getNome();
			}

			eliminarDaClassificacao(aux->getNome());
			infoLog += "Piloto " + aux->getNome() + "teve um acidente";
		}

		if (aux->getEmergencia() == true && aux->getDanificado() == false) {
			aut->retiraPilotoDaPista(aux->getIDCar()); //retira piloto da pista e coloca-o na garagem
			eliminarDaClassificacao(aux->getNome());
			infoLog += "Piloto " + aux->getNome() + " acionou o sinal de emergencia";
		}
		atualizarMetrosPista(aux->getNome(), aux->getVelocidadeAtual());

		pos++;
	}
	//organiza o vetor da classificação
	atualizaVecClass();
	verificaSeMudouPos();
	tempoCorrida++;

	return false;
}

string Corrida::mostraPosicoes() const {
	ostringstream os;

	for (int i = 0; i < classificacao.size(); i++)
		os << classificacao[i]->getAsString();

	return os.str();
}

//funções auxiliares
//retorna posição em pista... 
int Corrida::returnPosicaoEmPista(string nomePil) {
	for (int i = 0; i < classificacao.size(); i++)
		if (classificacao[i]->returnNome() == nomePil) 
			return classificacao[i]->returnPosClassificacao();
}

//função que modifica a organização dos pilotos em pista :)
void Corrida::atualizaVecClass(){
	sort(classificacao.begin(), classificacao.end(), compare);

	for (int i = 0; i < classificacao.size(); i++) {
		classificacao[i]->setPosCorrida(i + 1);
	}
}

//função que verifica se algum dos pilotos já chegou ao final da corrida
bool Corrida::finalCorrida() {
	int tamPista = aut->returnTamPista();
	for (int i = 0; i < classificacao.size(); i++)
		if (classificacao[i]->returnPosAtual() >= tamPista)
			return true;

	return false;
}

void Corrida::eliminarDaClassificacao(string n1, string n2) {
	vector<Posicoes*>::iterator it;
	for (it = classificacao.begin(); it != classificacao.end();) {
		if ((*it)->returnNome() == n1)
			it = classificacao.erase(it);
		else if ((*it)->returnNome() == n2)
			it = classificacao.erase(it);
		else
			it++;
	}
}

//função que atualiza os metros percorridos pelo carro
void Corrida::atualizarMetrosPista(string piloto, int m) {
	for (int i = 0; i < classificacao.size(); i++)
		if (classificacao[i]->returnNome() == piloto)
			classificacao[i]->setPosicaoPista(m);

}

//função para atualizar a posição do carro no ecrã
void Corrida::verificaSeMudouPos() {
	int dis = aut->returnTamPista() / repPista;

	for (int i = 0; i < classificacao.size(); i++) { //percorre o vetor das classificacoes
		int atual = classificacao[i]->returnPosAtual();
		int anterior = classificacao[i]->returnPosAnterior();
		while (anterior < atual) { //enquanto os "metros" anteriores forem menores ou iguais aos atuais
			if ((anterior % dis) == 0) { //se a divisao der resto zero
				classificacao[i]->MexePosEcra();	//hora de mudar a posição
				anterior++;
			}
			else
				anterior++; //senão incrementa
		}
	}
}

Corrida::~Corrida() {

	aut = nullptr;

	vector <Posicoes*>::iterator it;
	for (it = classificacao.begin(); it != classificacao.end(); it++)
		delete* it;

}