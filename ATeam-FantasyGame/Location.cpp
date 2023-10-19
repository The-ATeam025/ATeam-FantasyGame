#include "Location.h"

using namespace std;

//Location class
//Sets a Locations name and description
//Returns a Locations name and description

//Constructor
Location::Location(string newName, string newDescription)
{

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
void Location::addConnectedLocation(string locationName) {
    connectedLocations.push_back(locationName);
}

// Get the list of connected locations
vector<string> Location::getConnectedLocations() const {
    return connectedLocations;
}

// Display items present in the location
void Location::lookAround() const {
    cout << "You look around the " << name << ". You see the following items:" << endl;
    for (Item* item : items) {
        cout << item->getName() << " - " << item->getDescription() << endl;
    }
}

// Add an item to the location
void Location::addItem(Item* item) {
    items.push_back(item);
}

// Create a new location with specified properties
Location* Location::createLocation(
    string name, string description, vector<string> connectedLocations, vector<Item*> items) {
    Location* location = new Location(name, description);

    for (const string& loc : connectedLocations) {
        location->addConnectedLocation(loc);
    }

    for (Item* item : items) {
        location->addItem(item);
    }

    return location;
}