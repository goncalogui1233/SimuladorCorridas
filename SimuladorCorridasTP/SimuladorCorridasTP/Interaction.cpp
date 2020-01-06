#include "Interaction.h"
#include "Piloto.h"

Interaction::Interaction(Jogo* d) {
	j = d;
	modo = 1;

	this->leituraComandos();
}

void Interaction::leituraComandos() {
	while (!end) {
		c.clear();	//limpa o vetor que recebe os comandos
		string com;
		do {
			Consola::clrscr();

			if (modo == 1)

				cout << "Modo 1" << endl;
			else
				cout << "Modo 2" << endl;

			cout << "Insira um comando: ";
			getline(cin, com);
			if (com.empty()) {
				cout << "Nao foi inserido nenhum comando, tente novamente ";
				(void)getchar();
			}
		} while (com.empty());

		istringstream is(com);

		for (string s; is >> s;) //divide string e coloca no vetor de strings
			c.push_back(s);

		if (modo == 1)
			opcoesModo1();
		else
			opcoesModo2();
	}
}

void Interaction::opcoesModo1() {

	if (c[0] == "help") {
		Consola::clrscr();
		helpModo1();
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}

	else if (c[0] == "carregaP") {
		if (c.size() == 2) {
			cout << j->carregaPilotos(c[1]);
		}
		else
			cout << "Argumentos nao validos, tente novamente" << endl;
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}

	else if (c[0] == "carregaC") {
		if (c.size() == 2) {
			cout << j->carregaCarrosFich(c[1]);
		}
		else
			cout << "Argumentos nao validos, tente novamente" << endl;
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}

	else if (c[0] == "carregaA") {
		if (c.size() == 2) {
			cout << j->carregaAutodromosFich(c[1]);
		}
		else
			cout << "Argumentos nao validos, tente novamente" << endl;

		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}

	else if (c[0] == "cria") {
		cout << j->criaItensJogo(c);
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}

	else if (c[0] == "apaga") {
		cout << j->eliminaItemJogo(c);
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}

	else if (c[0] == "entranocarro") {
		cout << j->inserePilotoEmCarro(c);
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}

	else if (c[0] == "saidocarro") {
		cout << j->retiraPilotoDeCarro(c);
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}

	else if (c[0] == "lista") {
		cout << j->listagem();
		cout << "Pressione uma tecla para continua... ";
		(void)getchar();
	}

	else if (c[0] == "campeonato" && c.size() == 1) { //passa para o modo 2
		if (j->getNAutodromos() < 1)
		{
			cout << "Impossivel inciar campeonato sem Autodromos";
		}
		else if (j->getNCarros() > 0 && j->getNPilotos() > 1) {

			j->criaCampeonato(); //cria um novo campeonato
			escolhePilotos();
			if (j->getParticipantes_size() >= 2) {
				modo = 2;
				leituraComandos();
			}
			else {
				cout << "E necessario participantes";
			}
		}
		else
		{
			cout << "Impossivel inciar campeonato sem carros e/ou sem pilotos. (E' exigido pelo menos 2 pilotos no minimo)";
		}
		(void)getchar();
	}

	else if (c[0] == "savedgv")
		cout << "Guarda DGV";

	else if (c[0] == "loaddgv")
		cout << "carrega DGV";

	else if (c[0] == "deldgv")
		cout << "Apaga DGV";

	else if (c[0] == "sair") {
		cout << "A sair...";
		end = 1;
	}
	else {
		cout << "Comando nao existente, (help) mostra comandos" << endl;
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}
}

