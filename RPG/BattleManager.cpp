#include "BattleManager.h"


void BattleManager::startBattle(Character& player, Character& enemy) {
	while (player.getHealth() > 0 && enemy.getHealth() > 0) {
		cout << "--------------------------------" << endl;
		cout << player.getName() << "'s Health: " << player.getHealth() << " ** " << enemy.getName() << "'s Health: " << enemy.getHealth();
		cout << "\nPlayer's Turn" << endl;
		cout << "Press A to Attack or D to Defend" << endl;
		char user_choice;
		if (player.status == "Froze" || player.status == "Broken" || player.status == "Paralyzed") {
			cout << player.name << " is " << player.status << ". " << player.name << " loses a turn." << endl << endl;
		}
		else {
			cin >> user_choice;
			if (user_choice == 'a') {
				player.attack(enemy);
				if (enemy.getHealth() <= 0) {
					cout << player.getName() << " wins!" << endl;
					break;
				}
			}
			if (user_choice == 'd') {
				player.defend(player);
			}
		}
		player.statusReturn();

		if (enemy.status == "Frozen" || enemy.status == "Broken" || enemy.status == "Paralyzed") {
			cout << enemy.name << " is " << enemy.status << ". " << enemy.name << " loses a turn." << endl << endl;
		}
		else {
			cout << "--------------------------------" << endl;
			cout << "Player's Health: " << player.getHealth() << " ** Enemy's Health " << enemy.getHealth();
			cout << "\nEnemy's Turn" << endl;
			enemy.attack(player);

			if (player.getHealth() <= 0) {
				cout << enemy.getName() << " wins!" << endl;
				break;
			}
		}
		enemy.statusReturn();
	}
}