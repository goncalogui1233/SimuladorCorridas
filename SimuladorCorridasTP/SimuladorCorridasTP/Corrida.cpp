#include "Corrida.h"

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

void Corrida::passaTempo() { //passar isto para a pista :)
	string auxLog = "";
	int pos = 0;
	int maxPilotos = aut->returnNumPilotosPista();
	if (tempoCorrida == 0) {
		//pilotos arrancam...
	}
	else{
		while (pos <= maxPilotos) {
			Piloto* aux = aut->returnPilotoPista(pos);
			int posicao = returnPosicaoEmPista(aux->getNome());
			aux->passaTempo(posicao, maxPilotos, tempoCorrida);
			if (aux->getEmergencia() == true)
				//retira piloto da pista e coloca-o na garagem
				return;

			if(aux->getDanificado() ==  true)
				//
				


		}
	}

	tempoCorrida++;
}

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

//funções auxiliares
//retorna posição em pista... 
int Corrida::returnPosicaoEmPista(string nomePil) {
	for (int i = 0; i < classificacao.size(); i++)
		if (classificacao[i]->returnNome() == nomePil) 
			return classificacao[i]->returnPosClassificacao();
}

//função usada para ordenar vetor classificações
bool compare(const Posicoes& p1, const Posicoes& p2) {
	return p1.returnPosAtual() > p2.returnPosAtual();
} //sort(vector.begin(), vector.end(), compare) -> necessario #include <algorithm>