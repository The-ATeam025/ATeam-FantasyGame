#include "fairyDialogue.h"
#include <iostream>

using namespace std;

fairyDialogue::fairyDialogue() : NPCDefeated(false) {
}

void fairyDialogue::startDialogue(Player& player) {
	dtree.init();
}

void fairyDialogue::defeatedDialogue() {
	cout << "You defeeated the fairies" << endl;
}