#include "hareDialogue.h"
#include <iostream>

using namespace std;

hareDialogue::hareDialogue() : NPCDefeated(false), talkedTo(false) {
}

void hareDialogue::startDialogue(Player& player) {
	Item* hands = player.getWeaponSlot();


	if (talkedTo == false) {
		talkedTo = true;

		if (hands) {
			string handName = hands->getName();
			if (handName == "carrot") {
				dtree.init_hare();
			}
		}
		else
		{
			cout << "Hunfry" << endl;
		}
	}
		else if (talkedTo == true) {
			cout << "The hare twitches its nose at you." << endl;
		}
	}


void hareDialogue::defeatedDialogue() {
	cout << "You defeeated the hare." << endl;
}


