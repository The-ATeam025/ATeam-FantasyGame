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
	DialogueNode* node1 = new DialogueNode("I don't want to talk");
	DialogueNode* node2 = new DialogueNode("I have a quest for you");
	DialogueNode* node3 = new DialogueNode("You will get money");
	DialogueNode* node4 = new DialogueNode("Collect flowers");

	//Node 0
	node0->dialogueOptions.push_back(DialogueOption("Sure, I would love to", 0, node1));
	node0->dialogueOptions.push_back(DialogueOption("Uhh...I guess, yeah", 0, node2));
	dialogueNodes.push_back(node0);

	//Node 1
	node1->dialogueOptions.push_back(DialogueOption("Aww", 0, nullptr));
	dialogueNodes.push_back(node1);

	//Node 2
	node2->dialogueOptions.push_back(DialogueOption("Bye", 0, nullptr));
	node2->dialogueOptions.push_back(DialogueOption("What is it", 0, node4));
	node2->dialogueOptions.push_back(DialogueOption("Pay", 0, node3));
	dialogueNodes.push_back(node2);

	//Node 3
	node2->dialogueOptions.push_back(DialogueOption("What is it", 0, node4));
	node2->dialogueOptions.push_back(DialogueOption("Ew", 0, nullptr));
	dialogueNodes.push_back(node3);

	//Node 4
	node2->dialogueOptions.push_back(DialogueOption("What is it", 0, node4));
	node2->dialogueOptions.push_back(DialogueOption("Ew", 0, nullptr));
	dialogueNodes.push_back(node3);
}

void DialogueTree::destroyTree()
{
	for (int i = 0; i < dialogueNodes.size(); i++)
	{
		delete dialogueNodes[i];
	}
	dialogueNodes.clear();
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
				return currentNode->dialogueOptions[input].returnCode;
			}
			currentNode = currentNode->dialogueOptions[input].nextNode;
		}

		cout << endl;


	}
}