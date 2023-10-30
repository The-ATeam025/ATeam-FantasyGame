#pragma once
#include <string>
#include "Item.h"
#include "DialogueNPC.h"
#include "Location.h"

class NPC
{
private:
    std::string name; // NPC Name
    std::string description; // NPC Description
    Item* item; // NPC is holding a specifc item
    DialogueNPC* dialogue; // Pointer to the NPC's specfic dialogue
    Location* location; // Keeps hold of the NPC's location

public:
    NPC(std::string newName, std::string newDescription); // Constructor
    void setLocation(Location* newLocation); // Sets NPC location
    Location* getCurrentLocation(); // Getter for NPC location
    void setDialogue(DialogueNPC* newDialogue); //Sets Dialogue for NPC
    void setItem(Item* newItem); //Sets item for NPC
    Item* dropItem(); //returns the item from the NPC ivnentory and returns it
    void setName(std::string newName); //Setter for Npc name
    std::string getName(); // Getter for NPC name
    void setDescription(std::string newDescription); // Setter for NPC description
    std::string getDescription(); // Getter for NPC description
};