#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include "Level.h"
#include "GameSys.h"
#include "Player.h"
#include "Item.h"
#include "Mob.h"

using namespace std;

GameSys::GameSys() {		//konstruktor
	option = 0;				//ustawienie opcji wyboru MENU GLOWNEGO na 0 (niezdefiniowany wybor)			
	start = 0;				//ustawienie opcji wyboru MENU STATYSTYK BOHATERA na 0 (niezdefiniowany wybor)
	goToMainMenu = 1;
}

template<class T> inline void GameSys::verify(T &ver) {
	cin >> ver;
	while (1)
	{
		if (!cin.good()) {
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Podano niewlasciwy typ danych. Powtorz wpis.  " << endl;
			cin >> ver;
		}
		if (cin.good())
			break;
	}
}


void GameSys::setMainMenu() {	

	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << endl;
	cout << "                <------ == == == == oo00oo == == == == ------>" << endl;
	cout << "                                                               " << endl;
	cout << "               		            WITAMY                 " << endl;
	cout << "                	       JASKINIA & SMOK             " << endl;
	cout << "                                                       " << endl;
	cout << "                <------ == == == == oo00oo == == == == ------>" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl;
	cout << endl;
	cout << "1. Nowa gra" << endl;
	cout << "2. Wyjscie" << endl;
	cout << endl;
	
	do {
		cout << "Wybierz swoje przeznaczenie: ";
		verify<int>(option);
		if (option == 1) {
			goToMainMenu = 0; break; //ustawienie flagi goToMainMenu na 0. Ustawienie na 1 bedzie spowodowane smiercia lub klawiszem ESC.
		}
	} while (option != 2);

	if (option == 2) {
		cout << "Do zobaczenia !!! ";
		exit(0);
	}

}

Player GameSys::setPlayerStats() {
	system("CLS");
	Player playr,playr2,playr3;		//trzech playerow, aby "dolosowywac" zmienione wsplczynniki obrony i ataku. Zmienione wsplczynniki zapisywane sa do playra
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << endl;
	cout << "                        <------ == == == == J & S == == == == ------>" << endl;
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "Witaj !!!" << endl;
	cout << "Zjawiasz sie w idelnym momencie !!! Od kilku miesiecy, nasze miasto regularnie nawiedza i pladruje smok. " << endl;
	cout << "Organizujemy wlasnie wyprawe samobojc ... yyy odwaznego bohatera. Z nieba nam spadles." << endl;
	cout << "Nie szkodzi, ze jestes u nas tylko przelotem. Pokazemy Tobie jaskinie smoka, raz, dwa go zabijesz i bedziesz mogl dalej podrozowac" << endl;
	cout << "Hmmm, mowisz nie masz czasu ... To moze ujme to inaczej. Jezeli zaraz nie pojdziesz do tej jaskini, to znamy z chlopakami pare ciekawych sposobow przekonywania ..." << endl;
	cout << "I to jest duch !!! Takich ludzi nam potrzeba. Prosze, tam jest jaskinia. Powodzenia !!! " << endl;
	cout << "A w ogole to jak masz na imie ? " << endl;
	cout << endl;
	cout << "Podaj swoje imie : ";
	cin >> playr.name;
	playr.damagePlayer = playr.damagePlayer + (roll(10,70) / roll(1, 3));				//bardzo randomowa pol empiryczna formula losujaca wspolczynniki :)
	playr.defensePlayer = playr.defensePlayer + roll(roll(10,70),70) / roll(1, 3);		//jak wyzej tylko ze jeszcze bardziej losowa formula :)
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << endl;
	cout << "                        <------ == == == == J & S == == == == ------>" << endl;
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "Los wlasnie rozdal karty. Sprawdz jakim bohaterem przyjdzie Tobie rozgrywac Twoj nierowny pojedynek ze zlem.";
	cout << endl;
	bottomMenu(playr);
	cout << "Zaskoczony, zniesmaczony a moze zachwycony swoim nowym herosem ?" << endl;
	cout << "Jezeli uwazasz, ze stac Ciebie na wiecej i chcesz rzucic losowi rekawice w twarz mozesz ponownie wylosowac bohatera." << endl;
	cout << "Badz ostrozny jednak. Los jest kaprysny i kolejnym razem przeznaczenie moze nie byc tak przychylne. Pozostaly Tobie jeszcze 2 proby.";
	cout << endl;
	cout << "1. Rozpocznij gre" << endl;
	cout << "2. Ponownie losuj statystyki bohatera" << endl;
	cout << "Wybor: ";
	
	verify<int>(start);
	if (start != 1) {			//jezeli nie zostal wybrany start kolejne losowanie						
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << endl;
		cout << "                        <------ == == == == J & S == == == == ------>" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		playr.damagePlayer = playr2.damagePlayer + (roll(10,70) / roll(1, 3.5));
		playr.defensePlayer = playr2.defensePlayer + roll(roll(10,70),80) / roll(1,3.5);
		cout << "Los ponownie pochylil sie w Twojej sprawie. Sprawdz teraz kim przyjdzie Tobie walczyc.";
		cout << endl;
		bottomMenu(playr);
		cout << "I jak ? Jestes godny powyzszych statystyk ? Jezeli nie, znasz procedure. Pamietaj tylko, ze jest to Twoja ostatnia proba !";
		cout << endl;
		cout << "1. Rozpocznij gre" << endl;
		cout << "2. Ponownie losuj statystyki bohatera" << endl;
		cout << "Wybor: ";
		
		verify<int>(start);
	if (start != 1) {		//jezeli nie zostal wybrany start kolejne losowanie
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << endl;
		cout << "                        <------ == == == == J & S == == == == ------>" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Ostateczny osad wydany. Pozostala juz jedynie walka. Oto statystyki Twojego bohatera.";
		playr.damagePlayer = playr3.damagePlayer + (roll(10,70) / roll(1, 4));
		playr.defensePlayer = playr3.defensePlayer + roll(roll(10,70),80) / roll(1, 4);
		cout << endl;
		bottomMenu(playr);
		cout << "1. Rozpocznij gre" << endl;
		cout << "Wybor: ";
		do {
			verify<int>(start);
			if (start != 1) cout << "Nie uciekniesz od przeznaczenia !";
		} while (start != 1);
	}

	}
	
	playr.defaultDamagePlayer = playr.damagePlayer;    //ustawienie domyslnej wartosci ataku, aby atak miecza byl dodawany do wartosci bazowej a nie poprzedniej  
	playr.defaultDefensePlayer = playr.defensePlayer;  //ustawienie domyslnej wartosci obrony, aby obrona zbroi byla dodawana do wartosci bazowej a nie poprzedniej
	return playr;

}

void GameSys::bottomMenu(Player p)
{
	int health, damagePlayer, defensePlayer, exp, exp_level;
	cout << endl;
	cout << "Imie: " << p.name << endl;
	cout << "Zdrowie: " << p.health << endl;
	cout << "Atak: " << p.damagePlayer << endl;
	cout << "Obrona: " << p.defensePlayer << endl;
	cout << "Poziom: " << p.exp_level << endl;
	cout << "Doswiadczenie: " << p.exp << endl;
	cout << endl;
	
}

void GameSys::game(GameSys &g, Level &l, Player &p) {
	p = g.setPlayerStats();
	l.load("Lev1.txt");
	l.show(l, p);
	p.move(g,l, p);
		
}