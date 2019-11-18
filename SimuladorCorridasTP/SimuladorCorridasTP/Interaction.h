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

	int modo;

	void opcoesModo1();

	void helpModo1() const;

	void opcoesModo2();

	void listaComandosModo2() const;

public:

	Interaction(Jogo* d);

	void leituraComandos();

};