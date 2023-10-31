#include "better-dialogue.h"
using namespace std;

DialogueNode::DialogueNode(string Text)
{
	text = Text;
}

DialogueOption::DialogueOption(string Text, int ReturnCode, DialogueNode* NextNode)
{

	text = Text;
	returnCode = ReturnCode;
	nextNode = NextNode;

}

DialogueTree::DialogueTree() //constructor
{

}

void DialogueTree::init() //set up tree with dialogue, make this one virtual?
{
	DialogueNode* node0 = new DialogueNode("Greetings! Care to join us for a feast?");
	DialogueNode* node1 = new DialogueNode("You seem nervous. Don't you think we look nice?");
	DialogueNode* node2 = new DialogueNode("You're polite for a human. I invite you to a game of riddles, as is customary. ");
	DialogueNode* node3 = new DialogueNode("That's not very nice. Let's play a game. Riddle? ");
	DialogueNode* node4 = new DialogueNode("That's ok. Riddle ? ");

	//Node 0
	node0->dialogueOptions.push_back(DialogueOption("Sure, I would love to", 1, node2));
	node0->dialogueOptions.push_back(DialogueOption("Uhh...I guess, yeah", 0, node1));
	dialogueNodes.push_back(node0);

	//Node 1
	node1->dialogueOptions.push_back(DialogueOption("No, you look nice, I'm just new here.", 0, node2));
	node1->dialogueOptions.push_back(DialogueOption("You're a bit unsettling to look at, to be honest.", 0, nullptr));
	dialogueNodes.push_back(node1);

	//Node 2
	node2->dialogueOptions.push_back(DialogueOption("Thank you, what is the riddle?", 1, nullptr));
	node2->dialogueOptions.push_back(DialogueOption("Who plays games before dinner? I don't want to do this.", 0, node3));
	dialogueNodes.push_back(node2);

	//Node 3
	node3->dialogueOptions.push_back(DialogueOption("tttt", 0, node4));
	node3->dialogueOptions.push_back(DialogueOption("aaa", 0, nullptr));
	dialogueNodes.push_back(node3);

	//Node 4
	node4->dialogueOptions.push_back(DialogueOption("Sure", 0, nullptr));
	node4->dialogueOptions.push_back(DialogueOption("You're weird.", 0, nullptr));
	dialogueNodes.push_back(node4);

	performDialogue();
}

void DialogueTree::destroyTree()
{
	for (int i = 0; i < dialogueNodes.size(); i++)
	{
		delete dialogueNodes[i];
	}
	dialogueNodes.clear();
}

int DialogueTree::consequences(int code)
{
	
	if (code == 0)
	{
		cout << "You were rude" << endl;
	}
	else
		cout << "You were polite" << endl;
	return 0;
}
int DialogueTree::performDialogue()
{
	if (dialogueNodes.empty())
	{
		return -1;
	}

	DialogueNode* currentNode = dialogueNodes[0];

	while (true)
	{
		cout << currentNode->text << endl;

		for (int i = 0; i < currentNode->dialogueOptions.size(); i++)
		{
			cout << i + 1 << ": " << currentNode->dialogueOptions[i].text << endl;
		}



		cout << endl;
		int input;
		cin >> input;
		input--;

		if (input<0 || input>currentNode->dialogueOptions.size())
		{
			cout << "invalid" << endl;
		}
		else
		{
			if (currentNode->dialogueOptions[input].nextNode == nullptr)
			{
				//cout << "reee";
				int code= currentNode ->dialogueOptions[input].returnCode;
				consequences(code);
				return 1;
			}
			currentNode = currentNode->dialogueOptions[input].nextNode;
		}

		cout << endl;


	}
}

