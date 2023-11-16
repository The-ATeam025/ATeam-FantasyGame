#include "fairyDialogue.h"
#include <iostream>

using namespace std;

fairyDialogue::fairyDialogue() : NPCDefeated(false), talkedTo(false) {
}

void fairyDialogue::startDialogue(Player& player) {
	if (talkedTo == false) {
		talkedTo = true;
		dtree.init_fairy(player);
	}
	else if (talkedTo == true) {
		cout << "The fairies look in your direction, but they have nothing else to tell you" << endl;
	}
}

void fairyDialogue::defeatedDialogue() {
	cout << "You defeeated the fairies" << endl;
}