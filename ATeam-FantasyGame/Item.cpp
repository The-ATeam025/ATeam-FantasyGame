#include "Item.h"
// Item Class
// Allows for creation of items with descriptions

using namespace std;

// Constructor
Item::Item(string newName, string newDescription) : name(newName), description(newDescription) {}

// Get the name of the item
string Item::getName() {
    return name;
}

// Get the description of the item
string Item::getDescription() {
    return description;
}
