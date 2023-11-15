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

void DialogueTree::init_fairy() //set up tree with dialogue, make this one virtual?
{
	string message = "It's not very polite to mumble. "; //custom error message for this character interaction--the warning the player gets if the input is invalid 

	cout << "As you enter the room, you see a group of figures around a table laden with all sorts of delicious foods and wines. This is odd, because the rest of the room is dusty and abandoned, but what is even stranger than the food are the people seated there. " << endl;

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


	performDialogue(message);
}

void DialogueTree::init_cat() //set up tree with dialogue, make this one virtual?
{
	string message = "Cat got your tongue? "; //custom error message for this character interaction--the warning the player gets if the input is invalid 

	cout << "As you emerge in this new and altered version of the garden, the atmosphere feels denser and the surroundings take on an otherworldly hue. Amidst" << endl;
	cout << "the mystical setting, your gaze is drawn to a striking sight - a towering black cat, standing upright on its hind legs, seemingly unfazed by your" << endl;
	cout << "sudden appearance. Unsure of what to do next, you start walking towards it, wondering if it has some sort of spine condition causing it to stand" << endl;
	cout << " like that. Your attempts at applying logic to your situation fail as the cat opens its mouth and starts speaking to you in a human voice." << endl;
	cout << endl;

	DialogueNode* node0 = new DialogueNode("CAT: Hello there. Lost, aren't ya?");
	DialogueNode* node1 = new DialogueNode("CAT: Names hold a lot of power here. Won't say mine to a stranger. And you are?");
	DialogueNode* node2 = new DialogueNode("CAT: The Otherworld, obviously. The last guy actually didn't make it this far.");
	DialogueNode* node3 = new DialogueNode("CAT: That's smart. You might survive this place after all.");
	DialogueNode* node4 = new DialogueNode("CAT: It's a dangerous place, the Otherworld. Suprising amount of people end up here, but much fewer get to leave. ");
	DialogueNode* node5 = new DialogueNode("CAT: It's a cursed fairy realm, essentially.");
	DialogueNode* node6 = new DialogueNode("CAT: You got here by stepping in a mushroom circle. You'll get out pretty much the same way, if you don't get killed or trapped first.");


	//Node 0
	node0->dialogueOptions.push_back(DialogueOption("Who are you?", 3, node1));
	node0->dialogueOptions.push_back(DialogueOption("Where am I?", 3, node2));
	dialogueNodes.push_back(node0);

	//Node 1
	node1->dialogueOptions.push_back(DialogueOption("I probably shouldn't tell you mine either, then.", 3, node3));
	node1->dialogueOptions.push_back(DialogueOption("Where is 'here', exactly?", 3, node2));
	dialogueNodes.push_back(node1);

	//Node 2
	node2->dialogueOptions.push_back(DialogueOption("Wait, what do you mean,'didn't make it'?", 3, node4));
	node2->dialogueOptions.push_back(DialogueOption("The Otherworld? What do you mean?", 3, node5));
	dialogueNodes.push_back(node2);

	//Node 3
	node3->dialogueOptions.push_back(DialogueOption("Look, you keep saying that. What do you mean, 'this place?'", 3, node2));
	node3->dialogueOptions.push_back(DialogueOption("Wait...survive?", 3, node4));
	dialogueNodes.push_back(node3);

	//Node 4
	node4->dialogueOptions.push_back(DialogueOption("Well, that sounds ominous. What exactly is the Otherworld?", 3, node5));
	node4->dialogueOptions.push_back(DialogueOption("You're freaking me out, I've heard enough. How do I get out of here?", 3, node6));
	dialogueNodes.push_back(node4);

	//Node 5
	node5->dialogueOptions.push_back(DialogueOption("That sounds horrible. How do I leave?", 3, node6));
	node5->dialogueOptions.push_back(DialogueOption(" ...Why am I in a cursed fairy realm? I was just on vacation.", 3, node6));
	dialogueNodes.push_back(node5);

	//Node 6
	node6->dialogueOptions.push_back(DialogueOption("How do I do that? Why are you telling me all this?", 3, nullptr));
	node6->dialogueOptions.push_back(DialogueOption("Man, I'm scared and I want to go home. Can you just help me leave?", 3, nullptr));
	dialogueNodes.push_back(node6);


	performDialogue(message); 
}

