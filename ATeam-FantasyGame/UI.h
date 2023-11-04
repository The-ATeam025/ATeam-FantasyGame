#include <iostream>
#include "GameWorld.h"

// Handles all interaction of the player and the GameWorld
// Called through a switch case in the ATeam-FantasyGame.cpp file.

class UI {
public:
    static void displayCurrentLocation(Player& player); // Display the player's current location and description.
    static void displayMenu(); // Display the game menu.
    static void movePlayer(Player& player); // Handle moving the player to another location.
    static void lookAround(Location* currentLocation, GameWorld& world); // Handle looking around the current location and displaying items.
    static void pickUpItem(Player& player); // Handle picking up item and adding it to the players inventory
    static void displayInventory(const Player& player); // Handle displaying the user's current inventory
    static void displayEquipment(const ::Player& player); // Display the player's current equipment.
    static void equipItem(Player& player); // Prompt the player to equip an item.
    static void unequipItem(Player& player); // Prompt the player to unequip an item.
    static void equipmentMenu(Player& player); //Displays the users equipment
    static void interactWith(Player& player, GameWorld& world); // Shows the interactions and causes the interactions between players and NPC/Objects
};


