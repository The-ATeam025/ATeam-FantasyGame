#include "GoddessDialogue.h"
#include <iostream>

using namespace std;

GoddessDialogue::GoddessDialogue() : NPCDefeated(false), itemGiven(false) {
}

void GoddessDialogue::startDialogue(Player& player) {
	Item* hands = player.getWeaponSlot();

	if (hands && hands->getName() == "tooth") {
		player.removeItem("hands");
		player.removeItemFromInventory(hands);
		itemGiven = true;
		dtree.init_goddess_2(player);
	}
	else if (itemGiven == false) {
		dtree.init_goddess_1(player);
	}
}

void GoddessDialogue::defeatedDialogue() {
	cout << "You defeeated the fairies" << endl;
}