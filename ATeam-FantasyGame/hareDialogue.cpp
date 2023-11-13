#include "hareDialogue.h"
#include <iostream>

using namespace std;

hareDialogue::hareDialogue() : NPCDefeated(false), talkedTo(false) {
}

void hareDialogue::startDialogue(Player& player) {
	if (talkedTo == false) {
		talkedTo = true;
		dtree.init_hare();
	}
	else if (talkedTo == true) {
		cout << "The hare looks in your direction, but it has nothing else to tell you." << endl;
	}
}

void hareDialogue::defeatedDialogue() {
	cout << "You defeeated the hare." << endl;
}