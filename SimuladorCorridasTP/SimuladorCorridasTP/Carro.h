#pragma once

#include <string>
#include <sstream>


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

	//Destrutor da Class
	/*
	* Using virtual destructors, you can destroy objects without knowing their type.
	* the correct destructor for the object is invoked using the virtual function mechanism.
	*
	*/
	~Carro() {}

	// return faz sentido fazer no header para nao ter que ir por exemplo à pilha.. 
	// É mais rápido 
	inline char getID() const {
		return id;
	}

	inline bool getDanificado() const {
		return danificado;
	}

	void setDanificado(bool danificado);

	/* Manivela de carregamento do carro (em mAh)
	* Não pode ultrapassar a quantidade Max de energia. 
	* Se conseguir carregar, devolve true
	* Senão devolve False
	*/
	bool manivela(int valCarregamento);

	string getMarca() const;

	string getAsString()const;


	void setEmergencia();

	 /* Alterar Estado do Carro ( e vice-versa)
	 *
	 *  Se não estiver parado, passa a estar
	 *
	 */
	void setEstado();

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
