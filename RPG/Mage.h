#pragma once

#include "Characters.h"

class Mage : public Character {
public:

	Mage() {
		name = "Mage";
		element = getRandomElement();
		health = 100;
		strength = 3;
		intelligence = 8;
		willpower = 7;
		armor = 2;
		level = 0;
		xp = 0;
	}

	void attack(Character& target) {
		if (element == "fire") {
			cout << name << " casts fireball at " << target.name << endl;
			target.health -= intelligence * 1.5;
			//chance to cause fire damage for 2 turns enemy willpower will play a role
		}
		else if (element == "water") {
			cout << name << " casts tidal wave at " << target.name << endl;
			target.health -= intelligence * 2;
		}
		else if (element == "earth") {
			cout << name << " casts rock throw at " << target.name << endl;
			target.health -= intelligence * 1.3;
			//chance to break limb for a turn
		}
		else if (element == "wind") {
			cout << name << " casts wind whip at " << target.name << endl;
			target.health -= intelligence * 2;
		}
		else if (element == "ice") {
			cout << name << " casts freeze at " << target.name << endl;
			target.health -= intelligence * 1.3;
			//chance to freeze for a turn
		}
		else if (element == "lightning") {
			cout << name << " casts shock at " << target.name << endl;
			target.health -= intelligence * 1.3;
			//chance to paralyze for a turn
		}
	}
	void defend(Character& target) {
		cout << name << " casts a protective barrier" << endl;
		//protects your character and one other for a certain type of damage linked to your element
	}

};
