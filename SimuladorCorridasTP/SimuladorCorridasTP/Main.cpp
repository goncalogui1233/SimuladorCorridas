#include "Jogo.h"
#include "Interaction.h"


using namespace std;

int main() {
	Jogo jog;

	Interaction it(&jog);

	it.leituraComandos();
}