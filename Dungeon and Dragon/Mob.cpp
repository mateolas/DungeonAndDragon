#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Mob.h"
#include "Player.h"
#include "GameSys.h"


using namespace std;

//konstruktor bez argumentow z lista inicjalizacyjna z "randomowymi" parametrami
Mob::Mob():health(roll(40,80)),damage(roll(10,90)),defense(roll(1,10)){ 
}

void Mob::getMob() {
	cout << "Mob health " << health << endl;
	cout << "Mob damage " << damage << endl;
	cout << "Mob defense " << defense << endl;
}

void Mob::attack(Player &play) {
	cout << "Atak moba";
}

//konstruktor bez argumentow z lista inizjalizacyjna w sklad ktorej wchodzi konstruktor klasy bazowej oraz argument klasy poœredniej
Troll::Troll():Mob(), name("Trol") {

}

void Troll::getTroll() {
	cout << "Troll health " << health << endl;
	cout << "Troll damage " << damage << endl;
	cout << "Troll defense " << defense << endl;
	cout << "Troll name " << name << endl;
}

void Troll::attack(GameSys &game, Level &lev,Troll &tr, Player &play) {

	int expPoints;
	int initiative;
	int k = 0;
	int strikeTroll; //parametr opisuje ile obrazen "przeszlo przez obrone"
	int strikePlayer; //parametr opisuje ile obrazen "przeszlo przez obrone"
	int luckTroll; //parametr randomowy do walki
	int luckPlayer; //parametr randomowy do walki
	luckTroll = roll(-20, 20);
	luckPlayer = roll(-15, 20);
	lev.show(lev, play);
	cout << "Podszedles blizej do Trola i oceniasz jego cechy na: " << endl;
	cout << "Atak: " << tr.damage << endl;
	cout << "Obrona: " << tr.defense << endl;
	cout << "Zycie: " << tr.health << endl;
	cout << endl;
	cout << "Nacisnij klawisz aby kontynuowac walke ... " << endl;
	_getch();
	initiative = roll(1, 100);
	do {
			lev.show(lev, play);
			
			strikePlayer = tr.defense - play.damagePlayer - luckPlayer;
			if (strikePlayer > 1) tr.health = tr.health-1;
			if (strikePlayer < 1) tr.health = tr.health + strikePlayer;
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << "Wymierzasz cios i zadajesz "; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); 
			if (strikePlayer > 1) { strikePlayer = 1;  cout << 1; }
			if (strikePlayer < 1) cout << -strikePlayer;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << " pktow obrazen." << endl;
			
			if (tr.health < 1) {
			expPoints = roll(1, 20);
			cout << "Brawo !! Trol zostal zabity. " << endl;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << "Otrzymujesz ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout << expPoints;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << " punktow doswiadczenia." << endl;
			play.exp = play.exp + expPoints;
			cout << endl << "Nacisnij dowolny klawisz aby kontynuowac gre."; break; 
			}
			if (tr.health > 1) { 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << "Trolowi pozostalo ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				cout << tr.health;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << " pktow zycia." << endl;
			}
			
			strikeTroll = play.defensePlayer - tr.damage - luckTroll;
			if (strikeTroll > 1) play.health = play.health-1;
			if (strikeTroll < 1) play.health = play.health + strikeTroll;

			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << "Trol nie zostaje dluzny i zabiera Tobie ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			if (strikeTroll > 1) { strikeTroll = 1;  cout << 1; }
			if (strikeTroll < 1) cout << -strikeTroll;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << " zycia.";
			cout << endl;
			
			if (play.health < 1) { 
			cout << endl;
			cout << "Trol zadal Tobie smiertelny cios !!! " << endl << endl << "KONIEC GRY !!! "; 
			game.goToMainMenu = 1;
			k = 1;
			break; 
			}
			
			if (play.health > 1) { 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << "Pozostalo Tobie ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				cout << play.health;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << " pktow zycia.";
				cout << endl << endl;
			}
			cout << "Nacisnij dowolny klawisz aby kontynuwac walke ... " << endl;
			_getch();
			
			} while (1);
	if(k==1){
		game.goToMainMenu = 1;
	}
}

Dragon::Dragon():Mob(), name("Dragon"){

}


