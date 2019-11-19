#pragma once
#include <string>
#include <sstream>

using namespace std;

class Carro {
	static int idcar;
	const string marca;
	string modelo;
	const char id;
	const int maxvelocidade;
	const double maxenergia;
	int velocidadeAtual = 0;
	double energia = 0;
	bool parado = true, emergencia = false;
	bool danificado = false;

public:

	Carro(string mar, double maxe, int maxv, string mod = "Modelo Base");

	Carro(const Carro& aux);

	inline char getID() const {
		return id;
	}

	inline bool getDanificado() const {
		return danificado;
	}

	string getMarca() const {
		return marca;
	}

	string getAsString()const;

	void setEstado();

	bool manivela(int val);

	void setEmergencia();

	void acelerador(int vel = 1);

	void travao();

	~Carro();

};
