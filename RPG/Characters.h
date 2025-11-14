#pragma once

#include <iostream>
#include <random>
#include <chrono>

using namespace std;

class Character {
private:

public:
	string name;
	string element;
	double health;
	double strength;
	double intelligence;
	double willpower;
	double fortitude;
	double armor;
	string status = "Normal";
	int level;
	double xp;

	//constructor
	Character() : name(" "), element("water"), health(0), strength(0), intelligence(0), willpower(0), fortitude(0), armor(0), level(0), xp(0) {}
	virtual ~Character() = default;

	virtual void attack(Character& target) = 0;
	virtual void defend(Character& target) = 0;

	string getRandomElement() {
		static const vector<string> elements = {
			"fire", "water", "earth", "wind", "ice", "lightning"
		};

		// Seed with current time
		unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		default_random_engine rng(seed);
		uniform_int_distribution<int> dist(0, elements.size() - 1);

		return elements[dist(rng)];
	}
	void setName() {
		cout << "\nHow shalt thine Character be named: " << endl;
		cin >> name;
	}

	double getHealth() const{
		return health;
	}

	string getName() const{
		return name;
	}

	bool statusChance(const Character& target) const{
		double statusChance;
		if (intelligence >= strength) {
			statusChance = (intelligence * willpower - target.fortitude * target.armor);
		}
		if (strength > intelligence) {
			statusChance = (strength * willpower - target.fortitude * target.armor);
		}

		unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		default_random_engine rng(random_device{}());
		uniform_int_distribution<int> dist(0, 100);
		int roll = dist(rng);

		return statusChance >= roll;
	}

	double statusEffect(Character& character) const {
		if (character.status == "Burning" || character.status == "Bleeding") {
			if (intelligence >= strength) {
				cout << "\n" << character.name << " is " << character.status << endl;
				cout << character.name << " loses " << intelligence * 1.2 << " health from" << character.status << endl;
				return character.health -= intelligence * 1.2;
			}
			else if (strength >= intelligence) {
				cout << "\n" << character.name << " is " << character.status << endl;
				cout << character.name << " loses " << strength * 1.2 << " health from " << character.status << endl;
				return character.health -= strength * 1.2;
			}
		}
		else if (character.status == "Froze" || character.status == "Paralyzed" || character.status == "Broken") {
			cout << "\n" << character.name << " is " << character.status << endl;
		}
	}
	string statusReturn() {
		if (status != "Normal") {
			unsigned seed = chrono::system_clock::now().time_since_epoch().count();
			default_random_engine rng(random_device{}());
			uniform_int_distribution<int> dist(0, 1);
			int roll = dist(rng);
			if (roll > 0) {
				cout << name << " is no longer " << status << endl;
				status = "Normal";
			}
		}
		return status;
	}


};


