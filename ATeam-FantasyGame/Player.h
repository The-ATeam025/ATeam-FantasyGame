#pragma once
#include "Location.h"

using namespace std;

class Player
{
private:
	string name; // Player name
	Location* currentLocation; // Pointer to Players Current Location
	vector<Item*> inventory; // Vector to store items in the player's inventory

public:
	Player(string newName); // Constructor
	void walkToLocation(Location* newLocation); // Sets the Players currentLocation to a newLocation
	Location* getCurrentLocation(); // Getter for player location
	void addItemToInventory(Item* item); // Add an item to the player's inventory
	vector<Item*> getInventory() const;  // Get the player's inventory.
	bool hasItemInInventory(Item* item) const; // Check if item is in the player's inventory

};