void DialogueTree::init_hare() //set up tree with dialogue, make this one virtual?
{
	string message = "Hare: Sorry, what did you say?"; //custom error message for this character interaction--the warning the player gets if the input is invalid 

	cout << "As you hold out the carrot, the hare approaches it and eats it from your hand. After crunching down on it for a few minutes, it begins to speak. " << endl;

	cout << endl;

	DialogueNode* node0 = new DialogueNode("Hare: That was a good carrot. You're an odd-looking creature. Are you a wingless fairy, or a hornless troll?");
	DialogueNode* node1 = new DialogueNode("Hare: You're definitely from the boring world if you think I'm odd,");
	DialogueNode* node2 = new DialogueNode("Hare: Ha! I see you've dealt with the Fae already. They sure love their riddles. ");
	DialogueNode* node3 = new DialogueNode("Hare: We sure do.No magic over there.What do you people even do for fun, taxes ? ");
	DialogueNode* node4 = new DialogueNode("Hare: I do love a good battle of wits, but I won't force you to listen to mine. Offer's up, though.");
	DialogueNode* node5 = new DialogueNode("Hare: I don't care about you, so I don't care what you say. If you tick me off I'll just hop away.");
	DialogueNode* node6 = new DialogueNode("Hare: You humans are always going on about going home. It's no fun if I just tell you how. I'll give you a hint though.");



	//Node 0
	node0->dialogueOptions.push_back(DialogueOption("Yes. I'm a wingless fairy. Obviously. God, more fucking riddles.", 1, node2));
	node0->dialogueOptions.push_back(DialogueOption("I've never been called odd by a one eyed bunny rabbit before.", 0, node1));
	dialogueNodes.push_back(node0);

	//Node 1
	node1->dialogueOptions.push_back(DialogueOption("The boring world? Is that what you call where I'm from?", 2, node3));
	node1->dialogueOptions.push_back(DialogueOption("You can call my world boring, but at least people there don't offer me riddles threateningly.", 0, node3));
	dialogueNodes.push_back(node1);

	//Node 2
	node2->dialogueOptions.push_back(DialogueOption("They really do. They were also sticklers about politeness. Are you like that too? ", 2, node5));
	node2->dialogueOptions.push_back(DialogueOption("Let me guess, you're going to offer me a riddle too?.", 1, node4));
	dialogueNodes.push_back(node2);

	//Node 3
	node3->dialogueOptions.push_back(DialogueOption("I admit, it can get pretty mundane over there, but I do want to go home. ", 2, node6));
	node3->dialogueOptions.push_back(DialogueOption("Definitely not as many riddles as you guys. I feel like everyone here either talks in riddles, or gives me one!", 1, node4));
	dialogueNodes.push_back(node3);

	//node 4
	node4->dialogueOptions.push_back(DialogueOption("I think I'll pass. ", 4, nullptr));
	node4->dialogueOptions.push_back(DialogueOption("God, might as well. Another one won't hurt, as long as it helps me get home.", 5, nullptr));
	dialogueNodes.push_back(node4);

	//node 5
	node5->dialogueOptions.push_back(DialogueOption("That's fair, could you please help me get home? ", 0, node6));
	node5->dialogueOptions.push_back(DialogueOption("I don't care about you either, but I just want to get back home.", 5, node6));
	dialogueNodes.push_back(node5);

	//node 6
	node6->dialogueOptions.push_back(DialogueOption("Not another riddle. I think I'll pass. ", 4, nullptr));
	node6->dialogueOptions.push_back(DialogueOption("Let me guess, another riddle? I'll take what I can get.", 5, nullptr));
	dialogueNodes.push_back(node6);


	performDialogue(message);
}

void DialogueTree::destroyTree()
{
	for (int i = 0; i < dialogueNodes.size(); i++)
	{
		delete dialogueNodes[i];
	}
	dialogueNodes.clear();
}

int DialogueTree::consequences_all_creatures(int code)
{
	string answer;
	switch (code) {
		//Consequences for fairy: it eats you because you decline a riddle
	case 0:
		cout << "The fairy shakes its head in dissapointment. 'I hate rude people.', it says. It eats you whole." << endl;
		cout << endl;
		system("pause");
		cout << "Game will now close" << endl;
		cout << endl;
		exit(0);
		
		break;
	case 1:

		cout << "Fairy: You were nice, so you get an easy riddle. Your answer will be one word. Still, you only have three tries." << endl;
		cout << "What has hands, but can't hold anything?" << endl;
		cout << endl;
		for (int i = 2; i >= 0; i--)
		{
			cout << "What is your answer? Answer wisely, lest you anger the fairies." << endl;
			cout << endl;
			cin >> answer;

			if ((answer != "e") && (answer != "E"))
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
	case 3:
		cout << "CAT: Look, I don't care about you, or your home. I just like to watch you mortals try to to escape, it's so fun. Here's a hint: stop by the castle, you're gonna need a Celtic cross for later." << endl;
		cout << endl;
		cout << "Before you can say anything, the cat turns around and melts into the shadows, leaving you questioning your own sanity. Did it really talk to you?" << endl;
		return code;
		break;

	default:
		cout << "Error: no code given" << endl;
		break;
	};
	return code;
}
int DialogueTree::performDialogue(string message)
{
	string errorMessage = message;

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
			cout << errorMessage << "Enter 1 or 2" << endl << endl;
		}
		input--;
		if (currentNode->dialogueOptions[input].nextNode == nullptr)
		{
			//cout << "reee";
			int code= currentNode ->dialogueOptions[input].returnCode;
			consequences_all_creatures(code);
			return code;
		}
		currentNode = currentNode->dialogueOptions[input].nextNode;

		cout << endl;


	}
}

