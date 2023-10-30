#include "UI.h"
#include "Location.h"
#include <list>
#include "gameWorld.h"

// UI Class
// This class manages the user interface and interactions in the game.

using namespace std;

// FIXED INPUT LOOPING with cin.clear() and cin.ignore after every invalid input

// Display the player's current location and description.
void UI::displayCurrentLocation(Player& player) {
    // Get the current location the player is in.
    Location* currentLocation = player.getCurrentLocation();

    if (currentLocation != nullptr) {
        // If the current location exists:
        cout << "You are in the " << currentLocation->getName() << endl;
        // Display the name of the location.
        cout << currentLocation->getDescription() << endl;
        // Display the description of the location.
    }
    else {
        cout << "Player's location is unknown." << endl;
    }
}

// Display the game menu.
void UI::displayMenu() {
    cout << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Move to a nearby area" << endl;
    cout << "2. Look around" << endl;
    cout << "3. Talk to someone" << endl;
    cout << "4. Pick up an item" << endl;
    cout << "5. Check your inventory" << endl;
    cout << "6. Manage your equipment" << endl;
}

// Handles moving player from location to location
void UI::movePlayer(Player& player) {
    Location* currentLocation = player.getCurrentLocation();
    list<Location*> connectedLocations = currentLocation->getConnectedLocations();
    // Get the current location of the player and its connected locations

    cout << endl << "Choose a location to move to:" << endl;
    cout << "0. Stay in the area" << endl;
    int i = 1;
    for (list<Location*>::iterator it = connectedLocations.begin(); it != connectedLocations.end(); ++it) {
        cout << i << ". " << (*it)->getName() << endl;
        ++i;
    }
    // Display a list of connected locations that the player can move to.
    int choice;

    // Get the player's choice.
    while (!(cin >> choice) || cin.peek() != '\n') {
        // Handle non-numeric input or input with spaces
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a non-spaced, numeric value." << endl << endl;
    }

    system("CLS");

    if (choice >= 1 && choice <= connectedLocations.size()) {
        list<Location*>::iterator it = connectedLocations.begin();
        advance(it, choice - 1);
        player.walkToLocation(*it);
        cout << "You have moved to the " << player.getCurrentLocation()->getName() << "." << endl;
        Location* newLocation = player.getCurrentLocation();
        cout << newLocation->getDescription() << endl;
    }
    else if (choice == 0) {
        cout << "You have decided to stay in the area." << endl;
    }
    else {
        cout << "Invalid choice. Please select a valid option." << endl;
    }
}

// Handle looking around the current location and displaying items and Npcs.
void UI::lookAround(Location* currentLocation, GameWorld& world) {
    // Get the list of items and NPCs in the current location.
    const list<Item*>& items = currentLocation->getItems();
    const list<NPC*>& npcs = world.getNPCsInLocation(currentLocation);

    cout << endl;
    system("CLS");

    if (items.empty() && npcs.empty()) {
        cout << "You see nothing interesting in the area." << endl;
    }
    else {
        cout << "You look around the " << currentLocation->getName() << ". You see:" << endl;

        int i = 1;

        // Display items in the area.
        for (list<Item*>::const_iterator it = items.begin(); it != items.end(); ++it) {
            cout << i << ". " << (*it)->getName() << " - " << (*it)->getDescription() << endl;
            ++i;
        }

        // Display NPCs in the area.
        for (list<NPC*>::const_iterator it = npcs.begin(); it != npcs.end(); ++it) {
            cout << i << ". " << (*it)->getName() << " - " << (*it)->getDescription() << endl;
            ++i;
        }
    }
}

