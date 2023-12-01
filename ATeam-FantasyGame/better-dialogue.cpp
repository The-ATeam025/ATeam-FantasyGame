#include "better-dialogue.h"
#include <iostream>
#include <string>
//both files below are used for riddle answers, making sure there is no case sensitivity
#include <algorithm> // for std::transform
#include <cctype>    // for ::tolower
#include <limits> // The <limits> header is included to allow us to use std::numeric_limits. This is necessary for the std::cin.ignore line, to ensure we clear out the entire input buffer.

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

void DialogueTree::init_fairy(Player& player) //set up tree with dialogue, make this one virtual?
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


	performDialogue(player, message);
}

void DialogueTree::init_cat(Player& player) //set up tree with dialogue, make this one virtual?
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


	performDialogue(player, message);
}

void DialogueTree::init_hare(Player& player) //set up tree with dialogue, make this one virtual?
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


	performDialogue(player, message);
}

void DialogueTree::init_troll(Player& player) //set up tree with dialogue, make this one virtual?
{
	string message = "Troll: Speak Correctly!"; //custom error message for this character interaction--the warning the player gets if the input is invalid 

	cout << "As you approach the bridge, you see nothing but just mossy wooden planks. As you cautiously step onto the creaking wooden planks of the bridge, a deep, growling voice erupts from beneath it, stopping you in your tracks. Everything went quiet... then suddenly, a short hairy creature jumps out from under the bridge. " << endl;

	cout << endl;

	DialogueNode* node0 = new DialogueNode("Troll: Who ventures upon my guarded bridge without my sanction ? This is no place for the unwatched and unguarded! Declare your purpose, lest you wander into peril under my watch!");
	DialogueNode* node1 = new DialogueNode("Troll: Ah, a polite one! Trespass is not taken lightly here, but your manners show honor. Tell me, why does your journey bring you to this bridge?");
	DialogueNode* node2 = new DialogueNode("Troll: A sacred site, you say? The lands beyond this bridge hold many ancient secrets and hallowed grounds. Few are those who tread such paths with pure intent. ");
	DialogueNode* node3 = new DialogueNode("Troll: Ah.. I see. The only way to cross is by saying the magic word! ");
	DialogueNode* node4 = new DialogueNode("Troll: In a rush, eh?");
	DialogueNode* node5 = new DialogueNode("Troll: I hope they are. You only have a few chances..");
	DialogueNode* node6 = new DialogueNode("Troll: If you tell me the magic word.. I will let you pass.");



	//Node 0
	node0->dialogueOptions.push_back(DialogueOption("My path leads me to a sacred site known to lie beyond this bridge.", 1, node2));
	node0->dialogueOptions.push_back(DialogueOption("I'm so sorry. I didn't mean to trespass.", 0, node1));
	dialogueNodes.push_back(node0);

	//Node 1
	node1->dialogueOptions.push_back(DialogueOption("I am looking for Aine.", 2, node3));
	node1->dialogueOptions.push_back(DialogueOption("Seems very serious. I am on a journey to get back home.", 0, node3));
	dialogueNodes.push_back(node1);

	//Node 2
	node2->dialogueOptions.push_back(DialogueOption("I assure you, my intentions are pure and my respect for the sacred is profound. ", 2, node5));
	node2->dialogueOptions.push_back(DialogueOption("Can you just let me pass through? I'm kind of in a hurry.", 1, node4));
	dialogueNodes.push_back(node2);

	//Node 3
	node3->dialogueOptions.push_back(DialogueOption("Magic word? I don't have time for this! ", 2, node6));
	node3->dialogueOptions.push_back(DialogueOption("At least it's not a riddle.", 1, node4));
	dialogueNodes.push_back(node3);

	//node 4
	node4->dialogueOptions.push_back(DialogueOption("Nevermind.. I'll come back with the magic word. ", 4, nullptr));
	node4->dialogueOptions.push_back(DialogueOption("I think I know it!", 5, nullptr));
	dialogueNodes.push_back(node4);

	//node 5
	node5->dialogueOptions.push_back(DialogueOption("Can you give me a hint? ", 0, node6));
	node5->dialogueOptions.push_back(DialogueOption("It's worth a shot.", 5, node6));
	dialogueNodes.push_back(node5);

	//node 6
	node6->dialogueOptions.push_back(DialogueOption("Sorry... I don't know the magic word. I'll come back later.", 4, nullptr));
	node6->dialogueOptions.push_back(DialogueOption("I think I know it.", 5, nullptr));
	dialogueNodes.push_back(node6);


	performDialogue(player, message);
}

void DialogueTree::destroyTree()
{
	for (int i = 0; i < dialogueNodes.size(); i++)
	{
		delete dialogueNodes[i];
	}
	dialogueNodes.clear();
}

