#pragma once
#include "Characters.h"
#include "Mage.h"
#include "Knight.h"

using namespace std;

class BattleManager {
public:
	void startBattle(Character& Player, Character& enemy);
};
