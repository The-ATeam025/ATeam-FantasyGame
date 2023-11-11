#pragma once

#include <iostream>
#include <vector>
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
	void init_fairy(); //start fairy dialogue
	void init_cat(); //start cat dialogue

	void destroyTree(); //saves memory be deleting all nodes 
	int performDialogue(string errorMessage);
	int consequences(int code);




private:
	vector <DialogueNode*> dialogueNodes;

};

