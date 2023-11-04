#include "Objects.h"

// Constructor for the Object class
Object::Object(std::string newName, std::string newDescription) : name(newName), description(newDescription), location(nullptr) {
    // Initialize the object with a name and description
}

// Set the location of the object
void Object::setLocation(Location* newLocation) {
    location = newLocation;
}

// Get the current location of the object
Location* Object::getCurrentLocation() {
    return location;
}

// Add an item to the object's items list
void Object::addItemToInventory(Item* item) {
    items.push_back(item);
}

// Give all items held by the object to a player
void Object::giveItemsToPlayer(Player& player) {
    for (Item* item : items) {
        player.addItemToInventory(item);
    }
    items.clear(); // Clear the object's items list
}

// Drop all items from the object and add them to the location's inventory
void Object::dropItems() {
    if (!items.empty() && location != nullptr) {
        for (Item* item : items) {
            location->addItem(item);
        }
        items.clear();
    }
}

// Setter for the object's name
void Object::setName(std::string newName) {
    name = newName;
}

// Getter for the object's name
std::string Object::getName() {
    return name;
}

// Setter for the object's description
void Object::setDescription(std::string newDescription) {
    description = newDescription;
}

// Getter for the object's description
std::string Object::getDescription() {
    return description;
}

// Virtual function for interacting with the object (to be implemented in derived classes)
void Object::interactWithObject(Player& player) {
    // Implement interaction logic specific to each derived object
}
