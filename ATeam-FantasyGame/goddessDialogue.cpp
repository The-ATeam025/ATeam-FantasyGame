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
                itemGiven = true;
                dtree2.init_goddess_2(player);
                Backstory backstory;
                backstory.epilogue();
            }
        }
    }
    else {
        // Player hasn't talked to the goddess yet
        talkedToGoddess = true;
        dtree.init_goddess_1(player);
    }

    // If the loop completes without finding the "Tooth" item
    if (!itemGiven) {
        cout << "She has nothing else to say to you. You must return with the creature's tooth." << endl;
    }
}

void GoddessDialogue::defeatedDialogue() {
    // Update the flag to indicate that the player has defeated the fairies
    NPCDefeated = true;
    cout << "You defeated the fairies." << endl;
}