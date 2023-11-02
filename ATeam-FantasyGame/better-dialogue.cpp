#include "better-dialogue.h"
#include <iostream>
#include <string>

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
	cout << "As you eneter the room, you see a group of figures around a table laden with all sorts of delicious foods and wines. This is odd, because the rest of the room is dusty and abandoned, but what is even stranger than the food are the people seated there. " << endl;

	cout << "A group of humanoid creatures with shimmering wings are enjoying the feast, but there is a sinister air that contrasts with their beautiful appearance.You get the feeling that you do not want to mess with them. As you stand hesitantly in the corner, one fairy notices you." << endl;

	cout << endl;

	DialogueNode* node0 = new DialogueNode("Fairy: Greetings! Care to join us for a feast?");
	DialogueNode* node1 = new DialogueNode("Fairy: You seem nervous. Don't you think we look nice?");
	DialogueNode* node2 = new DialogueNode("Fairy: You're polite for a human. I invite you to a game of riddles, as is customary. ");
	DialogueNode* node3 = new DialogueNode("Fairy: That's not very nice. I will offer one more time. Riddle? ");

	//Node 0
	node0->dialogueOptions.push_back(DialogueOption("Sure, I would love to", 1, node2));
	node0->dialogueOptions.push_back(DialogueOption("Uhh...I guess, yeah", 0, node1));
	dialogueNodes.push_back(node0);

	//Node 1
	node1->dialogueOptions.push_back(DialogueOption("No, you look nice, I'm just new here.", 2, node2));
	node1->dialogueOptions.push_back(DialogueOption("You're a bit unsettling to look at, to be honest.", 0, node3));
	dialogueNodes.push_back(node1);

	//Node 2
	node2->dialogueOptions.push_back(DialogueOption("Thank you, what is the riddle?",2, nullptr));
	node2->dialogueOptions.push_back(DialogueOption("Who plays games before dinner? I don't want to do this.", 1, node3));
	dialogueNodes.push_back(node2);

	//Node 3
	node3->dialogueOptions.push_back(DialogueOption("Ugh fine, I'll take your stupid riddle.", 1, nullptr));
	node3->dialogueOptions.push_back(DialogueOption("You're being weird. I don't want the riddle", 0, nullptr));
	dialogueNodes.push_back(node3);


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
	string answer;
	switch (code) {
	case 0:
		cout << "The fairy shakes its head in dissapointment. 'I hate rude people.', it says. It eats you whole." << endl;
		cout << endl;
		system("pause");
		cout << "Game will now close" << endl;
		cout << endl;
		exit(0);
		
		break;
	case 1:
		cout << "The fairy shakes its head, grinning menacingly." << endl;
		cout << "Fairy: Can't stand rude people. For your insolence, we will make you guess a hard riddle. You have three tries." << endl;
		cout << "What is the beginning of eternity, the end of time and space, the beginning of every end, and the end of every place?" << endl;

		cout << endl;
		for (int i = 2; i >= 0; i--)
		{
			cout << "What is your answer? Answer wisely, lest you anger the fairies." << endl;
			cout << endl;
			cin >> answer;

			if ((answer != "E") && (answer != "e"))
			{
				cout << "Incorrect. You have " << i << " tries left." << endl;
			}
			else
			{
				cout << "That's correct. For your reward, I'll give you a little information" << endl;
				cout << "If you havent met him already, the Redcap in the dungeon is a nasty fellow." << endl;
				cout << "I have heard if you hold up a Celtic Cross to him though, he does not fare so well." << endl << endl;
				return code;
			}
			
			break;

		}
		cout << endl;
		cout << "You have messed up the riddle. The fairies keep you imprisoned forever." << endl;
		system("pause");
		cout << "Game will now close" << endl;
		cout << endl;
		exit(0);
		//code = 0;

		break;
	case 2:
		cout << "Fairy: You were nice, so you get an easy riddle. Your answer will be one word. Still, you only have three tries." << endl;
		cout << "What has hands, but can't hold anything?" << endl;
		cout << endl;
		for (int i = 2; i >= 0; i--)
		{
			cout << "What is your answer? Answer wisely, lest you anger the fairies." << endl;
			cout << endl;
			cin >> answer;

			if ((answer != "clock") && (answer != "Clock") && (answer != "CLOCK"))
			{
				cout << "Incorrect. You have " << i << " tries left." << endl;
			}
			else
			{
				cout << "That's correct. For your reward, I'll give you a little information" << endl;
				cout << "If you havent met him already, the Redcap in the dungeon is a nasty fellow." << endl;
				cout << "I have heard if you hold up a Celtic Cross to him though, he does not fare so well." << endl << endl;
				return code;
			}
		}
		cout << endl;
		cout << "You have messed up the riddle. The fairies keep you imprisoned forever." << endl;
		system("pause");
		cout << "Game will now close" << endl;
		cout << endl;
		exit(0);
		//code = 0;

		break;

	default:
		cout << "Error: no code given" << endl;
		break;
	};
	return code;
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

		while (!(cin >> input) || cin.peek() != '\n' || input < 0 || input > currentNode->dialogueOptions.size()) {
			// Handle non-numeric input or input with spaces
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter a non-spaced, numeric value listed." << endl << endl;
		}
		input--;
		if (currentNode->dialogueOptions[input].nextNode == nullptr)
		{
			//cout << "reee";
			int code= currentNode ->dialogueOptions[input].returnCode;
			consequences(code);
			return code;
		}
		currentNode = currentNode->dialogueOptions[input].nextNode;

		cout << endl;


	}
}

