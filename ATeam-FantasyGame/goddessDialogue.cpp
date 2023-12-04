#include "GoddessDialogue.h"
#include <iostream>

using namespace std;

GoddessDialogue::GoddessDialogue() : NPCDefeated(false), itemGiven(false), talkedToGoddess(false) {
}

void GoddessDialogue::startDialogue(Player& player) {
    // Check if the player has talked to the goddess once
    if (talkedToGoddess) {
        // Iterate through the player's inventory
        for (Item* inventoryItem : player.getInventory()) {
            string itemName = inventoryItem->getName();
            if (itemName == "Tooth") {
                player.removeItemFromInventory(inventoryItem);
		itemGiven = true;
		dtree.init_goddess_2(player);
                break; // Exit the loop since we found the "Tooth" item
	}
        }

        // If the loop completes without finding the "Tooth" item
        if (!itemGiven) {
            cout << "You need the item 'Tooth' to proceed." << endl;
        }
    }
    else {
        // Player hasn't talked to the goddess yet
		dtree.init_goddess_1(player);
        talkedToGoddess = true;
	}
}

void GoddessDialogue::defeatedDialogue() {
    // Update the flag to indicate that the player has defeated the fairies
    NPCDefeated = true;
    cout << "You defeated the fairies." << endl;
}