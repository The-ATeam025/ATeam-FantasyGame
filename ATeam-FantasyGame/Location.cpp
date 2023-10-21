#include "Location.h"
#include "Item.h"
#include "Player.h"

using namespace std;

//Location class
//Sets a Locations name and description
//Returns a Locations name and description
//Allows for items to be added to a location
//Allows for two locations to be connected (next to each other)

//Constructor
Location::Location(string newName, string newDescription) : name(newName), description(newDescription) {
    // Initialize other members as needed...
}


// Returns a string of the Locations name
string Location::getName()
{
	return name;
}


// Returns a string of the Locations description
string Location::getDescription()
{
	return description;
}

// Add a connected location to this location
void Location::addConnectedLocation(Location* location) {
    connectedLocations.push_back(location);
}

// Get the list of connected locations
vector<Location*> Location::getConnectedLocations() const {
    return connectedLocations;
}

// Add an item to the location
void Location::addItem(Item* item) {
    items.push_back(item);
}

// Create a new location with specified properties
Location* Location::createLocation(
    string name, string description, vector<Location*> connectedLocations, vector<Item*> items) {
    Location* newLocation = new Location(name, description);

    // Add connected locations
    for (Location* location : connectedLocations) {
        newLocation->addConnectedLocation(location);
    }

    // Add items to the location
    for (Item* item : items) {
        newLocation->addItem(item);
    }

    return newLocation;
}

// Remove an item from a location
void Location::removeItem(Item* item) {
    // Find and remove the specified item from the location's item list.
    auto it = std::remove(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it, items.end());
    }
}

// Check if the specified item exists in the location's item list.
bool Location::hasItem(const Item* item) const {
    return std::find(items.begin(), items.end(), item) != items.end();
}