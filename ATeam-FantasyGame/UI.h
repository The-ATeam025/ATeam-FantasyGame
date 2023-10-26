#include <iostream>
#include "Location.h"
#include "Player.h"

class UI {
public:
    static void displayIntro(); // Display the game's introductory text.
    static void displayCurrentLocation(Player& player); // Display the player's current location and description.
    static void displayMenu(); // Display the game menu.
    static void movePlayer(Player& player); // Handle moving the player to another location.
    static void lookAround(Location* currentLocation); // Handle looking around the current location and displaying items.
    static void pickUpItem(Player& player); // Handle picking up item and adding it to the players inventory
    static void displayInventory(const Player& player); // Handle displaying the user's current inventory
};


