#include "UI.h"
#include "Location.h"
#include <list>

// UI Class
// This class manages the user interface and interactions in the game.

using namespace std;

// Display the player's current location and description.
void UI::displayCurrentLocation(Player& player) {
    // Get the current location the player is in.
    Location* currentLocation = player.getCurrentLocation();

    if (currentLocation != nullptr) {
        // If the current location exists:
        cout << "You are in the " << currentLocation->getName() << endl;
        // Display the name of the location.
        cout << currentLocation->getDescription() << endl;
        // Display the name of the location.
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
    cout << "3. Pick up an item" << endl;
    cout << "4. Check your inventory" << endl;
}


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
    cin >> choice;

    // Clear the current screen
    system("CLS");

    if (choice >= 1 && choice <= connectedLocations.size()) {
        list<Location*>::iterator it = connectedLocations.begin();
        advance(it, choice - 1);
        player.walkToLocation(*it);
        cout << "You have moved to the " << player.getCurrentLocation()->getName() << "." << endl;
        Location* newLocation = player.getCurrentLocation();
        cout << newLocation->getDescription() << endl;
    }
    else if (choice >= 0) {
        cout << "You have decided to stay in the area." << endl;
    }
    else {
        cout << "Invalid choice. Please select a valid option." << endl;
    }
}

// Handle looking around the current location and displaying items.
void UI::lookAround(Location* currentLocation) {
    const list<Item*>& items = currentLocation->getItems();
    // Get the list of items in the current location.
    cout << endl;
    system("CLS");

    if (items.empty()) {
        cout << "You see nothing interesting in the area." << endl;
        // If there are no items, display a message about the empty area.
    }
    else {
        cout << "You look around the " << currentLocation->getName() << ". You see:" << endl;
        int i = 1;
        // Display the name of the current location.
        for (list<Item*>::const_iterator it = items.begin(); it != items.end(); ++it) {
            cout << i << ". " << (*it)->getName() << " - " << (*it)->getDescription() << endl;
            ++i;
            // Loop through and display each item in the area.
        }
    }
}

// Allows player to pick up items from a room
void UI::pickUpItem(Player& player) {
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
        cin >> choice;
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


