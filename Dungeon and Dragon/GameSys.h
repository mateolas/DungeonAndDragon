#pragma once
#include <iostream>
#include "Player.h"
#include "Item.h"

using namespace std;

class GameSys
{
private:
	friend class Player;
	friend int roll(int x);


public:
	int option;	//wybor opcji w menu glownym
	int start;	//wybor opcji w ustawieniach parametrow gracza
	int goToMainMenu;	//flaga na powrot do menu glownego
	GameSys();	//konstruktor bez argumentow
	void setMainMenu();	//ustawienie wyboru opcji w menu glownym
	Player setPlayerStats();	//ustawienie wartosci playera w menuplayera, zwraca obiekt Player
	void bottomMenu(Player playr);	//wyswietlanie parametrow gracza
	void game(GameSys &g, Level &l, Player &p);	//metoda zawierajaca glowne moduly gry
	template<class T>  void verify(T &ver);	//szablon do weryfikacji poprawnosci wprowadzanych danych 
};