void Interaction::opcoesModo2() {
	if (c[0] == "help") {
		Consola::clrscr();
		listaComandosModo2();
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}
	else if (c[0] == "campeonato") {
		cout << j->adicionarAutodromoCamp(c) << endl;
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}

	else if (c[0] == "listacarros") {
		cout << j->listaCarrosCampeonato() << endl;
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();

	}

	else if (c[0] == "carregabat") {
		if (c.size() == 3)
			cout << j->carregaBateriaCarro(c[1], c[2]) << endl;
		else
			cout << "Argumentos nao validos, tente novamente" << endl;
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}

	else if (c[0] == "carregatudo" && c.size() == 1) {
		cout << j->carregaBateriasCarros() << endl;
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}
	else if (c[0] == "corrida" && c.size() == 1) {
		corrida();
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}

	else if (c[0] == "acidente" && c.size() == 2)
		cout << j->acidente(c[1]) << endl;
	else if (c[0] == "stop" && c.size() == 2)
		cout << j->stop(c[1]) << endl;
	else if (c[0] == "destroi" && c.size() == 2) {
		cout << j->destroiCarro(c[1]) << endl;
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}

	else if (c[0] == "passatempo") {

		if (c.size() == 2 && c[1].find_first_not_of("0123456789") == -1 && stoi(c[1]) > 0) {

			for (unsigned int i = 0; i < stoi(c[1]); i++) {
				representarPista();
				bool term = j->passarTempo();
				if (term == true) //caso a corrida termine, sai imediatamente do ciclo
					break;
				Sleep(2000); // 2 segundos
			}
		}
		else
			cout << "Argumentos nao validos, tente novamente" << endl;

		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}
	else if (c[0] == "classificacao" && c.size() == 1){
		cout << j->classificaoCorrida() << endl;
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}
	else if (c[0] == "garagem" && c.size() == 1) {
		j->garagem();
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}
	else if (c[0] == "log") {
		cout << j->mostraLogCorrida() << endl;
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
	}
	else if (c[0] == "exit") {
		j->apagaCampeonato();
		modo = 1;
		leituraComandos();
	}
	else {
		cout << "Comando nao existente, (help) mostra comandos" << endl;
		cout << "Pressione uma tecla para continuar... ";
		(void)getchar();
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
	cout << "- campeonato " << endl;
	cout << "- savedgv <nome>" << endl;
	cout << "- loaddgv <nome>" << endl;
	cout << "- deldgv <nome>" << endl;
	cout << "- sair" << endl;
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
	cout << "- classificacao" << endl;
	cout << "- garagem" << endl;
	cout << "- exit" << endl;
}

void Interaction::escolhePilotos() {
	string nome;
	while (1) {
		Consola::clrscr();
		c.clear();
		cout << "Escolha os pilotos que irao participar na corrida (apenas os que tem um carro associado)\nInsira 'fim' para passar ao menu campeonato" << endl << "> ";
		getline(cin, nome);

		if (nome == "fim")
			break;

		istringstream iss(nome);

		for (string s; iss >> s;) //divide string e coloca no vetor de strings
			c.push_back(s);

		cout << j->escolhePilotosCampeonato(c);
		cout << "Prima uma tecla para continuar... " << endl;
		(void)getchar();
	}
}


void Interaction::representarPista() {
	char a = 96;
	Consola::clrscr();
	cout << "Pista de Corridas" << endl;

	for (unsigned int i = 0; i < j->returnNumPilotosPista(); i++) {

		Consola::gotoxy(0, (2 * i) + 2);
		for (int j = 0; j < representacaoPista; j++) { //coloca os traços entre os ID's dos carros
			cout << (char)45;
		}
		cout << endl;
		cout << endl;
		Consola::gotoxy(j->returnPosX(i), (2 * i) + 3);
		cout << j->returnIDCarrosPista(i);
		cout << endl;
	}

	for (int i = 0; i < representacaoPista; i++) //necessário para fazer a última linha
		cout << (char)45;
	cout << endl << endl;

}



// Interation Corrida 
void Interaction::corrida() {
	if (j->getAutodromosCampeonato_size() == j->getAutodromoAtual()) {
		cout << "Nao existe autodromo para realizar a corrida" << endl;
		return;
	}

	if (j->getAutodromosCampeonato_size() > 0) {
		if (j->existeCorrida() == true)
			cout << "Ja existe uma corrida a decorrer, finalize-a primeiro" << endl;
		else {
			j->colocaCarrosEmPista();

			if (j->returnNumPilotosPista() >= 2) {
				cout << j->iniciaCorrida(representacaoPista);
				representarPista();
			}
			else {
				cout << "A corrida tem que ter no minimo 2 carros" << endl;
			}
		}
	}
	else
	{
		cout << "A corrida tem que ter autodromos" << endl;
	}
}