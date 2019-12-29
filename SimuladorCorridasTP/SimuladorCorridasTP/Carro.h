#pragma once

#include <string>
#include <sstream>

using namespace std;

class Carro {
	static int idcar; //id que é atribuido aos carros
	const string marca;
	string modelo;
	const char id;
	const int maxvelocidade;
	const double maxenergia;
	const double initenergia;
	int velocidadeAtual = 0;
	double energia = 0;
	bool parado = true, emergencia = false;
	bool danificado = false;
	bool disponivel = true;

public:
	Carro(double initCap, double maxe, int maxv, string mar, string mod = "Modelo Base");
	Carro(const Carro& aux);

	//Destrutor da Class
	/*
	* Using virtual destructors, you can destroy objects without knowing their type.
	* the correct destructor for the object is invoked using the virtual function mechanism.
	*
	*/
	~Carro();

	char setIDs(int idcar);

	// return faz sentido fazer no header para nao ter que ir por exemplo à pilha.. 
	// É mais rápido 
	inline char getID() const {
		return id;
	}

	bool returnParado() const {
		return parado;
	}

	inline bool getDanificado() const {
		return danificado;
	}

	bool getDisponibilidade() const{
		return disponivel;
	}

	bool getEmergencia() const {
		return emergencia;
	}

	string getMarca() const {
		return marca;
	}

	int getVelocidadeAtual() const {
		return velocidadeAtual;
	}

	void setDisponibilidade();

	void setDanificado();

	/* Manivela de carregamento do carro (em mAh)
	* Não pode ultrapassar a quantidade Max de energia. 
	* Se conseguir carregar, devolve true
	* Senão devolve False
	*/
	bool manivela(double valCarregamento);

	double getMaxCarregamento()const {
		return maxenergia;
	}

	double getEnergiaAtual() const {
		return energia;
	}

	void drenaEnergia();

	string getAsString()const;


	void setEmergencia();

	 /* Alterar Estado do Carro ( e vice-versa)
	 *
	 *  Se não estiver parado, passa a estar
	 *
	 */
	void setEstado();

	/* Descelerar
	 *
	 *  Perde velocidade caso nao acelere
	 *
	 */
	void desacelerar();

	/* Acelerar
	 *
	 *  Se velocidade max < velocidadeAtual -> Acelera
	 *
	 */
	void acelerar(int velo = 1);

	/* Travar
	 *
	 *  Chama o method acelerar com velocidade -1
	 *
	 */
	void travar();

};
