  #include "dialogue.h"
#include <iostream>
#include <string>

using namespace std;
string choice; //user input
Dialogue::Dialogue()
{
}

void Dialogue::CatIntro()
{
	cout << "As you emerge in this new and altered version of the garden, the atmosphere feels denser and the surroundings take on an otherworldly hue. Amidst" << endl;
	cout << "the mystical setting, your gaze is drawn to a striking sight - a towering black cat, standing upright on its hind legs, seemingly unfazed by your" << endl;
	cout << "sudden appearance. Unsure of what to do next, you start walking towards it, wondering if it has some sort of spine condition causing it to stand" << endl;
	cout<<" like that. Your attempts at applying logic to your situation fail as the cat opens its mouth and starts speaking to you in a human voice." << endl;

	Node1();
}

/* Every Node method follows the same format. It displays dialogue spoken by the cat character, and allows the user to choose between two responses. 
Depending on the response, the appropriate next node is called. This forms a rudimentary dialogue tree. */


void Dialogue::Node1()                                                 
{
	cout << endl;
	cout << endl;
	cout << "CAT: Hello there. Lost, aren't ya?" << endl;
	cout << endl;

	cout << "CHOOSE YOUR RESPONSE" << endl;
	cout << endl;
	cout << "1. Who are you?" << endl;
	cout << "2. Where am I?";
	cout << endl;
	getline(cin, choice);

	
	/*
	Input verificaiton takes the first character of the input string and compares to '1' or '2'. Forces uses to re-enter input if not equal to 1 or 2,
	or if more than 1 character has been entered
	*/
	while ((choice[0] != '1') && (choice[0] != '2') || (choice.length() >= 2)) 
	{
		cout << "Cat got your tongue? Enter 1 or 2 to reply." << endl;
		getline(cin, choice);
	}
	


	if (choice == "1")
	{
		cout << "YOU: Who are you?" << endl;
		Node2();
	}
	else
		cout << "YOU: Where am I?" << endl;
		Node3();

}

void Dialogue::Node2()
{
	cout << endl;
	cout << endl;
	cout << "CAT: Names hold a lot of power here. Won't say mine to a stranger. And you are?" << endl;
	cout << endl;
	cout << "CHOOSE YOUR RESPONSE" << endl;
	cout << endl;
	cout << "1. I probably shouldn't tell you mine either, then." << endl;
	cout << "2. Where is 'here', exactly?";
	cout << endl;
	getline(cin, choice);


	while ((choice[0] != '1') && (choice[0] != '2') || (choice.length() >= 2))
	{
		cout << "Cat got your tongue? Enter 1 or 2 to reply." << endl;
		getline(cin, choice);
	}


	if (choice == "1")
	{
		cout << "YOU: I probably shouldn't tell you mine either, then." << endl;
		Node4();
	}
	else
		cout << "YOU: Where is 'here', exactly?" << endl;
		Node3(); //explain otherworld in detail



}

void Dialogue::Node3()
{
	cout << endl;
	cout << endl;
	cout << "CAT: The Otherworld, obviously. The last guy actually didn't make it this far." << endl;
	cout << endl;
	cout << "CHOOSE YOUR RESPONSE" << endl;
	cout << endl;
	cout << "1. Wait, what do you mean,'didn't make it'?" << endl;
	cout << "2. The Otherworld? What do you mean?" << endl;
	cout << endl;
	getline(cin, choice);


	while ((choice[0] != '1') && (choice[0] != '2') || (choice.length() >= 2))
	{
		cout << "Cat got your tongue? Enter 1 or 2 to reply." << endl;
		getline(cin, choice);
	}


	if (choice == "1")
	{
		cout << "YOU: Wait, what do you mean,'didn't make it'?" << endl;
		Node5();
	}
	else
	{
		cout << "YOU: The Otherworld? What do you mean?" << endl;
		Node6();
	}

}

