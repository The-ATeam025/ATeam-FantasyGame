#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Location
{
private:
	string name; // Name of the Location
	string description; // A description of the Location
	vector<Location*> connectedLocations; // Connected one room to another


public:
	vector<Item*> items; // Connect an item to a room
	Location(string newName, string newDescription); // Location Constructor
	string getName(); // Returns a string Name
	string getDescription();  // Returns a string Description
    void addConnectedLocation(Location* locationName); // Add a connected location to this location
    vector<Location*> getConnectedLocations() const; // Get the list of connected locations
    void addItem(Item* item); // Add an item to the location
    static Location* createLocation(
        string name, string description, vector<Location*> connectedLocations, vector<Item*> items); // Create a new location with specified properties

};