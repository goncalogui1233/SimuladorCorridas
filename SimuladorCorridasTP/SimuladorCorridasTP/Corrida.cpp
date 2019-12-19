#include "Corrida.h"

Corrida::Corrida(Autodromo* aux, int rep)
	:repPista(rep){
	contaPosicao = 1;
	aut = aux;
	for (int i = 0; i < aut->returnNumPilotosPista(); i++) { //percorre vetor dos pilotos na pista
				//classificacao.push_back(new Posicoes(aut[i].returnNomePiloto(i), aut[i].returnIDCarro(i), contaPosicao++));
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

string Corrida::mostraPosicoes() const {
	ostringstream os;

	for (int i = 0; i < classificacao.size(); i++)
		os << classificacao[i]->getAsString();

	return os.str();
}