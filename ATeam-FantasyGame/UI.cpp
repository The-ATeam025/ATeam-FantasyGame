#include "UI.h"
#include "Location.h"

// UI Class
// This class manages the user interface and interactions in the game.

using namespace std;

// Display the game's introductory text.
void UI::displayIntro() {
    cout << "Welcome to the adventure!" << endl;
}

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
        // If the current location is not known, display a message.
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
    // Display the options the player has, such as moving or looking around.
}

// Handle moving the player to another location.
void UI::movePlayer(Player& player) {
    Location* currentLocation = player.getCurrentLocation();
    // Get the current location of the player.

    vector<Location*> connectedLocations = currentLocation->getConnectedLocations();
    // Get a list of locations connected to the current location.

    cout << endl << "Choose a location to move to:" << endl;
    cout << "0. Stay in the area" << endl;
    for (size_t i = 0; i < connectedLocations.size(); ++i) {
        cout << i + 1 << ". " << connectedLocations[i]->getName() << endl;
    }
    // Display a list of connected locations that the player can move to.

    int choice;
    cin >> choice;
    // Get the player's choice.

    if (choice >= 1 && choice <= connectedLocations.size()) {
        // Check if the choice is valid.
        player.walkToLocation(connectedLocations[choice - 1]);
        // Clear the current screen
        system("CLS");
        // Move the player to the chosen location.
        cout << endl << endl << "You have moved to the " << player.getCurrentLocation()->getName() << "." << endl;
        // Display a message about the successful move.
        Location* currentLocation = player.getCurrentLocation();
        // Get the player's new location.
        cout << currentLocation->getDescription() << endl;
        // Display the description of the new location.
    }
    else if(choice >= 0) {
        cout << "You have decided to stay in the area." << endl;
    }
    else {
        cout << "Invalid choice. Please select a valid option." << endl;
        // Display an error message for an invalid choice.
    }
}

// Handle looking around the current location and displaying items.
void UI::lookAround(Location* currentLocation) {
    const vector<Item*>& items = currentLocation->items;
    // Get the list of items in the current location.
    cout << endl;
    if (items.empty()) {
        cout << "You see nothing interesting in the area." << endl;
        // If there are no items, display a message about the empty area.
    }
    else {
        cout << endl << "You look around the " << currentLocation->getName() << ". You see:" << endl;
        // Display the name of the current location.
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i + 1 << ". " << items[i]->getName() << " - " << items[i]->getDescription() << endl;
        }
        // Loop through and display each item in the area.
    }
}

// Allows player to pick up items from a room
void UI::pickUpItem(Player& player) {
    Location* currentLocation = player.getCurrentLocation();

    // Get the list of items in the current location.
    vector<Item*>& items = currentLocation->items;

    if (!items.empty()) {
        cout << "Choose an item to pick up:" << endl;
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i + 1 << ". " << items[i]->getName() << " - " << items[i]->getDescription() << endl;
        }

        int choice;
        cin >> choice;

        if (choice >= 1 && choice <= items.size()) {
            // Move the item to the player's inventory and remove it from the location.
            Item* pickedItem = items[choice - 1];
            player.addItemToInventory(pickedItem);
            currentLocation->removeItem(pickedItem);
            cout << "You have picked up the " << pickedItem->getName() << "." << endl;
        }
        else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
    else {
        cout << "There are no items to pick up in this area." << endl;
    }
}

// Implement the displayInventory method.
void UI::displayInventory(const Player& player) {
    vector<Item*> inventory = player.getInventory();

    if (!inventory.empty()) {
        cout << "Inventory:" << endl;
        for (size_t i = 0; i < inventory.size(); ++i) {
            cout << i + 1 << ". " << inventory[i]->getName() << " - " << inventory[i]->getDescription() << endl;
        }
    }
    else {
        cout << "Your inventory is empty." << endl;
    }
}




