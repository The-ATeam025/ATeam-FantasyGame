#include "trollDialogue.h"
#include <iostream>

using namespace std;

trollDialogue::trollDialogue() : NPCDefeated(false), talkedTo(false) {
}


void trollDialogue::startDialogue(Player& player) {
	string magicWord;


	if (talkedTo == false) {
		talkedTo = true;
		cout << "As you cautiously step onto the creaking wooden planks of the bridge, a deep, growling voice erupts, stopping you in your tracks. Then suddenly, the short hairy creature walks towards you, almost scaring you to death. " << endl;
		cout << "Troll: WHAT'S THE MAGIC WORD?!?!" << endl;
		cin >> magicWord;
		if (magicWord == "rathad") {
			talkedTo = true;
			convoCompleted = true;
			dtree.init_troll(player);
		}
		else {
			cout << "Troll: Wrong! Go away and come back when you learn something!!" << endl;
		}
	}
	else if((talkedTo==true) && (convoCompleted==false))
	{
		cout << "The troll is leaning against the bridge and tapping its foot impatiently." << endl;
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
	else if (convoCompleted==true)
	{
		cout << "Vine test!" << endl;
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