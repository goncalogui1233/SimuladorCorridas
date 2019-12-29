#include "DGV.h"
#include <sstream>
#include <iostream>


//construtor por cópia
DGV::DGV(const DGV& aux) {
	for (unsigned int i = 0; i < aux.carros.size(); i++)
		this->carros.push_back(new Carro(*aux.carros[i]));

	for (unsigned int i = 0; i < aux.getPilotosTam(); i++) {
		aux.pilotos[i]->atribuiCarro(aux.pilotos[i]->returnCarro());
		this->pilotos.push_back(aux.pilotos[i]->clone());

	}
}


string DGV::carregaPilotosFich(string fich) {
	ifstream f;
	string tipo;
	string nome;
	string s;
	f.open(fich);

	if (!f)
		return "Erro a abrir o ficheiro, Confirme o nome do ficheiro\n";

	while (!f.eof()) {
		getline(f, s);
		istringstream is(s);
		is >> tipo >> ws;
		getline(is, nome);
		nome += " ";

		if (tipo == "crazy")
			pilotos.push_back(new CrazyDriver(nome));
		else if (tipo == "rapido")
			pilotos.push_back(new FastDriver(nome));
		else if (tipo == "surpresa")
			pilotos.push_back(new SurpriseDriver(nome));
	}

	f.close();
	return "Ficheiro lido com sucesso!\n";
}

string  DGV::carregaCarrosFich(string fich) {
	ifstream f;
	int maxvelocidade;
	double initCap, maxenergia;
	string marca, modelo;
	f.open(fich);

	if (!f)
		return "Erro a abrir o ficheiro, Confirme o nome do ficheiro\n";

	while (!f.eof()) {
		try {
			modelo = "";
			f >> initCap >> maxenergia >> maxvelocidade >> marca;

			getline(f, modelo);

			if (initCap <= 0 || maxenergia <= 0 || maxvelocidade <= 0 || marca.empty()) {
				throw exception("Erro a ler o ficheiro, Confirme os dados\n");
			}

			if (!modelo.empty())
				carros.push_back(new Carro(initCap, maxenergia, maxvelocidade, marca, modelo));
			else
				carros.push_back(new Carro(initCap, maxenergia, maxvelocidade, marca));
		}
		catch (exception & e) {
			f.close();
			return e.what();
		}
	}

	f.close();

	return "Ficheiro Lido com sucesso!\n";
}


string DGV::insereCarro(vector <string> vec) {

	// 2 - Cap Inicial, 3 - Capacidade Max, 4 - velocidade Max, 5 - marca, 6 - modelo (se houver)
	if (!vec[2].empty() && !vec[3].empty() && !vec[4].empty() && !vec[5].empty()) {
		carros.push_back(new Carro(stod(vec[2]), stod(vec[3]), stoi(vec[4]), vec[5], vec[6]));
		return "Carro inserido com sucesso\n";
	}

	return "Nao foi possivel inserir carro, verifique os parametros\n";
}

string DGV::inserePiloto(string tipo, string nome) {
	Piloto* aux = Piloto::fabrica(tipo, nome);
	if (aux != nullptr) {
		pilotos.push_back(aux);
		return "Piloto inserido com sucesso\n";
	}

	return "Nao foi possivel inserir o piloto, verifique os parametros\n";
}

string DGV::eliminaCarro(string ident) {
	vector<Carro*>::iterator it;

	for (it = carros.begin(); it != carros.end();) {
		if ((*it)->getID() == ident.at(0)) {
			string aux = retiraPilotoDeCarro(ident.at(0)); //colocou-se a enviar para string para evitar WARNING
			delete* it;
			it = carros.erase(it);
			return "Carro eliminado com sucesso\n";
		}
		else
			it++;
	}

	return "Carro nao encontrado, tente novamente\n";
}

string DGV::eliminaPiloto(string ident) {
	vector<Piloto*>::iterator it;

	for (it = pilotos.begin(); it != pilotos.end();) {
		if ((*it)->getNome() == ident) {
			retiraPilotoDeCarro((*it)->getIDCar());
			delete* it;
			it = pilotos.erase(it);
			return "Piloto eliminado com sucesso\n";
		}
		else
			it++;
	}

	return "Piloto não encontrado, tente novamente\n";
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
				return "Carro nao encontrado, tente novamente!!!\n"; //não encontrou carro
			}
			else
				return "Piloto ja esta dentro de um carro!!!\n"; //piloto tem carro
		}
	}
	return "Piloto nao encontrado, tente novamente!!!\n"; //piloto não encontrado

}

string DGV::retiraPilotoDeCarro(const char car) {
	vector <Piloto*>::iterator it;

	for (it = pilotos.begin(); it != pilotos.end(); it++) {
		if ((*it)->getIDCar() == car && (*it)->getCarroParado() == true) {
			(*it)->retiraCarro();
			return "Piloto Retirado do Carro\n";
		}
	}

	return "Piloto nao encontrado\n";
}

//função que retorna ponteiro de piloto para ser usado no campeonato
Piloto* DGV::retornaPiloto(string nome) {  
	for (unsigned int i = 0; i < pilotos.size(); i++)
		if (pilotos[i]->getNome() == nome && pilotos[i]->returnCarro() != nullptr)
			return pilotos[i];

	return nullptr;
}

string DGV::listagem() const {
	ostringstream os;

	if (pilotos.size() != 0) {
		os << "Pilotos: " << endl;
		for (unsigned int i = 0; i < pilotos.size(); i++)
			os << pilotos[i]->getAsString() << endl;
	}
	else
		os << "Nao existem pilotos" << endl;

	if (carros.size() != 0) {
		os << endl << "Carros: " << endl;
		for (unsigned int i = 0; i < carros.size(); i++)
			os << i << ": " << carros[i]->getAsString();
	}
	else
		os << "Nao existem carros" << endl;
	return os.str();
}

//string DGV::listaCarros() const {
//	ostringstream os;
//
//	for (unsigned int i = 0; i < carros.size(); i++) //unsigned pois não são necessários inteiros negativos!!
//		os << "Nome: " << carros[i]->getMarca() << " ID: " << carros[i]->getID() << endl;
//
//	return os.str();
//}

int DGV::getCarrosTam() const {
	return (int)carros.size();
}

int DGV::getPilotosTam() const {
	return (int)pilotos.size();
}

DGV::~DGV() {
	//liberta memoria vector pilotos
	/*vector <Piloto*>::iterator it;
	for (it = pilotos.begin(); it != pilotos.end(); it++)
		delete *it;

	vector <Carro*>::iterator itC;
	for (auto itC = carros.begin(); itC != carros.end(); itC++)
		delete* itC;*/

 
	for (auto p : pilotos)
		delete p;

	for (auto c : carros)
		delete c;
}