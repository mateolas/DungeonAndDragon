#pragma once
#include <iostream>
#include "Player.h"

using namespace std;

class Player;
class Level;
class GameSys;

class Mob {
protected:
	int health, damage, defense;
	friend int roll(int x, int y);
		
public:
	Mob();
	void getMob(); //metoda pomocnicza
	void attack(Player &play); //metoda opisujaca reakcje gracz <-> mob	
};

class Troll :public Mob {
protected:
	string name;
public:
	Troll();
	void getTroll(); //metoda pomocnicza
	void attack(GameSys &game, Level &lev, Troll &tr, Player &play); //metoda opisujaca reakcje gracz <-> troll

};

class Dragon: public Mob {
protected:
	string name;
public:
	Dragon();
	void attack(GameSys &game, Level &lev, Dragon &dr, Player &play); //metoda opisujaca reakcje gracz <-> smok
	void getDragon(); //metoda pomocznicza
};
