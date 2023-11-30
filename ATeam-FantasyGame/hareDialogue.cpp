#include "hareDialogue.h"
#include <iostream>

using namespace std;

hareDialogue::hareDialogue() : NPCDefeated(false), talkedTo(false) {
}

void hareDialogue::startDialogue(Player& player) {
	if (talkedTo == false) {
		talkedTo = true;
		dtree.init_fairy(player);
	}
	else if (talkedTo == true) {
		cout << "The fairies look in your direction, but they have nothing else to tell you" << endl;
	}
}



void hareDialogue::defeatedDialogue() {
	cout << "You defeeated the hare." << endl;
}


