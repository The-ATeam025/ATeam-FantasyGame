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
	string magicWord;

	// Before reading the answer using std::getline, we clear the input buffer to ensure no leftover characters (like newline from a previous input) are read as the answer.
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (talkedTo == false) {
		talkedTo = true;
		cout << "As you cautiously step onto the creaking wooden planks of the bridge, a deep, growling voice erupts, stopping you in your tracks. \nThen suddenly, the short hairy creature walks towards you, almost scaring you to death. " << endl;
		cout << endl;
		cout << "Troll: WHAT'S THE MAGIC WORD?!?!" << endl;
		std::getline(std::cin, magicWord); //reads the whole line of input, including spaces, until it encounters a newline character.


		//code to accept the user answer and transform answer into all lowercase, no matter how it is written.
		std::string answerLowerCase = magicWord; // Make a copy of answer
		std::transform(answerLowerCase.begin(), answerLowerCase.end(), answerLowerCase.begin(),
			[](unsigned char c) { return std::tolower(c); });

		if (answerLowerCase == "rathad") {
			talkedTo = true;
			convoCompleted = true;
			dtree.init_troll(player);
		}
		else {
			cout << "Troll: Wrong! Go away and come back when you learn something!!" << endl; //If word is given and is incorrect (and the player does not leave the bridge location)
		}
	}
	else if ((talkedTo == true) && (convoCompleted == false)) ///If word is given and is incorrect (and the player does leaves the bridge location and comes back)
	{
		cout << "The troll is leaning against the bridge and tapping its foot impatiently." << endl;
		cout << endl;
		cout << "Troll:" << randomResponse() << endl;
		cin >> magicWord;
		if (magicWord == "rathad") {
			talkedTo = true;
			convoCompleted = true;
			dtree.init_troll(player);
		}
		else {
			cout << "Troll: Wrong again!" << endl;

		}
	}
	//
	else if (convoCompleted == true) //If the troll has talked to the player before (magic word was correct), but the player had to go back to get the vine 
	{


		Item* hands = player.getWeaponSlot();
		if (hands && hands->getName() == "Vine") //if player is holding vine
		{
			//INIT NEW CODE
			dtree.consequences(6, player);
		}
		else
		{
			cout << "Troll: I don't see you holding your materials!" << endl;

		}
	}

}

void trollDialogue::defeatedDialogue() {
	cout << "You defeated the troll." << endl;
}
string trollDialogue::randomResponse()
{
	string reply;

	string a = "Well? What's the word?";
	string b = "You again? What's the word?";
	string c = "Are you slow? What's the word?";
	string d = "I'm starting to get sick of looking at you. What's the word?";

	int random = 1 + (rand() % 4);

	if (random == 1)
	{
		reply = a;
	}
	if (random == 2)
	{
		reply = b;
	}
	if (random == 3)
	{
		reply = c;
	}
	if (random == 4)
	{
		reply = d;
	}

	return reply;
}

bool trollDialogue::checkConvoCompleted()
{
	if (convoCompleted == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}