void Dialogue::Node4()
{
	cout << endl;
	cout << endl;
	cout << "CAT: That's smart. You might survive this place after all." << endl;
	cout << endl;
	cout << "CHOOSE YOUR RESPONSE" << endl;
	cout << endl;
	cout << "1. Look, you keep saying that. What do you mean, 'this place?'" << endl;
	cout << "2. Wait...survive?";
	cout << endl;
	getline(cin, choice);


	while ((choice[0] != '1') && (choice[0] != '2') || (choice.length() >= 2))
	{
		cout << "Cat got your tongue? Enter 1 or 2 to reply." << endl;
		getline(cin, choice);
	}


	if (choice == "1")
	{
		cout << "YOU: Look, you keep saying that. What do you mean, 'this place?'" << endl;
		Node3();
	}
	else
	{
		cout << "YOU: Wait...survive?" << endl;
		Node5();
	}

}

void Dialogue::Node5()
{
	cout << endl;
	cout << endl;
	cout << "CAT: It's a dangerous place, the Otherworld. Suprising amount of people end up here, but much fewer get to leave." << endl;
	cout << endl;
	cout << "CHOOSE YOUR RESPONSE" << endl;
	cout << endl;
	cout << "1. Well, that sounds ominous. What exactly is the Otherworld?" << endl;
	cout << "2. You're freaking me out, I've heard enough. How do I get out of here?";
	cout << endl;
	getline(cin, choice);


	while ((choice[0] != '1') && (choice[0] != '2') || (choice.length() >= 2))
	{
		cout << "Cat got your tongue? Enter 1 or 2 to reply." << endl;
		getline(cin, choice);
	}


	if (choice == "1")
	{
		cout << "YOU: Well, that sounds ominous. What exactly is the Otherworld?" << endl;
		Node6(); //explain otherworld in detail
	}
	else
	{
		cout << "YOU: You're freaking me out, I've heard enough. How do I get out of here?" << endl;
		Node7();
	}

}

void Dialogue::Node6()
{
	cout << endl;
	cout << endl;
	cout << "CAT: It's a cursed fairy realm, essentially." << endl;
	cout << endl;
	cout << "CHOOSE YOUR RESPONSE" << endl;
	cout << endl;
	cout << "1. That sounds horrible. How do I leave?" << endl;
	cout << "2. ...Why am I in a cursed fairy realm? I was just on vacation.";
	cout << endl;
	getline(cin, choice);


	while ((choice[0] != '1') && (choice[0] != '2') || (choice.length() >= 2))
	{
		cout << "Cat got your tongue? Enter 1 or 2 to reply." << endl;
		getline(cin, choice);
	}


	if (choice == "1")
	{
		cout << "YOU: That sounds horrible. How do I leave?" << endl;
		Node7();
	}
	else
	{
		cout << "YOU: . ...Why am I in a cursed fairy realm? I was just on vacation." << endl;
		Node7();
	}

	

}

void Dialogue::Node7()
{
	cout << endl;
	cout << endl;
	cout << "CAT: You got here by stepping in a mushroom circle. You'll get out pretty much the same way, if you don't get killed or trapped first." << endl;
	cout << endl;
	cout << "CHOOSE YOUR RESPONSE" << endl;
	cout << endl;
	cout << "1. How do I do that? Why are you telling me all this?" << endl;
	cout << "2. Man, I'm scared and I want to go home. Can you just help me leave?";
	cout << endl;
	getline(cin, choice);


	while ((choice[0] != '1') && (choice[0] != '2') || (choice.length() >= 2))
	{
		cout << "Cat got your tongue? Enter 1 or 2 to reply." << endl;
		getline(cin, choice);
	}


	if (choice == "1")
	{
		cout << "YOU:  How do I do that? Why are you telling me all this?" << endl;
		CatOutro();
	}
	else
	{
		cout << "YOU: Man, I'm scared and I want to go home. Can you just help me leave?" << endl;
		CatOutro();
	}
		
	
	
};

void Dialogue::CatOutro()
{
	cout << endl;
	cout << endl;
	cout << "CAT: Look, I don't care about you, or your home. I just like to watch you mortals try to to escape, it's so fun. Here's a hint: stop by the castle, you're gonna need a Celtic cross for later." << endl;
	cout << endl;
	cout << "Before you can say anything, the cat turns around and melts into the shadows, leaving you questioning your own sanity. Did it really talk to you?" << endl;
	cout << endl;
	
}
