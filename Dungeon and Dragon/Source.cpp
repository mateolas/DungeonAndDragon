#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameSys.h"
#include "Player.h"
#include "Level.h"
#include "Mob.h"

using namespace std;

//funkcja libcz pseudolsowych z podanego zakresu
int roll(int x, int y) {
	int rol;
	srand(time(0));
	rol = rand() % ((y+1)-x) + x;	//liczba random z zakresu od x do y
	return rol;
}

int main()
{
	GameSys game;
	Player play;
	Level lev;
	while(1){ 
	if (game.goToMainMenu == 1) game.setMainMenu();
	game.game(game, lev, play);
	if (game.option == 2) break;
	}
	system("Pause");
	return 0;
}