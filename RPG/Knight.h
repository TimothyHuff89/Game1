#pragma once

#include "Characters.h"

class Knight : public Character {
public:

	Knight() {
		name = "Knight";
		element = getRandomElement();
		health = 120;
		strength = 8;
		intelligence = 4;
		willpower = 7;
		armor = 4;
		level = 0;
		xp = 0;
	}

	void attack(Character& target) {
		cout << name << " Slashes at " << target.name << endl;
		target.health -= strength * 1.2;
	}

	void defend(Character& target) {
		cout << name << " Shields " << target.name << endl;
		//protects your character and one other with extra shield armor
	}
};
