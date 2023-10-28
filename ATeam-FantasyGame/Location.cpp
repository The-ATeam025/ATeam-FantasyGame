#include "Location.h"
#include "Item.h"
#include "Player.h"

using namespace std;

//Location class
//Sets a Locations name and description
//Returns a Locations name and description
//Allows for items to be added to a location
//Allows for two locations to be connected (next to each other)
//Allows for an npc to be added to a location

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
list<Location*> Location::getConnectedLocations() const {
    return connectedLocations;
}

// Add an item to the location
void Location::addItem(Item* item) {
    items.push_back(item);
}

// Get an item from the location
list<Item*> Location::getItems() const {
    return items;
}

// Remove an item from a location
bool Location::removeItem(Item* item) {
    items.remove(item);
    return true; // Return true if the item was found and removed, you can add error handling if needed.
}

// Check if the specified item exists in the location's item list.
bool Location::hasItem(const Item* item) const {
    return std::find(items.begin(), items.end(), item) != items.end();
}

// Add an Npc to the location
void Location::addNpc(NPC* npc)
{
    npcs.push_back(npc);
}

//Get an Npc from the location
list<NPC*> Location::getNpcs() const {
    return npcs;
}

//Remove an Npc from a location
bool Location::removeNpc(NPC* npc)
{
    npcs.remove(npc);
    return true;
}

// Check if there is an npc in the locations NPC List
bool Location::hasNpc(const NPC* npc) const {
    return std::find(npcs.begin(), npcs.end(), npc) != npcs.end();
}