#pragma once
#include "Objects.h"  // Include necessary headers

// Class handles all interactions with the chest inside the Armory
// Derived from the Objects.h class, redifined virtual function
// interactWithObjects

class marbleBust : public Objects {
private:
    std::string name; // Object Name
    std::string description; // Object Description
    std::list<Item*> items; // Object is holding specific items
    Location* location; // Keeps hold of the Object's location
    Location* hiddenLocation; // Will hold onto the outside location to connect the two when activated
public:
    marbleBust(string newName, string newDescription, Location* newHiddenLocation);

    // Override the interaction method
    void interactWithObject(Player& player) override;
};