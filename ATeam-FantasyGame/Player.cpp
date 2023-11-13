#include "Player.h"
// Player Class
// Sets a Players name and changes Players current Location

// Constructor
Player::Player(std::string newName) : name(newName), currentLocation(nullptr), torsoSlot(nullptr),
headSlot(nullptr), feetSlot(nullptr), weaponSlot(nullptr){}

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

// Removes the item from the inventory if it is present
void Player::removeItemFromInventory(Item* item) {
    auto it = std::find(inventory.begin(), inventory.end(), item);

    if (it != inventory.end()) {
        // Item found, erase it
        it = inventory.erase(it);
    }
}

// Implement the getInventory method.
list<Item*> Player::getInventory() const {
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

// Equips an item to its correct slot if it is empty
// Not implemented to check if the item has the correct slot as of now, ui handles
// Removes the item from the players inventory if the slot is available
void Player::wearItem(Item* item, string slot) {
    if (slot == "torso") {
        torsoSlot = item;
        removeItemFromInventory(item);
    }
    else if (slot == "head" && headSlot == nullptr) {
        headSlot = item;
        removeItemFromInventory(item);
    }
    else if (slot == "feet" && feetSlot == nullptr) {
        feetSlot = item;
        removeItemFromInventory(item);
    }
    else if (slot == "hands" && weaponSlot == nullptr) {
        weaponSlot = item;
        removeItemFromInventory(item);
    }
    else {
        cout << "Slot is already occupied." << endl << endl;
    }
}
// Removes the item from the slot is in a returns the item that was just removed
Item* Player::removeItem(string slot) {
    Item* item = nullptr;
    if (slot == "head") {
        item = headSlot;
        headSlot = nullptr;
    }
    else if (slot == "torso") {
        item = torsoSlot;
        torsoSlot = nullptr;
    }
    else if (slot == "legs") {
        item = feetSlot;
        feetSlot = nullptr;
    }
    else if (slot == "hands") {
        item = weaponSlot;
        weaponSlot = nullptr;
    }
    else {
        cout << "Invalid equipment slot." << endl;
    }
    return item;


}// Getters for the equipment slots
Item* Player::getHeadSlot() const {
    return headSlot;
}
Item* Player::getTorsoSlot() const {
    return torsoSlot;
}
Item* Player::getFeetSlot() const {
    return feetSlot;
}
Item* Player::getWeaponSlot() const {
    return weaponSlot;
}

