#include "DGV.h"
#include <sstream>
#include <iostream>

void DGV::carregaPilotosFich(string fich) {
	ifstream f;
	string tipo;
	string nome;
	f.open(fich);
	
	while (!f.eof()) {
		f >> tipo;
		getline(f, nome);
		cout << "Aqui";
		if (tipo == "c")
			pilotos.push_back(new CrazyDriver(nome));
		else if(tipo == "f")
			pilotos.push_back(new FastDriver(nome));
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
		if (modelo != "")
			carros.push_back(new Carro(marca, maxenergia, maxvelocidade, modelo));
		else
			carros.push_back(new Carro(marca, maxenergia, maxvelocidade));
	}
}

using namespace std;

void DGV::insereCarro(Carro *aux) {
	carros.push_back(aux);
}

string DGV::insereCarro(vector <string> vec) {
	if (vec[2] != "" && vec[3] != "" && vec[4] != "") {
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
						(*it)->atribuiCarro(carros[i]);
						
						return "Carro atribuido a piloto com sucesso :)\n";
					}
				}
				return "Carro não encontrado, tente novamento!!!\n"; //não encontrou carro
			}
			else
				return "Piloto já está dentro de um carro!!!\n"; //piloto tem carro
		}
	}

		return "Piloto não encontrado, tente novamente!!!\n"; //piloto não encontrado

}

string DGV::retiraPilotoDeCarro(string pil) {
	vector <Piloto*>::iterator it;

	for (it = pilotos.begin(); it != pilotos.end(); it++) {
		if ((*it)->getNome() == pil) {
			(*it)->retiraCarro();
			return "Piloto Retirado do Carro";
		}
	}

	return "Piloto não encontrado";
}


string DGV::listaPilotos() const {
	ostringstream os;
	os << "Pilotos: \n";
	for (unsigned int i = 0; i < pilotos.size(); i++)
		os << "Nome: " << pilotos[i]->getNome() <<"\n";

	os << "Carros: \n";
	for (unsigned int i = 0; i < carros.size(); i++)
		os << carros[i]->getAsString();

	return os.str();
}

string DGV::listaCarros() const {
	ostringstream os;

	for (unsigned int i = 0; i < carros.size(); i++) //unsigned pois não são necessários inteiros negativos!!
		os << "Nome: " << carros[i]->getMarca() << " ID: " << carros[i]->getID() << "\n";

	return os.str();
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