// Allows player to pick up items from a room
void UI::pickUpItem(Player & player) {
    Location* currentLocation = player.getCurrentLocation();
    // Get the list of items in the current location.
    list<Item*> items = currentLocation->getItems(); // Corrected to list<Item*>

    if (!items.empty()) {
        cout << endl << "Choose an item to pick up:" << endl;
        cout << "0. Do not pick up an item" << endl;
        int i = 1;
        for (list<Item*>::iterator it = items.begin(); it != items.end(); ++it) { // Corrected to list<Item*>::iterator
            cout << i << ". " << (*it)->getName() << " - " << (*it)->getDescription() << endl;
            ++i;
        }

        int choice;
        while (!(cin >> choice) || cin.peek() != '\n') {
            // Handle non-numeric input or input with spaces
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a non-spaced, numeric value." << endl << endl;
        }

        system("CLS");

        if (choice == 0) {
            cout << "You have decided not to pick up an item." << endl;
        }
        else if (choice >= 1 && choice <= items.size()) {
            list<Item*>::iterator it = items.begin();
            advance(it, choice - 1);

            // Move the item to the player's inventory and remove it from the location.
            Item* pickedItem = *it;
            player.addItemToInventory(pickedItem);
            currentLocation->removeItem(pickedItem);
            cout << "You have picked up the " << pickedItem->getName() << "." << endl;
        }
        else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
    else {
        system("CLS");
        cout << "There are no items to pick up in this area." << endl;
    }
}

// Allows for player to access their inventory
void UI::displayInventory(const Player& player) {
    list<Item*> inventory = player.getInventory();
    system("CLS");

    if (!inventory.empty()) {
        cout << "Inventory:" << endl;
        int i = 1;
        for (list<Item*>::const_iterator it = inventory.begin(); it != inventory.end(); ++it) {
            cout << i << ". " << (*it)->getName() << " - " << (*it)->getDescription() << endl;
            ++i;
        }
    }
    else {
        cout << "Your inventory is empty." << endl;
    }
}

// Function to display what the user has equipped
void UI::displayEquipment(const Player& player) {
    cout << "Current Equipment:" << endl << endl;
    cout << "1. Head - " << (player.getHeadSlot() ? player.getHeadSlot()->getName() : "None") << endl;
    cout << "2. Torso - " << (player.getTorsoSlot() ? player.getTorsoSlot()->getName() : "None") << endl;
    cout << "3. Legs - " << (player.getFeetSlot() ? player.getFeetSlot()->getName() : "None") << endl;
    cout << "4. Hands - " << (player.getWeaponSlot() ? player.getWeaponSlot()->getName() : "None") << endl << endl;
}
// Function to equip an item to a selected slot
void UI::equipItem(Player& player) {
    cout << "Choose a slot to equip the item:" << endl << endl;
    cout << "0. Return to menu" << endl;
    cout << "1. Head" << endl;
    cout << "2. Torso" << endl;
    cout << "3. Legs" << endl;
    cout << "4. Hands" << endl;
    int choice;
    while (!(cin >> choice) || cin.peek() != '\n') {
        // Handle non-numeric input or input with spaces
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a non-spaced, numeric value." << endl << endl;
    }
    // Gets the choice of the user for what slot they would like to fill
    if (choice >= 1 && choice <= 4) {
        string slot;
        if (choice == 1) slot = "head";
        else if (choice == 2) slot = "torso";
        else if (choice == 3) slot = "legs";
        else if (choice == 4) slot = "hands";
        list<Item*> inventory = player.getInventory();
        // Display inventory that can fill the selected slot
        if (!inventory.empty()) {
            int i = 1;
            cout << endl;
            for (list<Item*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
                if ((*it)->getType() == slot) {
                    cout << i << ". " << (*it)->getName() << " - " << (*it)->getDescription() << endl;
                    i++;
                }
            }

            if (i == 1) {
                system("CLS");
                cout << "No equippable items in your inventory for the selected slot." << endl << endl;
                return;
            }
            // Gets the users choice for which item they would like to equip and filters it so it matches a choice
            int itemChoice;
            while (!(cin >> itemChoice) || cin.peek() != '\n') {
                // Handle non-numeric input or input with spaces
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a non-spaced, numeric value." << endl << endl;
            }

            system("CLS");
            // Checks if the item choice is in the list of the provided items
            if (itemChoice >= 1 && itemChoice <= i - 1) {
                list<Item*>::iterator it = inventory.begin();
                advance(it, itemChoice - 1);
                Item* item = *it;
                player.wearItem(item, slot);
            }
            else {
                system("CLS");
                cout << "Invalid item choice. Please select a valid option." << endl << endl;
            }
        }
        else if (choice == 0) {
            system("CLS");
            cout << "You have decided to keep your equipment the same";
        }
        else {
            system("CLS");
            cout << "Your inventory is empty." << endl << endl;
        }
    }
    else {
        cout << "Invalid slot choice. Please select a valid option." << endl << endl;
    }
}
// Fucntion to let the user unequip items
void UI::unequipItem(Player& player) {
    cout << "Choose a slot to unequip:" << endl << endl;
    cout << "0. Nothing" << endl;
    cout << "1. Head" << endl;
    cout << "2. Torso" << endl;
    cout << "3. Legs" << endl;
    cout << "4. Hands" << endl;
    int choice;
    while (!(cin >> choice) || cin.peek() != '\n') {
        // Handle non-numeric input or input with spaces
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a non-spaced, numeric value." << endl << endl;
    }
    system("CLS");

    if (choice >= 1 && choice <= 4) {
        string slot;
        if (choice == 1) slot = "head";
        else if (choice == 2) slot = "torso";
        else if (choice == 3) slot = "legs";
        else if (choice == 4) slot = "hands";
        Item* item = player.removeItem(slot);
        // Unequips item from that slot and moves it to the user's inventory
        if (item) {
            cout << "You have unequipped " << item->getName() << " from the " << slot << " slot." << endl << endl;
            player.addItemToInventory(item); // Add the item back to inventory
        }
        else {
            cout << "No item was equipped in the " << slot << " slot." << endl << endl;
        }
    }
    else if (choice == 0) {
        cout << "You have decided to keep all your equipment on." << endl << endl;
    }
    else {
        cout << "Invalid slot choice. Please select a valid option." << endl << endl;
    }
}
// Function displays the options for the user to take in regards to their inventory
void UI::equipmentMenu(Player& player) {
    while (true) {
        cout << "Equipment Menu:" << endl << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "1. Display Equipment" << endl;
        cout << "2. Equip Item" << endl;
        cout << "3. Unequip Item" << endl;
        int choice;
        while (!(cin >> choice) || cin.peek() != '\n') {
            // Handle non-numeric input or input with spaces
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a non-spaced, numeric value." << endl << endl;
        }
        system("CLS");
        switch (choice) {
        case 0:
            cout << "You have returned to the main menu:" << endl;
            return; // Return to the main menu
        case 1:
            displayEquipment(player);
            break;
        case 2:
            equipItem(player);
            break;
        case 3:
            unequipItem(player);
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl << endl;
        }
    }
}

void UI::interactWithNPC(Player& player, GameWorld& world) {
    Location* currentLocation = player.getCurrentLocation();

    // Get NPCs in the current location from the GameWorld
    list<NPC*> locationNPCs = world.getNPCsInLocation(currentLocation);
    system("CLS");
    if (!locationNPCs.empty()) {
        cout << "You see someone in the area:" << endl;
        int i = 1;
        cout << "0. Do not talk to anyone" << endl;
        for (list<NPC*>::iterator it = locationNPCs.begin(); it != locationNPCs.end(); ++it) {
            std::cout << i << ". " << (*it)->getName() << endl << endl;
            ++i;
        }

        std::cout << "Choose someone to interact with" << endl;
        int choice;

        while (!(cin >> choice) || cin.peek() != '\n' || choice < 0 || choice > locationNPCs.size()) {
            // Handle non-numeric input or input with spaces
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a non-spaced, numeric value listed." << endl << endl;
        }

        system("CLS");

        if (choice == 0) {
            std::cout << "You have decided not to interact with any anyone." << endl;
        }
        else {
            list<NPC*>::iterator it = locationNPCs.begin();
            advance(it, choice - 1);
            NPC* npc = *it;
            DialogueNPC* dialogue = npc->getDialogue();

            dialogue->startDialogue(player);

            // Call NPC-specific interactions or actions
            // For example, you can check if the NPC is defeated and drop an item if necessary
            if (dialogue->isNPCDefeated() == true) {
                // Call defeated dialogue
                dialogue->defeatedDialogue();
                Item* item = npc->dropItem();
                currentLocation->addItem(item);
                npc->setLocation(nullptr);
                // Implement other interactions as needed
            }
        }
    }
    else {
        system("CLS");
        cout << "There is nobody in this area." << endl;
    }
}



