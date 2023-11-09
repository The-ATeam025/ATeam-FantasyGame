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
	void init(Player& player); //start 
	void destroyTree(); //saves memory be deleting all nodes 
	int performDialogue(Player& player);
	int consequences(int code, Player& player);




private:
	vector <DialogueNode*> dialogueNodes;

};
