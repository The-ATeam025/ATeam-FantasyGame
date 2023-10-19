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
    // Display the options the player has, such as moving or looking around.
}

// Handle moving the player to another location.
void UI::movePlayer(Player& player) {
    Location* currentLocation = player.getCurrentLocation();
    // Get the current location of the player.

    vector<Location*> connectedLocations = currentLocation->getConnectedLocations();
    // Get a list of locations connected to the current location.

    cout << endl << "Choose a location to move to:" << endl;
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
        // Move the player to the chosen location.
        cout << endl << endl << "You have moved to the " << player.getCurrentLocation()->getName() << "." << endl;
        // Display a message about the successful move.
        Location* currentLocation = player.getCurrentLocation();
        // Get the player's new location.
        cout << currentLocation->getDescription() << endl;
        // Display the description of the new location.
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



