#pragma once

#include <iostream>
#include <random>
#include <chrono>

using namespace std;

class Character {
public:
	string name;
	string element;
	double health;
	double strength;
	double intelligence;
	double willpower;
	double armor;
	int level;
	double xp;

	//constructor
	Character() : name(" "), element("water"), health(0), strength(0), intelligence(0), willpower(0), armor(0), level(0), xp(0) {}
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

	double getHealth() {
		return health;
	}

	string getName() {
		return name;
	}

};


