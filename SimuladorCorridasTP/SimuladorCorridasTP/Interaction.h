#pragma once

#include "Jogo.h"
#include "Consola.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


class Interaction {

	Jogo* j;

	vector<string> c; //vetor que guarda os comandos

	const int representacaoPista = 50; //calcular "andamento" das letras: metrosPista / representação

	int modo;

	void representarPista();

	void opcoesModo1();

	void helpModo1() const;

	void opcoesModo2();

	void listaComandosModo2() const;

	void escolhePilotos();

public:

	Interaction(Jogo* d);

	void leituraComandos();

};