#include "UI.h"

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
    cout << "3. Interact" << endl;
    cout << "4. Pick up an item" << endl;
    cout << "5. Check your inventory" << endl;
    cout << "6. Equip an item" << endl;
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

// Handle looking around the current location and displaying items, objects NPCs.
void UI::lookAround(Location* currentLocation, GameWorld& world) {
    // Get the list of items, objects, and NPCs in the current location.
    const list<Item*>& items = currentLocation->getItems();
    const list<NPC*>& npcs = world.getNPCsInLocation(currentLocation);
    list<Objects*> locationObjects = world.getObjectsInLocation(currentLocation);

    cout << endl;
    system("CLS");

    if (items.empty() && npcs.empty() && locationObjects.empty()) {
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


        // Display Objects in the area
        for (list<Objects*>::iterator it = locationObjects.begin(); it != locationObjects.end(); ++it) {
            std::cout << i << ". " << (*it)->getName() << " - " << (*it)->getDescription() << endl;
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

// Function to equip an item
void UI::equipItem(Player& player) {
    // Check if the slot is already filled
    system("CLS");
    if (player.getWeaponSlot() != nullptr) {
        cout << "You already have a " << player.getWeaponSlot()->getName() << " equipped, would you like to equip something else?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int choice;
        while ((!(cin >> choice) || cin.peek() != '\n')||choice < 1||choice > 2){
            // Handle non-numeric input or input with spaces
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter either 1 or 2." << endl;
        }
        if (choice == 1) {
            cout << endl;
            chooseItemEquip(player);
            return;
        }
        if (choice == 2) {
            system("CLS");
            cout << "You have decided not to unequip the " << player.getWeaponSlot()->getName() << endl;
            return;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }
    else {
        chooseItemEquip(player);
    }
}

void UI::chooseItemEquip(Player& player) {

    list<Item*> inventory = player.getInventory();
    list<Item*> equippableItems;

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if ((*it)->getType() == "hands") {
            equippableItems.push_back(*it);
        }
    }

    if (!inventory.empty()) {
        int i = 1;

        cout << "Choose an item to equip." << endl;

        for (auto it = equippableItems.begin(); it != equippableItems.end(); ++it) {
            cout << i << ". " << (*it)->getName() << " - " << (*it)->getDescription() << endl;
            i++;
        }

        if (i == 1) {
            system("CLS");
            cout << "You do not have anything to equip." << endl << endl;
            return;
        }

        int itemChoice;
        while (!(cin >> itemChoice) || cin.peek() != '\n') {
            // Handle non-numeric input or input with spaces
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a non-spaced, numeric value." << endl << endl;
        }

        system("CLS");

        if (itemChoice >= 1 && itemChoice <= i - 1) {
            auto it = equippableItems.begin();
            advance(it, itemChoice - 1);
            Item* item = *it;

            // Check if the selected slot is empty before equipping the item
            if (player.getWeaponSlot() == nullptr) {
                player.wearItem(item, "hands");
                cout << "You have equipped the " << player.getWeaponSlot()->getName() << "." << endl;
                player.removeItemFromInventory(item);
            }
            else {
                Item* itemRemoved = player.removeItem("hands");
                player.addItemToInventory(itemRemoved);
                player.wearItem(item, "hands");
                cout << "You have equipped the " << player.getWeaponSlot()->getName() << ", and removed the " << itemRemoved->getName() << "." << endl;
                player.removeItemFromInventory(item);
            }
        }
        else {
            system("CLS");
            cout << "Invalid item choice. Please select a valid option." << endl;
        }
    }
    else {
        system("CLS");
        cout << "You have nothing in your inventory." << endl;
    }
}

// Function to interact with objects or NPCs in the current room
void UI::interactWith(Player& player, GameWorld& world) {
    Location* currentLocation = player.getCurrentLocation();

    // Get NPCs and objects in the current location from the GameWorld
    list<NPC*> locationNPCs = world.getNPCsInLocation(currentLocation);
    list<Objects*> locationObjects = world.getObjectsInLocation(currentLocation);

    if (!locationNPCs.empty() || !locationObjects.empty()) {
        cout << endl << "Who or what would you like to interact with?:" << endl;
        int i = 1;
        cout << "0. Do not interact with anyone or anything" << endl;

        // List NPCs in the current location
        for (list<NPC*>::iterator it = locationNPCs.begin(); it != locationNPCs.end(); ++it) {
            std::cout << i << ". " << (*it)->getName() << endl << endl;
            ++i;
        }

        // List objects in the current location
        for (list<Objects*>::iterator it = locationObjects.begin(); it != locationObjects.end(); ++it) {
            std::cout << i << ". " << (*it)->getName() << endl << endl;
            ++i;
        }

        int choice;

        while (!(cin >> choice) || cin.peek() != '\n' || choice < 0 || choice > locationNPCs.size() + locationObjects.size()) {
            // Handle non-numeric input or input with spaces
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a non-spaced, numeric value listed." << endl << endl;
        }

        system("CLS");

        if (choice == 0) {
            cout << "You have decided not to interact with anyone or anything." << endl;
        }
        else if (choice <= locationNPCs.size()) {
            list<NPC*>::iterator it = locationNPCs.begin();
            advance(it, choice - 1);
            NPC* npc = *it;
            DialogueNPC* dialogue = npc->getDialogue();
            dialogue->startDialogue(player);

            if (dialogue->isNPCDefeated()==true) {
                dialogue->defeatedDialogue();
                Item* item = npc->dropItem();
                currentLocation->addItem(item);
                npc->setLocation(nullptr);
            }
        }
        else {
            list<Objects*>::iterator it = locationObjects.begin();
            advance(it, choice - locationNPCs.size() - 1);
            Objects* object = *it;
            object->interactWithObject(player);
        }
    }
    else {
        system("CLS");
        cout << "There is nobody or nothing in this area." << endl;
    }
}



