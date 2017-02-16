#include <iostream>
#include <conio.h>
#include "Player.h"
#include "Level.h"
#include "Item.h"
#include "GameSys.h"
#include "Mob.h"
#include <string>

using namespace std;

Player::Player()
{
	health = 100;
	damagePlayer = 10;
	defensePlayer = 10;
	exp = 0;
	exp_level = 1;
	ballast = 0;
	name = "XXX";
	weapon = "Brak broni";
	armor = "Brak zbroi";
	x = 0;
	y = 0;
}

void Player::setPlayerPosition(int xx, int yy) {
	x = xx;
	y = yy;

}

void Player::getPlayerPosition() {
	cout << endl;
	cout << "X: " << x;
	cout << "Y: " << y;

}

// xx, yy parametry umozliwiaja zastosowanie jednej metody do wszystkich typow ruchu - gora, dol, boki
void Player::moveReactions(GameSys &game, Level &lev, Player &play, int xx, int yy) {
	
	char answer;
	
	//chodzenie
	if (lev.level_line[y + yy][x + xx] == ' ') {
		lev.level_line[y + yy][x + xx] = '@';
		lev.level_line[y][x] = ' ';
	}

	//reakcja na sciany
	if (lev.level_line[y + yy][x + xx] == '#') {
		cout << endl;
		cout << "Brak umiejetnosci przenikania przez sciany";
		system("Pause> NULL");
	}

	//reakcja na miecz
	if (lev.level_line[y + yy][x + xx] == 's') {
		
		Sword sw;
		cout << endl;
		sw.sword_info(sw);
		cout << endl;
		cout << "Czy chcesz zaczac uzywac znaleziony miecz ?" << endl;
		cout << "(T - Tak/N - Nie): ";
		cin >> answer;
		if (answer == 'T' || answer == 't') {
			weapon = sw.name;
			play.damagePlayer = play.defaultDamagePlayer + sw.damage;
			lev.level_line[y + yy][x + xx] = '@';
			lev.level_line[y][x] = ' ';
		}
		if (answer != 'T' || answer != 't') {
			lev.level_line[y + yy][x + xx] = '@';
			lev.level_line[y][x] = ' ';
			lev.show(lev, play);
		}
		system("Pause> NULL");
	}

	//reakcja na zbroje
	if (lev.level_line[y + yy][x + xx] == 'a') {
		Armor ar;
		cout << endl;
		ar.armor_info(ar);
		cout << endl;
		cout << "Czy chcesz nalozyc znaleziona zbroje ?" << endl;
		cout << "(T - Tak/N - Nie): ";
		cin >> answer;
		if (answer == 'T' || answer == 't')
		{
			armor = ar.name;
			play.defensePlayer = play.defaultDefensePlayer + ar.defense;
			lev.level_line[y + yy][x + xx] = '@';
			lev.level_line[y][x] = ' ';
		}
		if (answer != 'T' || answer != 't')
		{
			lev.level_line[y + yy][x + xx] = '@';
			lev.level_line[y][x] = ' ';
			lev.show(lev, play);
		}
		system("Pause> NULL");
	}

	//reakcja na eliksir
	if (lev.level_line[y + yy][x + xx] == 'e') {
		Elixir el;
		cout << endl;
		el.elixir_info(el);
		cout << endl;
		cout << "Czy chcesz go wypic ?" << endl;
		cout << "(T - Tak/N - Nie): ";
		cin >> answer;
		if (answer == 'T' || answer == 't')
		{
			play.health = play.health + el.hp_reg;
			lev.level_line[y + yy][x + xx] = '@';
			lev.level_line[y][x] = ' ';
		}
		if (answer != 'T' || answer != 't')
		{
			lev.level_line[y + yy][x + xx] = '@';
			lev.level_line[y][x] = ' ';
			lev.show(lev, play);
		}
		system("Pause> NULL");
	}

	//reakcja na trola 
	if (lev.level_line[y + yy][x + xx] == 'T') {
		//Mob *mbTroll = new Troll;
		Troll trolo;
		cout << endl;
		cout << "Na Twojej drodze stanal trol. Wyszczerzone zeby, slina cieknaca z pyska i okrzyki wskazuja na jego malo pokojowe zamiary. Czy chcesz go zaatakowac ?" << endl;
		cout << "(T - Tak/N - Nie): ";
		cin >> answer;
		if (answer == 'T' || answer == 't') {
			trolo.attack(game, lev, trolo, play); 
			lev.level_line[y + yy][x + xx] = '@';
			lev.level_line[y][x] = ' ';
		}
		system("Pause> NULL");
	}

	//reakcja na smoka 
	if (lev.level_line[y + yy][x + xx] == 'D') {
		Dragon dr;
		cout << endl;
		cout << "Na Twojej drodze stanal smok. Udajesz, ze bestia o dlugosci 25 metrow nie robi na Tobie wrazenia. " << endl;
		cout << "Czy na pewno chcesz go zaatakowac ? " << endl;
		cout << "(T - Tak/N - Nie): ";
		cin >> answer;
		if (answer == 'T' || answer == 't') {
			dr.attack(game, lev, dr, play); 
			lev.level_line[y + yy][x + xx] = '@';
			lev.level_line[y][x] = ' ';
		}
		
		system("Pause> NULL");
	}
}


void Player::move(GameSys &game, Level &lev, Player &play) {

	int PlayerX = x;
	int PlayerY = y;
	int k = 0;

	unsigned char moveKey;
	while (k != 1) {
		moveKey = _getch();
		//ORYGINALNY KOMENTARZ ZE STACKOVERFLOW
		//for detect the function\arrow keys 
		//we must call the getch() again
		//testing if moveKey is '0' or '0xE0'
		if (moveKey == 0 || moveKey == 0xE0) moveKey = _getch();

		switch (moveKey) {
		case 27: {				//ESC zeby przejsc do menu glownego
			cout << endl;
			cout << "Wszystkie dane gry zostana utracone. Nacisnij ponownie ESC, aby wyjsc lub inny klawisz pozostac dalej w grze.";
			moveKey = _getch();
			if (moveKey == 27) { k = 1; game.goToMainMenu = 1;  break; }
			else if (moveKey != 27) { lev.show(lev, play); }
					
		}

		case 72: {		//ruch w gore
			lev.actualPlayerPosition(lev, play);
			moveReactions(game, lev, play, 0, -1);
			if (game.goToMainMenu == 1) { k = 1; break; }
			lev.show(lev, play);
			break;
		}

		case 80: {		//ruch w dol
			lev.actualPlayerPosition(lev, play);
			moveReactions(game, lev, play, 0, 1);
			if (game.goToMainMenu == 1) { k = 1; break; }
			lev.show(lev, play);
			break;
		}

		case 75: {		//ruch w lewo
			lev.actualPlayerPosition(lev, play);
			moveReactions(game, lev, play, -1, 0);
			if (game.goToMainMenu == 1) { k = 1; break; }
			lev.show(lev, play);
			break;
		}

		case 77: {		//ruch w prawo
			lev.actualPlayerPosition(lev, play);
			moveReactions(game, lev, play, 1, 0);
			if (game.goToMainMenu == 1) { k = 1; break; }
			lev.show(lev, play);
			break;
			}
				
		}
		
	}
	game.goToMainMenu = 1; //flaga wykorzystywana aby przejsc do menu glownego
}
		
		