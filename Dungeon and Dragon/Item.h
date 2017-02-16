#pragma once
#include <iostream>
#include <string>
#include "Level.h"

using namespace std;

class Item {
protected:

	friend int roll(int x, int y);
	int weight;
	int price;
	int durability;
	
public:
	Item();
	void set_item(Item &it);

};

class Sword:public Item {
private:
	friend class Player;
	string name;
	int damage;
	

public:
	Sword(); 
	void sword_info(Sword sw1); //metoda wyswietlajaca parametry danego miecza
	
};

class Armor :public Item {
private:
	friend class Player;
	string name;
	int defense;
public:
	Armor();
	void armor_info(Armor ar1); //metoda wyswietlajaca parametry danej zbroi

};

class Elixir : public Item {
private:
	friend class Player;
	string name;
	int hp_reg;
public:
	Elixir();
	void elixir_info(Elixir el1); //metoda wyswietlajaca parametry danego eliksira	
};