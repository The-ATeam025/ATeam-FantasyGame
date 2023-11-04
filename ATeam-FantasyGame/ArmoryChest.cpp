#include "ArmoryChest.h"

ArmoryChest::ArmoryChest(string newName, string newDescription)
    : Objects(newName, newDescription), isLocked(true) {
    // Initialize the chest's initial state (locked)
}

void ArmoryChest::interactWithObject(Player& player) {
    Item* rustyKey = player.getWeaponSlot();

    if (isLocked) {
        if (rustyKey->getName() == "Rusty Key") {
            // The player has the rusty key, unlock the chest
            isLocked = false;
            setDescription("An unlocked chest in the armory.");
            cout << "You use the Key to unlock the chest." << endl << endl;
            // The chest is unlocked, allow the player to retrieve items
            cout << "You open the chest and find a sword and a helmet inside. You place them in your inventory." << endl;

            // Add items to the player's inventory
            giveItemsToPlayer(player);

        }
        else {
            cout << "The chest won't budge. You will need to find something to unlock it." << endl;
        }
    }
    else {
        if (items.empty()) {
            cout << "The chest is empty." << endl;
        }
    }
}

