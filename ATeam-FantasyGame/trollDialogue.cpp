#include "trollDialogue.h"
#include <iostream>

using namespace std;

trollDialogue::trollDialogue() : NPCDefeated(false), talkedTo(false) {
}

void trollDialogue::startDialogue(Player& player) {
	if (talkedTo == false) {
		talkedTo = true;
		dtree.init_fairy(player);
	}
	else if (talkedTo == true) {
		cout << "The troll looks in your direction, but it have nothing else to tell you" << endl;
	}
}

void trollDialogue::defeatedDialogue() {
    cout << "You defeated the troll." << endl;
}