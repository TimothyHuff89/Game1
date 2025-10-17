#include "BattleManager.h"


void BattleManager::startBattle(Character& player, Character& enemy) {
	while (player.getHealth() > 0 && enemy.getHealth() > 0) {
		cout << "\nPlayer's Turn" << endl;
		cout << "Press A to Attack or D to Defend" << endl;
		char user_choice;
		cin >> user_choice;
		if (user_choice == 'a') {
			player.attack(enemy);
			cout << enemy.getName() << "'s Health: " << enemy.getHealth() << endl;
			if (enemy.getHealth() <= 0) {
				cout << player.getName() << " wins" << endl;
				break;
			}
		}
		if (user_choice == 'd') {
			player.defend(player);
		}
		cout << "\nEnemy's Turn" << endl;
		enemy.attack(player);
		cout << player.getName() << "'s Health: " << player.getHealth() << endl;

		if (player.getHealth() <= 0) {
			cout << enemy.getName() << " wins" << endl;
		}
	}
}