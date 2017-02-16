#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Player.h"

using namespace std;

class Player;

class Level {
private:
	fstream file;
	vector <string> level_line;
	friend class Player;
	friend class Sword;

public:
	void load(string file_name);  //wczytanie mapy
	void show(Level &lev, Player &p); //pokazywanie pokolorowanej mapy na ekranie
	void actualPlayerPosition(Level &lev, Player &ply); //lokalizowanie znaku @ i ustawianie atrybutow x,y gracza
};