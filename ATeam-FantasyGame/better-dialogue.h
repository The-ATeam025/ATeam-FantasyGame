#pragma once

#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;

class DialogueNode;

class DialogueOption
{
public:

	DialogueOption(string Text, int ReturnCode, DialogueNode* NextNode);
	string text; //possible response
	DialogueNode* nextNode; //pointer to appropriate DialogueNode object
	int returnCode; //if applicable, this will return 
};


class DialogueNode

{
public:
	DialogueNode(string Text);
	string text;  //this is what the NPC says
	vector <DialogueOption> dialogueOptions; //this will hold the possible responses for what the NPC says

};


class DialogueTree
{
public:
	int ending;
	DialogueTree();
	void init_fairy(Player& player); //start fairy dialogue
	void init_cat(Player& player); //start cat dialogue
	void init_hare(Player& player); //start hare dialogue if given carrot
	void init_hare2(Player& player); //start hare dialogue if given dandelion
	void init_troll(Player& player); //start troll dialogue
	void init_goddess_1(Player& player); //start first goddess dialogue
	void init_goddess_2(Player& player);
	void destroyTree(); //saves memory be deleting all nodes 
	int performDialogue(Player& player, string errorMessage);
	int consequences(int code, Player& player);
	void tieBridle(Player& player);



private:
	vector <DialogueNode*> dialogueNodes;

};

