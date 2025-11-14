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
		willpower = 6;
		fortitude = 3;
		armor = 2;
		status = "Normal";
		level = 0;
		xp = 0;
	}

	void attack(Character& target) {
		double damage;
		if (element == "fire") {
			damage = intelligence * 1.5 - target.armor * 0.5;
			cout << name << " casts fireball at " << target.name << endl;
			cout << Character::name << " does " << damage << " damage to " << target.name << endl;
			target.health -= damage;
			//chance for burning
			if (statusChance(target)) {
				target.status = "Burning";
			}
			statusEffect(target);
		}
		else if (element == "water") {
			damage = intelligence * 2 - target.armor * 0.5;
			cout << name << " casts tidal wave at " << target.name << endl;
			cout << Character::name << " does " << damage << " damage to " << target.name << endl;
			target.health -= damage;
		}
		else if (element == "earth") {
			damage = intelligence * 1.3 - target.armor * 0.5;
			cout << name << " casts rock throw at " << target.name << endl;
			cout << Character::name << " does " << damage << " damage to " << target.name << endl;
			target.health -= damage;
			//chance to break limb
			if (statusChance(target)) {
				target.status = "Broken";
			}
			statusEffect(target);
		}
		else if (element == "wind") {
			damage = intelligence * 2 - target.armor * 0.5;
			cout << name << " casts wind whip at " << target.name << endl;
			cout << Character::name << " does " << damage << " damage to " << target.name << endl;
			target.health -= damage;
		}
		else if (element == "ice") {
			damage = intelligence * 1.3 - target.armor * 0.5;
			cout << name << " casts freeze at " << target.name << endl;
			cout << Character::name << " does " << damage << " damage to " << target.name << endl;
			target.health -= damage;
			//chance to freeze
			if (statusChance(target)) {
				target.status = "Frozen";
			}
			statusEffect(target);
		}
		else if (element == "lightning") {
			damage = intelligence * 1.3 - target.armor * 0.5;
			cout << name << " casts shock at " << target.name << endl;
			cout << Character::name << " does " << damage << " damage to " << target.name << endl;
			target.health -= damage;
			//chance to paralyze
			if (statusChance(target)) {
				target.status = "Paralyzed";
			}
			statusEffect(target);
		}
	}
	void defend(Character& target) {
		cout << name << " casts a protective barrier" << endl;
		//protects your character and one other for a certain type of damage linked to your element
	}
	 
};
