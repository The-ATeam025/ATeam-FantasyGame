#pragma once
#include "Objects.h"  // Include necessary headers

// Class handles all interactions with the chest inside the Armory
// Derived from the Objects.h class, redifined virtual function
// interactWithObjects

class ArmoryChest : public Objects {
private:
    std::string name; // Object Name
    std::string description; // Object Description
    std::list<Item*> items; // Object is holding specific items
    Location* location; // Keeps hold of the Object's location
    bool isLocked = true;
public:
    ArmoryChest(string newName, string newDescription);

    // Override the interaction method
    void interactWithObject(Player& player) override;
};