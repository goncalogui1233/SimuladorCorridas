#include "DGV.h"
#include <sstream>
#include <iostream>

//construtor por cópia
DGV::DGV(const DGV& aux) {
	for (unsigned int i = 0; i < aux.carros.size(); i++)
		this->carros.push_back(new Carro(*aux.carros[i]));

	//for(int i = 0; i < aux.pilotos.size(); i++)
		//this->pilotos.push_back(new Piloto())
}


void DGV::carregaPilotosFich(string fich) {
	ifstream f;
	string tipo;
	string nome;
	f.open(fich);
	
	while (!f.eof()) {
		f >> tipo;
		getline(f, nome);
		cout << "Aqui";
		if (tipo == "crazy")
			pilotos.push_back(new CrazyDriver(nome));
		else if (tipo == "fast")
			pilotos.push_back(new FastDriver(nome));
		else if (tipo == "surpresa")
			pilotos.push_back(new SurpriseDriver(nome));
	}

	f.close();
}

void DGV::carregaCarrosFich(string fich) {
	ifstream f;
	int maxenergia, maxvelocidade;
	string marca, modelo;
	f.open(fich);

	while (!f.eof()) {
		modelo = "";
		f >> maxenergia;
		f >> maxvelocidade;
		f >> marca;
		f >> modelo;
		if (!modelo.empty())
			carros.push_back(new Carro(marca, maxenergia, maxvelocidade, modelo));
		else
			carros.push_back(new Carro(marca, maxenergia, maxvelocidade));
	}
}


string DGV::insereCarro(vector <string> vec) {
	if (!vec[2].empty() && !vec[3].empty() && !vec[4].empty()) {
		carros.push_back(new Carro(vec[2], stod(vec[3]), stoi(vec[4]), vec[5]));
		return "Carro inserido com sucesso\n";
	}

	return "Não foi possível inserir carro, verifique os parametros\n";
}

string DGV::inserePiloto(string tipo, string nome) {
	Piloto* aux = Piloto::fabrica(tipo, nome);
	if (aux != nullptr) {
		pilotos.push_back(aux);
		return "Piloto inserido com sucesso\n";
	}

	return "Não foi possível inserir o piloto, tente novamente\n";
}

string DGV::eliminaCarro(string ident) {
	vector<Carro*>::iterator it;

	for (it = carros.begin(); it != carros.end();) {
		if ((*it)->getID() == ident.at(0)){
			delete* it;
			it = carros.erase(it);
			return "Carro eliminado com sucesso";
		}
		else
			it++;
	}

	return "Carro não encontrado, tente novamente";
}

string DGV::eliminaPiloto(string ident) {
	vector<Piloto*>::iterator it;

	for (it = pilotos.begin(); it != pilotos.end();) {
		if ((*it)->getNome() == ident){
			delete *it;
			it = pilotos.erase(it);
			return "Piloto eliminado com sucesso";
		}
		else
			it++;
	}

	return "Piloto não encontrado, tente novamente";
}

string DGV::inserePilotoEmCarro(string car, string pil) {
	vector<Piloto*>::iterator it;

	for (it = pilotos.begin(); it != pilotos.end(); it++) {
		if ((*it)->getNome() == pil) {	//procura o piloto
			if ((*it)->temCarroAtribuido() != true) {	//se encontrar, vê se já tem um carro atribuido

				for (unsigned int i = 0; i < carros.size(); i++) {	//caso não tenha, percorre vetor carrod

					if (carros[i]->getID() == car.at(0)) {	//procura carro com o id
						if (carros[i]->getDisponibilidade() == true) { //verifica se o carro está disponivel
							(*it)->atribuiCarro(carros[i]);
							carros[i]->setDisponibilidade();
							return "Carro atribuido a piloto com sucesso :)\n";
						}
						else
							return "Carro existe mas ja ocupado por um piloto\n"; //carro ocupado
					}
				}
				return "Carro nao encontrado, tente novamento!!!\n"; //não encontrou carro
			}
			else
				return "Piloto ja esta dentro de um carro!!!\n"; //piloto tem carro
		}
	}
	return "Piloto nao encontrado, tente novamente!!!\n"; //piloto não encontrado

}

string DGV::retiraPilotoDeCarro(string pil) {
	vector <Piloto*>::iterator it;

	for (it = pilotos.begin(); it != pilotos.end(); it++) {
		if ((*it)->getNome() == pil) {
			(*it)->retiraCarro();
			return "Piloto Retirado do Carro";
		}
	}

	return "Piloto nao encontrado";
}

Piloto* DGV::retornaPiloto(string nome) {  //função que retorna ponteiro de piloto para ser usado no campeonato
	for (unsigned int i = 0; i < pilotos.size(); i++)
		if (pilotos[i]->getNome() == nome && pilotos[i]->returnCarro() != nullptr)
			return pilotos[i];

	return nullptr;
}


string DGV::listagem() const {
	ostringstream os;
	os << "Pilotos: \n";
	for (unsigned int i = 0; i < pilotos.size(); i++)
		os << pilotos[i]->getAsString() <<"\n";

	os << "Carros: \n";
	for (unsigned int i = 0; i < carros.size(); i++)
		os << carros[i]->getAsString();

	return os.str();
}

int DGV::getCarrosTam() const {
	return carros.size();
}

int DGV::getPilotosTam() const {
	return pilotos.size();
}

DGV::~DGV() {
	//liberta memoria vector pilotos
	vector <Piloto*>::iterator it;
	for (it = pilotos.begin(); it != pilotos.end(); it++)
		delete *it;

	vector <Carro*>::iterator itC;
	for (auto itC = carros.begin(); itC != carros.end(); itC++)
		delete* itC;
}