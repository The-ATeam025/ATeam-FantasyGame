#include "Item.h"
// Item Class
// Allows for creation of items with descriptions

using namespace std;

// Constructor
Item::Item(string newName, string newDescription, string newType)
    : name(newName), description(newDescription), type(newType) {}

// Get the name of the item
string Item::getName() {
    return name;
}

// Get the description of the item
string Item::getDescription() {
    return description;
}

// Getter for item type
string Item::getType() const {
    return type;
}

