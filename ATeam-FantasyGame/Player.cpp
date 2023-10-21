#include "Player.h"
// Player Class
// Sets a Players name and changes Players current Location

// Constructor
Player::Player(std::string newName) : name(newName), currentLocation(nullptr) {}

// Changes the Players currentLocation* to a newLocation*
// To Do: How to validate the argument(example: incorrect values that can lead to crashes)
// Try/Catch Block is an option
void Player::walkToLocation(Location* newLocation)
{
    currentLocation = newLocation;
}

// Get the current location of the player
Location* Player::getCurrentLocation() {
    return currentLocation;
    // Return the current location of the player.
}

// Add the specified item to the player's inventory
void Player::addItemToInventory(Item* item) {
    inventory.push_back(item);
}

// Implement the getInventory method.
vector<Item*> Player::getInventory() const {
    return inventory;
}

bool Player::hasItemInInventory(Item* item) const {
    for (Item* inventoryItem : inventory) {
        if (inventoryItem == item) {
            // The item's address matches the item in the player's inventory.
            return true;
        }
    }
    return false;
}