int DialogueTree::consequences(int code, Player& player)
{
	/*
	* CASE 0: Fairy eats you 
	* CASE 1: Fairy gives you a hard riddle
	* CASE 2: Fairy gives you an easy riddle
	* CASE 3: Cat outro text
	* CASE 4: Hare does not give you a riddle
	* CASE 5: Hare gives you a riddle
	* CASE 6: Troll doesn't tell you how to tie bridle
	* CASE 7: Troll tells you how to tie bridle from vine
	*/




	string answer;
	switch (code) {
	
	case 0:
		system("CLS");
		player.setShouldRestartGame(true);
		cout << "The fairy shakes its head in disappointment. 'I hate rude people.', it says. It eats you whole" << endl;

		return code;
	case 1:

		cout << "Insolent mortal! For your lack of manners, you will get a hard riddle and only three attempts to guess it." << endl;
		cout << "What is both the beginning of eternity and the end of time and space, the beginning of every end and the end of every place?" << endl;
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
		system("CLS");
		player.setShouldRestartGame(true);
		cout << "You have messed up the riddle. The fairies keep you imprisoned forever." << endl;

		return code;

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
		system("CLS");
		player.setShouldRestartGame(true);
		cout << "You have messed up the riddle. The fairies keep you imprisoned forever." << endl;

		break;
	case 3:
		cout << "CAT: Look, I don't care about you, or your home. I just like to watch you mortals try to to escape, it's so fun. Here's a hint: stop by the castle, you're gonna need a Celtic cross for later." << endl;
		cout << endl;
		cout << "Before you can say anything, the cat turns around and melts into the shadows, leaving you questioning your own sanity. Did it really talk to you?" << endl;
		return code;
		break;
	case 4:
		cout << "\nThe Hare did not like your answer." << endl;
		cout << "\nHare: No riddle, eh? Fine then. You will regret this." << endl;
		return code;
		break;
	case 5:
		cout << "Hare: I will give you a simple riddle for being such a nice human. If you answer correctly within three tries, I'll give you advice to help you along the way!" << endl;
		cout << endl;
		cout << "I sit in the sun and stand in the shade," << endl;
		cout << "I follow no orders, but I often parade." << endl;
		cout << "When I'm high, I'm admired far and wide," << endl;
		cout << "When I'm low, I hide as if shy.\nWhat am I ?" << endl;
		cout << endl;

		// Before reading the answer using std::getline, we clear the input buffer to ensure no leftover characters (like newline from a previous input) are read as the answer.
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		for (int i = 2; i >= 0; i--)
		{
			cout << "Answer wisely. If you do not answer, you could miss out on important information! " << endl;
			cout << endl;


			std::getline(std::cin, answer); //reads the whole line of input, including spaces, until it encounters a newline character.
			

			//code to accept the user answer and transform answer into all lowercase, no matter how it is written.
			std::string answerLowerCase = answer; // Make a copy of answer
			std::transform(answerLowerCase.begin(), answerLowerCase.end(), answerLowerCase.begin(),
				[](unsigned char c) { return std::tolower(c); });


			if (answerLowerCase != "shadow")
			{
				cout << "Incorrect. You have " << i << " tries left." << endl;
			}
			else
			{
				cout << "Hare: That's correct. For your reward, I'll give you a little information." << endl;
				cout << "Rathad! If you want to leave the underworld, you will need to speak to Aine, the most beautiful goddess there is." << endl;
				cout << "She will help you get out of here. While you're there, mind asking her on a date for me? I get really shy around her." << endl << endl;
				return code;

			}
		}
		system("CLS");
		cout << "You have messed up the riddle. You have lost the chance at getting important information!" << endl;
		cout << "The Hare shakes his head in disbelief and hops away." << endl;
		cout << endl;
		return code;

		break;
	case 6:
		cout << "Troll: You want me to show you how to tie a bridle without anything to tie? Get outta here!" << endl;
		break;
	case 7: 

		cout << "Troll: First, lay the vine out flat on the ground" << endl;
		cout << "Hint : What keyboard character looks like a flat piece of rope or string on a ground? The vine is long so enter it twice." << endl;

		do {
			// Before reading the answer using std::getline, we clear the input buffer to ensure no leftover characters (like newline from a previous input) are read as the answer.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			getline(cin, answer);


			if (answer != "__")
			{
				cout << "Not quite!" << endl;
			}

		} while (rope != "__");


		cout << "Troll: Next, tie the left end of the rope into a circle." << endl;
		cout << "Hint: Make a LARGE circle on the left side, and don�t forget to leave some leftover rope on the right side!" << endl;

		do {
			// Before reading the answer using std::getline, we clear the input buffer to ensure no leftover characters (like newline from a previous input) are read as the answer.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			getline(cin, answer);

			if (answer != "O_")
			{
				cout << "Not quite!" << endl;
			}

		} while (answer != "O_");


		cout << "Troll: Lastly, tie the right end of the rope into a smaller circle, and leave some vine at the end so you can lead the kelpie. " << endl;
		cout << "Hint : Add a SMALL circle and a SMALL amount of rope on the right side. " << endl;

		do {
			// Before reading the answer using std::getline, we clear the input buffer to ensure no leftover characters (like newline from a previous input) are read as the answer.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			getline(cin, answer);

			if (answer != "O_o-")
			{
				cout << "Not quite!" << endl;
			}

		} while (answer != "O_o-");

		cout << "Troll: It's a bit odd looking, but it'll get the job done. Not sure why you'd want to, but this should pacify that beastly kelpie." << endl;

		return code;
		break;

	default:
		cout << "Error: no code given" << endl;
		break;
	};
	return code;
}
int DialogueTree::performDialogue(Player& player, string message)
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
			consequences(code, player);
			return code;
		}
		currentNode = currentNode->dialogueOptions[input].nextNode;

		cout << endl;


	}
}

