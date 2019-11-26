#include "Corrida.h"

Corrida::Corrida(Autodromo* aux, vector<Piloto*> part, int rep)
	:repPista(rep){
	contaPosicao = 1;
	aut = aux;
	for (int i = 0; i < aut->returnNumCarrosPista(); i++) { //percorre vetor dos carros na pista
		for (int j = 0; j < part.size(); j++) {	//percorre vetor dos pilotos participantes na corrida, passado por argumento
			if (aut->returnIdCarroPista(i) == part[j]->getIDCar())
				classificacao.push_back(new Posicoes(part[j]->getNome(), part[j]->getIDCar(), contaPosicao++));
		}
	}
}

void Corrida::atualizaPosCorrida(const vector<Piloto*>aux) {
	cout << "V0" << endl;
	for (int i = 0; i < aut->returnNumCarrosPista(); i++){ 
		cout << "V1" << endl;
		for (int j = 0; j < aux.size(); i++){		//percorre o vetor dos participantes, passado por argumento
			cout << "V2" << endl;
			if (aut->returnIdCarroPista(i) == aux[j]->getIDCar()){
				for (int k = 0; k < classificacao.size(); k++){ //percorre o vetor das classificacoes
					cout << "V3" << endl;
					if (classificacao[k]->returnCharCarro() == aut[i].returnIdCarroPista(i)){
						classificacao[k]->setPosicaoPista(aux[j]->returnVelocidadeAtual());
						break;
					}
				}
			}
			break;
		}
		break;
	}
}

void Corrida::aceleraCarrosInit(vector<Piloto*> aux) {
	for (int i = 0; i < aut->returnNumCarrosPista(); i++)
		for (int j = 0; j < aux.size(); j++)
			if (aut->returnIdCarroPista(i) == aux[j]->getIDCar()){
				aux[j]->acelera();
				break;
			}
}

void Corrida::verificaSeMudouPos() {
	int dis = aut->returnTamPista() / repPista;

	for (int i = 0; i < classificacao.size(); i++) { //percorre o vetor das classificacoes
		int atual = classificacao[i]->returnPosAtual(); 
		int anterior = classificacao[i]->returnPosAnterior();
		while (anterior < atual) { //enquanto os "metros" anteriores forem menores ou iguais aos atuais
			if ((anterior % dis) == 0) { //se a divisao der resto zero
				classificacao[i]->MexePosEcra();	//hora de mudar a posição
				break;
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