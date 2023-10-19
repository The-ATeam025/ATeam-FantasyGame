#include "dialogue.h"
#include <iostream>

using namespace std;

Dialogue::Dialogue()
{
}

void Dialogue::CatIntro()
{
	cout << "As you emerge in this new and altered version of the garden, the atmosphere feels denser" << endl;
	cout << " and the surroundings take on an otherworldly hue. Amidst the mystical setting, your gaze is drawn to a striking sight" << endl;
	cout << " - a towering black cat, standing upright on its hind legs, seemingly unfazed by your sudden appearance. To your suprise, it starts speaking to you." << endl;

	Node1();
}

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
	cin >> choice;

	if (choice == 1)
	{
		Node2();
	}
	else
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
	cout << "1. Probably shouldn't tell you mine either, then." << endl;
	cout << "2. Where is 'here', exactly?";
	cout << endl;
	cin >> choice;

	if (choice == 1)
	{
		Node4();
	}
	else
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
	cout << "1. What do you mean, 'didn't make it;?" << endl;
	cout << "2. What do you mean, the Otherworld?";
	cout << endl;
	cin >> choice;

	if (choice == 1)
	{
		Node5();
	}
	else
		Node5();

}

void Dialogue::Node4()
{
	cout << endl;
	cout << endl;
	cout << "CAT: Smart. You might survive this place after all." << endl;
	cout << endl;
	cout << "CHOOSE YOUR RESPONSE" << endl;
	cout << endl;
	cout << "1. What do you mean, 'this place?'" << endl;
	cout << "2. Wait...survive?";
	cout << endl;
	cin >> choice;

	if (choice == 1)
	{
		Node3();
	}
	else
		Node5();

}

void Dialogue::Node5()
{
	cout << endl;
	cout << endl;
	cout << "CAT: It's a dangerous place, the Otherworld. You don't really hear about it for a reason." << endl;
	cout << endl;
	cout << "CHOOSE YOUR RESPONSE" << endl;
	cout << endl;
	cout << "1. Jesus. What exactly is the Otherworld?'" << endl;
	cout << "2. I've heard enough. How do I get out of here?";
	cout << endl;
	cin >> choice;

	if (choice == 1)
	{
		Node6(); //explain otherworld in detail
	}
	else
		Node7();

}

void Dialogue::Node6()
{
	cout << endl;
	cout << endl;
	cout << "CAT: Fairy hell, basically." << endl;
	cout << endl;
	cout << "CHOOSE YOUR RESPONSE" << endl;
	cout << endl;
	cout << "1. That sounds horrible. How do I leave??'" << endl;
	cout << "2. And I'm just stuck here? Why am I here?";
	cout << endl;
	cin >> choice;

	Node7();

}

void Dialogue::Node7()
{
	cout << endl;
	cout << endl;
	cout << "CAT: You got here by stepping in a mushroom circle. You'll get out pretty much the same way, if you don't get killed or trapped first." << endl;
	cout << endl;
	cout << "CHOOSE YOUR RESPONSE" << endl;
	cout << endl;
	cout << "1. That sounds horrible. How do I leave??'" << endl;
	cout << "2. And I'm just stuck here? Why am I here?";
	cout << endl;
	cin >> choice;



};
