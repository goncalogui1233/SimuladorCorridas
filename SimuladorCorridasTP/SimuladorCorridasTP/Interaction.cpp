#include "Interaction.h"
#include "Piloto.h"

Interaction::Interaction(Jogo* d) {
	j = d;
	modo = 1;
}

void Interaction::leituraComandos() {

	while (1) {
		c.clear();	//limpa o vetor que recebe os comandos
		string com;
		do {
			//Consola::clrscr();

			if (modo == 1)
				cout << "Modo 1" << endl;
			else
				cout << "Modo 2" << endl;

			cout << "Insira um comando: (help lista todos os comandos)" << endl;
			getline(cin, com);
			if (com == "")
				cout << "Não foi inserido nenhum comando, tente novamente" << endl;
		} while (com == "");
		istringstream ler_com(com);

		for (unsigned int i = 0; i < com.size(); i++) { //separa as palavras por espaços e coloca-as num vetor
			string a;
			ler_com >> a;
			c.push_back(a);
		}

		if (modo == 1)
			opcoesModo1();
		else
			opcoesModo2();
	}
}

void Interaction::opcoesModo1() {

	if (c[0] == "help")
		helpModo1();

	else if (c[0] == "carregaP")
		j->carregaPilotos("pilotos.txt");

	else if (c[0] == "carregaC")
		j->carregaCarrosFich("carros.txt");

	else if (c[0] == "carregaA")
		cout << "carregaP d Aco";

	else if (c[0] == "cria")
		cout << j->criaItensJogo(c);

	else if (c[0] == "apaga")
		cout << j->eliminaItemJogo(c);

	else if (c[0] == "entranocarro")
		cout << j->inserePilotoEmCarro(c[1], c[2]);

	else if (c[0] == "saidocarro")
		cout << j->retiraPilotoDeCarro(c[1]);

	else if (c[0] == "lista")
		cout << j->listagem();

	else if (c[0] == "campeonato") {
		modo = 2;
		leituraComandos();
	}
	else if (c[0] == "savedgv")
		cout << "Guarda DGV";

	else if (c[0] == "loaddgv")
		cout << "carrega DGV";

	else if (c[0] == "deldgv")
		cout << "Apaga DGV";
	else
		cout << "Comando não existente, (help) mostra comandos" << endl;
}

void Interaction::opcoesModo2() {
	if (c[0] == "help")
		listaComandosModo2();
	else if (c[0] == "campeonato")
		cout << "carregaP d Aco";
	else if (c[0] == "listacarros")
		cout << "carregaP d Aco";
	else if (c[0] == "carregabat")
		cout << "carregaP d Aco";
	else if (c[0] == "carregatudo")
		cout << "carregaP d Aco";
	else if (c[0] == "corrida")
		cout << "carregaP d Aco";
	else if (c[0] == "acidente")
		cout << "carregaP d Aco";
	else if (c[0] == "stop")
		cout << "carregaP d Aco";
	else if (c[0] == "destroi")
		cout << "carregaP d Aco";
	else if (c[0] == "passatempo")
		cout << "carregaP d Aco";
	else if (c[0] == "log")
		cout << "carregaP d Aco";
	else if (c[0] == "exit") {
		modo = 1;
		leituraComandos();
	}
}

void Interaction::helpModo1() const {
	cout << "Estes sao os comandos que existem: " << endl;
	cout << "- carregaP <nomeficheiro>" << endl;
	cout << "- carregaC <nomeficheiro>" << endl;
	cout << "- carregaA <nomeficheiro>" << endl;
	cout << "- cria <letraTipo> <dados do objeto>" << endl;
	cout << "- apaga <letraTipo> identificador" << endl;
	cout << "- entranocarro <letraCarro> <nomePiloto>" << endl;
	cout << "- saidocarro <letraCarro>" << endl;
	cout << "- lista" << endl;
	cout << "- savedgv <nome>" << endl;
	cout << "- loaddgv <nome>" << endl;
	cout << "- deldgv <nome>" << endl;
}

void Interaction::listaComandosModo2() const {
	cout << "Estes sao os comandos que existem: " << endl;
	cout << "- campeonato <A1> <A2>...<An>" << endl;
	cout << "- listacarros" << endl;
	cout << "- carregabat <letraCarro> <Q>" << endl;
	cout << "- carregatudo" << endl;
	cout << "- corrida" << endl;
	cout << "- acidente <letraCarro>" << endl;
	cout << "- stop <nomePiloto>" << endl;
	cout << "- destroi <letraCarro>" << endl;
	cout << "- passatempo <n>" << endl;
	cout << "- log" << endl;
}