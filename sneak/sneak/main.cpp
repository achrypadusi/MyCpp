#include <iostream>
#include <time.h>
#include "board.h"


using namespace std;

int main() {
	//Game mojWaz(20, 20);
	Game* mojWaz = new Game(20, 20);
	mojWaz->startGame();

	while (1) {
		Sleep(1000);
		cin.get();
		delete mojWaz;
		Game* mojWaz = new Game(20, 20);
		Sleep(500);
		mojWaz->startGame();
	}



	//mojWaz.updatePix({ 1,2 },'o');
}