#include "trollDialogue.h"
#include <iostream>

using namespace std;

trollDialogue::trollDialogue() : NPCDefeated(false), talkedTo(false) {
}

void trollDialogue::startDialogue(Player& player) {
	string magicWord = " ";

	if (talkedTo == false) {
		cout << "As you cautiously step onto the creaking wooden planks of the bridge, a deep, growling voice erupts, stopping you in your tracks. Then suddenly, the short hairy creature walks towards you, almost scaring you to death. " << endl;
		cout << "Troll: WHAT'S THE MAGIC WORD?!?!" << endl;
	}

	cin >> magicWord;
	if (magicWord == "rathad") {
		talkedTo = true;
		dtree.init_troll(player);
	}
	else {
		cout << "The troll stand there with his arms crossed. Waiting for an answer." << endl;
		if (talkedTo == true) {
			cout << "The troll looks in your direction, but it have nothing else to tell you" << endl;
		}
	}
}

void trollDialogue::defeatedDialogue() {
	cout << "You defeated the troll." << endl;
}