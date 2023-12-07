#include "hareDialogue.h"
#include <iostream>

using namespace std;

hareDialogue::hareDialogue() : NPCDefeated(false), talkedTo(false) {
}

void hareDialogue::startDialogue(Player& player) {
    Item* hands = player.getWeaponSlot();

    

    // Checks the user's hands to be filled and checks if the user is holding a carrot
    if (hands && hands->getName() == "Carrot") {
        player.removeItem("hands");
        player.removeItemFromInventory(hands);
        talkedTo = true;
        dtree.init_hare(player);
    }
    else if (hands && hands->getName() == "Dandelion") {
        player.removeItem("hands");
        player.removeItemFromInventory(hands);
        talkedTo = true;
        dtree.init_hare2(player);
    }
    else {
        
        cout << "The hare twitches its nose at you";
        if (!talkedTo) {
            cout << ", it looks hungry.";
        }
        else {
            cout << ".";
        }
        cout << endl;
    }
}



void hareDialogue::defeatedDialogue() {
	cout << "You defeeated the hare." << endl;
}


