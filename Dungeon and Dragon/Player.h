#pragma once
#include <iostream>
#include "Level.h"
#include "Item.h"
#include "Mob.h"

using namespace std;

class Player {
private:

	int health, damagePlayer, defensePlayer, defaultDamagePlayer, defaultDefensePlayer, exp, exp_level, ballast;
	string name,weapon,armor;
	friend class GameSys;
	friend class Troll;
	friend int roll(int x, int y);
	int x;
	int y;
	friend class Level;

public:
	Player();
	void setPlayerPosition(int xx, int yy); //ustawienie x,y dla znaku @
	void getPlayerPosition(); //metoda pomocnicza
	void move(GameSys &game, Level &lev, Player &play); //metoda odpowiedzialna za reakcje za wcisnianie klawiszy (strzalki oraz ESC) 
	void moveReactions(GameSys &game, Level &lev,Player &play,  int xx, int yy); //reakcja gracza na poszczegolne elementy gry
	
};
