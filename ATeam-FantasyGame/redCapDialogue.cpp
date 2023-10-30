#include "redCapDialogue.h"
#include <iostream>

using namespace std;

void redCapDialogue::startDialogue(Player& player){
	Item* hands = player.getWeaponSlot();
	string handName = hands -> getName();
	if (handName == "Celtic Cross") {
		cout << "You raise the Celtic Cross and point it at the Redcap, who seems shocked at this action." << endl << endl;
		cout << "The Redcap hisses at you 'What is it that you hold there, Mortal?'" << endl;
		cout << "The malevolent creature recoils in agony, its grotesque features contorted with pain. 'N - no, it can't be...'" << endl << endl;
		cout << "As the Celtic cross's holy power envelops you, the Redcap begins to melt like a nightmare fading at dawn, dissolving into nothingness, its malicious laughter silenced forever." << endl;
		NPCDefeated = true;
	}
	else {
		cout << "The Redcap's malevolent grin widens as it locks eyes with you, its gaze filled with sinister intent. It takes slow, deliberate steps towards you." << endl << endl;
		cout << "An uneasy feeling settles in as the Redcap approaches, and you decide not to go any closer, maintaining a safe distance." << endl;
	}
}

void redCapDialogue::defeatedDialogue() {
	cout << "All that remains of the Redcap is a rusty key, which now lies on the floor" << endl;
}