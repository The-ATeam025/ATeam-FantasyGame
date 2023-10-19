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
	vector<string> connectedLocations; // Connected one room to another
	vector<Item*> items; // Connect an item to a room


public:
	Location(string newName, string newDescription); // Location Constructor
	string getName(); // Returns a string Name
	string getDescription();  // Returns a string Description
    void addConnectedLocation(string locationName); // Add a connected location to this location
    vector<string> getConnectedLocations() const; // Get the list of connected locations
    void lookAround() const; // Display items present in the location
    void addItem(Item* item); // Add an item to the location
    static Location* createLocation(
        string name, string description, vector<string> connectedLocations, vector<Item*> items); // Create a new location with specified properties
};