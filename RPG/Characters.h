#pragma once

#include <iostream>

using namespace std;

class Character {
public:
	string name;
	double health;
	double strength;
	double intelligence;
	double willpower;
	double armor;
	int level;
	double xp;

	//constructor
	Character() : health(0), strength(0), intelligence(0), willpower(0), armor(0), level(0), xp(0) {}
	virtual ~Character() = default;


};

class Mage : public Character {
public:

	double mana;

	Mage() : mana(100) {
		name = "Unnamed Mage";
		health = 100;
		strength = 30;
		intelligence = 80;
		willpower = 70;
		armor = 0;
		level = 0;
		xp = 0;
	}

	void fireball() {
		if (mana >= 10) {
			cout << name << " casts fireball" << endl;
			mana -= 10;
		}
		else {
			cout << "Not enough Mana" << endl;
		}
	}
	
};
