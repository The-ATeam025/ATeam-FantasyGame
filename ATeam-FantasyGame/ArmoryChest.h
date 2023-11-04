#pragma once
#include "Object.h"  // Include necessary headers

// Class handles all interactions with the chest inside the Armory
// Derived from the Objects.h class, redifined virtual function
// interactWithObjects

class ArmoryChest : public Object {
private:
    bool isLocked;
public:
    ArmoryChest();

    // Override the interaction method
    void interactWithObject(Player& player) override;
};