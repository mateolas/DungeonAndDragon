#include <iostream>
#include "Item.h"

using namespace std;

Item::Item() { 
	weight = roll(5, 15);
	price = roll(5, 15);
	durability = roll(5, 15);
}

void Item::set_item(Item &it) {
	it.weight = roll(5, 15);
	it.price = roll(5, 20);
	it.durability = roll(10, 40);

}

//konstruktor bez argumentow i listy inicjalizacyjnej, z randomowymi parametrami miecza
Sword::Sword(){
	weight = roll(4, 10);
	damage = roll(10, 30);
	price = roll(3, 16) + damage/3 - weight/2;
	durability = roll(10, 50);
	name = "Miecz";

}

void Sword::sword_info(Sword sw1) {
	cout << "Znalazles miecz !! Przygladasz sie mu i po chwili oceniasz, jego cechy na: " << endl;
	cout << "Waga: " << sw1.weight << endl;
	cout << "Obrazenia: +" << sw1.damage << endl;
	cout << "Wytrzymalosc: " << sw1.durability << endl;
	cout << "Wartosc: " << sw1.price;
}

//konstruktor bez argumentow i listy inicjalizacyjnej, z randomowymi parametrami zbroi
Armor::Armor() {
	weight = roll(20, 50);
	defense = roll(30, 80);
	price = roll(30, 40) + defense/ 3 - weight / 2;
	durability = roll(40, 100);
	name = "Zbroja";
}

void Armor::armor_info(Armor ar1) {
	cout << "Znalazles zbroje !! Przygladasz jej sie i po chwili oceniasz, jej cechy na: " << endl;
	cout << "Waga: " << ar1.weight << endl;
	cout << "Obrona: +" << ar1.defense << endl;
	cout << "Wytrzymalosc: " << ar1.durability << endl;
	cout << "Wartosc: " << ar1.price;
}

//konstruktor bez argumentow i listy inicjalizacyjnej, z randomowymi parametrami eliksira
Elixir::Elixir(){
	weight = roll(1, 5);
	hp_reg = roll(20, 50);
	price = roll(3, 16) + hp_reg / 3;
	name = "Eliksir";
}

void Elixir ::elixir_info(Elixir el1) {
	cout << "Znalazles eliksir !! Zregeneruje Tobie " << hp_reg << " punktow zdrowia. ";
}
