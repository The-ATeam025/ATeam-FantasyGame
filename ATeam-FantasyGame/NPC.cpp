#include "NPC.h"

//NPC class
// Sets a NPC name and NPC current Location

//Constructor
NPC::NPC(std::string newName, std::string newDescription) :
	name(newName), description(newDescription), item(nullptr), dialogue(nullptr){}

//Sets NPC location
void NPC::setLocation(Location* newLocation)
{
		location = newLocation;
}

// Get the current location of the NPC
Location* NPC::getCurrentLocation() {
	return location;
	// Return the current location of the player.
}

//Set Dialogue for NPC
void NPC::setDialogue(DialogueNPC* newDialogue)
{
	dialogue = newDialogue;
}


//Set NPC Item
void NPC::setItem(Item* newItem)
{
	item = newItem;
}

//Setter for NPC Name
void NPC::setName(std::string newName)
{
	name = newName;
}

Item* NPC::dropItem()
{
	return item;
	item = nullptr;
}

//Getter for NPC Name
std::string NPC::getName()
{
	return name;
}

//Setter for NPC Description
void NPC::setDescription(std::string newDescription)
{
	description = newDescription;
}

//Getter for NPC Description
std::string NPC::getDescription()
{
	return description;
}





