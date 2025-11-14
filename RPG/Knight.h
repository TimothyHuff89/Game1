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
		willpower = 4;
		fortitude = 5;
		armor = 4;
		status = "Normal";
		level = 0;
		xp = 0;
	}

	void attack(Character& target) {
		double damage = strength * 1.2 - target.armor * 0.5;
		cout << name << " Slashes at " << target.name << endl;
		cout << Character::name << " does " << damage << " damage to " << target.name << endl;
		target.health -= damage;
		if (statusChance(target)) {
			target.status = "Bleeding";
		}
		statusEffect(target);
	}
 
	void defend(Character& target) {
		cout << name << " Shields " << target.name << endl;
		//protects your character and one other with extra shield armor
	}
};