void Dragon::attack(GameSys &game, Level &lev, Dragon &dr, Player &play) {

	int answer2;
	int expPoints;
	int initiative;
	int k = 0;
	lev.show(lev, play);
	cout << "Podszedles blizej do Smoka i oceniasz jego cechy na: " << endl;
	cout << "Atak: 1000" << endl;
	cout << "Obrona: 1000" << endl;
	cout << "Zycie: 1000" << endl;
	cout << endl;
	cout << "Nacisnij klawisz aby kontynuowac walke ... " << endl;
	_getch();
	do {
		lev.show(lev, play);
		cout << "Po pierwsze gratulacje, ze tutaj dotarles - odezwal sie smok." << endl;
		cout << "Znudzily mnie juz skomlenia i trzaski kosci konajacych bohaterow, dlatego dla rozrywki zaproponuje Tobie inna gre." << endl;
		cout << "Zadam Tobie 2 zagadki. Jezeli na nie odpowiesz - przezyjesz i bedziesz mogl wszystkim rozpowiadac, ze zabiles smoka. Jako dowod mojej kleski przekaze Tobie pierscien z mojego skarbca." << endl;
		cout << "Jezeli nie odpowiesz, domyslasz sie pewnie swojego losu mizernego losu. Nie dodaje nawet, ze kol ratunkowych nie ma ..." << endl;
		cout << "No to zaczynajmy. Pierwsza zagadka." << endl;
		cout << endl;
		cout << "Nacisnij klawisz aby kontynuowac ... " << endl;
		_getch();
		lev.show(lev, play);
		cout << "5 pajakow lapie 5 much w ciagu 5 godzin. Ile much lapie 100 pajakow w ciagu 100 godzin?  " << endl;
		cout << "Odpowiedz: ";
		game.verify<int>(answer2);
		if (answer2 == 2000) {
			cout << "No, no, no. Kto by pomyslal. Nie wygladasz na takiego bystrzaka. Wiesz co jednak zatesknilem troche za skomleniem niewinnych. Ta zagadka powinna zalatwic sprawe." << endl;
			cout << endl;
			cout << "Nacisnij klawisz aby kontynuowac ... " << endl;
			
			_getch();
			lev.show(lev, play);
		}
		else {
			cout << "No to jednak przyjdzie mi dzisiaj posluchac skomlenia. " << endl;
			cout << "Kula ognia w mgnieniu oka pochlonela Twoje cale cialo i obrociles sie w pyl ...   " << endl;
			cout << endl;
			cout << "KONIEC GRY !!" << endl;
			cout << "Nacisnij klawisz aby kontynuowac ... " << endl;
			
			
			game.goToMainMenu = 1;
			break;
		}

			cout << "3 koty zlapaly 3 myszy w ciagu 3 minut. Jak dlugo zajmie 999 kotom zlapanie 999 myszy" << endl;
			cout << "Odpowiedz: ";
			game.verify<int>(answer2);
			if (answer2 == 3) {
				cout << "Chyle czola. Niespodziewalem sie, ze przyjdzie mi spotkac, nie dosc, ze tak odwaznego, to jeszcze tak madrego wojownika. " << endl;
				cout << "Prosze o to pierscien. Od dzisiaj mozesz nazywac siebie Pogromca Smokow !  " << endl;
				cout << endl;
				cout << "Nacisnij klawisz aby kontynuowac ... " << endl;
				
				_getch();
				lev.show(lev, play);
				cout << "GRATULACJE !!! UKONCZYLES GRE !!!" << endl;
				cout << "Nowy platny dodatek juz niedlugo !!!" << endl;
				cout << endl;
				cout << "Nacisnij klawisz, aby kontynuowac, Pogromco Smoka ... " << endl;
				
				break;
			}
			else {
				cout << "A byles tak blisko ...  " << endl;
				cout << "Kula ognia w mgnieniu oka pochlonela Twoje cale cialo i obrociles sie w pyl ...   " << endl;
				cout << "KONIEC GRY !!" << endl;
				game.goToMainMenu = 1;
				break;
			}
		} while (1);
	game.goToMainMenu = 1;
	}



void Dragon::getDragon() {
	cout << "Dragon health " << health << endl;
	cout << "Dragon damage " << damage << endl;
	cout << "Dragon defense " << defense << endl;
	cout << "Dragon name " << name << endl;
	
}