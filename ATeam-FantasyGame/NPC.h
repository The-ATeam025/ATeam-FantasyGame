#pragma once
#include <string>


class NPC
{
private:
    std::string name; // NPC Name
    std::string description; // NPC Description
    //Location* location; // Pointer to where the NPCs location is


public:
    NPC(std::string newName, std::string newDescription); // Constructor
    //void setLocation(Location* newLocation); // Sets the NPCs location
   // Location* getCurrentLocation(); // Getter for NPC location
    void setName(std::string newName); //Setter for Npc name
    std::string getName(); // Getter for NPC name
    void setDescription(std::string newDescription); // Setter for NPC description
    std::string getDescription(); // Getter for NPC description
    //void interact(Player& player); // used for the interaction between the NPC and the player.
};