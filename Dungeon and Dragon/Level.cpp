#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include "Level.h"
#include <vector>
#include "GameSys.h"
#include "Player.h"


using namespace std;


void Level::load(string file_name) {
	
	system("CLS");
	string line;
	file.open(file_name.c_str(), ios::in);	//c_str zwraca ³añcuch znaków tylko do odczytu. Metoda ta umozliwia wczytanie stringa jako argumentu.
	if (file.good() == false) {
		cout << "Plik nie istnieje !";
		system("Pause");
		exit(0);
	}

while (getline(file, line)) {
	level_line.push_back(line);

	}

	file.close();
	 	
}

void Level::show(Level &lev, Player &p){
	GameSys game;
	system("CLS");
	actualPlayerPosition(lev, p); //ustawienie pozycji gracza
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "<------======== MAPA ========------>";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl;
	for(int i = -4; i <= 4; i++){ //petla wyswietlajaca prostokat o wielkosci 4 x 7 znakow, gdzie centralny punkt stanowi znak @
		cout << "           ";
		
		for (int j = -7; j <= 7; j++) {
			if ((level_line[(p.y + i)][(p.x + j)]) == '@') { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); cout << level_line[(p.y + i)][(p.x + j)]; }
			else {

				if ((level_line[(p.y + i)][(p.x + j)]) == 'D' || level_line[(p.y + i)][(p.x + j)] == 'T') { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); cout << level_line[(p.y + i)][(p.x + j)]; }
				else
				{

					if ((level_line[(p.y + i)][(p.x + j)]) == 's' || level_line[(p.y + i)][(p.x + j)] == 'a' || level_line[(p.y + i)][(p.x + j)] == 'e') { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5); cout << level_line[(p.y + i)][(p.x + j)]; }
					else
					{

						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

						cout << level_line[(p.y + i)][(p.x + j)];
						if (i == -4 && j == 7) cout << "                   STATYSTYKI " << "                   EKWIPUNEK ";
						if (i == -3 && j == 7) cout << "                   Imie: " << p.name << "                   Bron: " << p.weapon;
						if (i == -2 && j == 7) cout << "                   Zdrowie: " << p.health << "                  Zbroja: " << p.armor;
						if (i == -1 && j == 7) cout << "                   Atak: " << p.damagePlayer;
						if (i == 0 && j == 7) cout << "                   Obrona: " << p.defensePlayer << "                    WSKAZOWKI ";
						if (i == 1 && j == 7) cout << "                   Poziom: " << p.exp_level << "                     Do poruszania sie po planszy uzywaj strzalek.";
						if (i == 2 && j == 7) cout << "                   Doswiadczenie: " << p.exp << "             Aby zakonczyc gre nacisnij dwa razy klawisz ESC.";
					}
				}
			}
		}
		cout << endl;
	}
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "<------========oo00oo========------>";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl;
	cout << "LEGENDA: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "@ ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "- gracz,";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << " T ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "- trol,";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << " D ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "- smok,";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << " s ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "- miecz,";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << " a ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "- zbroja,";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << " e ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "- eliksir";
	cout << endl;
}

void Level::actualPlayerPosition(Level &lev, Player &ply) {

	char sign;
	for (size_t i = 0; i < lev.level_line.size(); i++) {
		for (size_t j = 0; j < lev.level_line[i].size(); j++) {
			sign = level_line[i][j];
			if (sign == '@')
			{
					ply.setPlayerPosition(j, i); 
				
			}
		}
	}
}

