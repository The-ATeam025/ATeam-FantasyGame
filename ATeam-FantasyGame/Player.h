#pragma once
#include "Location.h"
#include <list>

using namespace std;

class Player
{
private:
	string name; // Player name
	Location* currentLocation; // Pointer to Players Current Location
	list<Item*> inventory; // Vector to store items in the player's inventory
	Item* torsoSlot;  // Equipment slot for torso
	Item* headSlot;   // Equipment slot for head
	Item* feetSlot;   // Equipment slot for feet
	Item* weaponSlot; // Equipment slot for hands (as a weapon)

public:
	Player(string newName); // Constructor
	void walkToLocation(Location* newLocation); // Sets the Players currentLocation to a newLocation
	Location* getCurrentLocation(); // Getter for player location
	void addItemToInventory(Item* item); // Add an item to the player's inventory
	void removeItemFromInventory(Item* item); // Remove an item from the player's inventory
	list<Item*> getInventory() const;  // Get the player's inventory.
	bool hasItemInInventory(Item* item) const; // Check if item is in the player's inventory
	void wearItem(Item* item, string slot); // Allows for player to set the item to a specific slot
	Item* removeItem(string slot); // Allows for player to remove item from that slot
	Item* getHeadSlot() const; // Shows the item currently equipped in the head slot
	Item* getTorsoSlot() const; // Same for torso
	Item* getFeetSlot() const; // Same for feet
	Item* getWeaponSlot() const; // Same for weapon/hand
};