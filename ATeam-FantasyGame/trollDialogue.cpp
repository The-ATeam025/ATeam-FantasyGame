#include "trollDialogue.h"
#include <iostream>
//both files below are used for riddle answers, making sure there is no case sensitivity
#include <algorithm> // for std::transform
#include <cctype>    // for ::tolower
#include <limits> // The <limits> header is included to allow us to use std::numeric_limits. This is necessary for the std::cin.ignore line, to ensure we clear out the entire input buffer.


using namespace std;

trollDialogue::trollDialogue() : NPCDefeated(false), talkedTo(false) {
}

void trollDialogue::startDialogue(Player& player) {
	string magicWord = " ";

	// Before reading the answer using std::getline, we clear the input buffer to ensure no leftover characters (like newline from a previous input) are read as the answer.
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (talkedTo == false) {
		cout << "As you cautiously step onto the creaking wooden planks of the bridge, a deep, growling voice erupts, stopping you in your tracks. Then suddenly, the short hairy creature walks towards you, almost scaring you to death. " << endl;
		
	}
	cout << "Troll: WHAT'S THE MAGIC WORD?!?!" << endl;

	std::getline(std::cin, magicWord);	//reads the whole line of input, including spaces, until it encounters a newline character.

	//code to accept the user answer and transform answer into all lowercase, no matter how it is written.
	std::string answerLowerCase = magicWord; // Make a copy of answer
	std::transform(answerLowerCase.begin(), answerLowerCase.end(), answerLowerCase.begin(),
		[](unsigned char c) { return std::tolower(c); });

	if (answerLowerCase != "rathad") {
		cout << "The troll stand there with his arms crossed. Waiting for an answer." << endl;
		if (talkedTo == true) {
			cout << "The troll looks in your direction, but it has nothing else to tell you" << endl;
		}
	}
	else {
		talkedTo = true;
		dtree.init_troll(player);
	}
}

void trollDialogue::defeatedDialogue() {
	cout << "You defeated the troll." << endl;
}