#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include <list>

using namespace std;

class Location
{
private:
	string name; // Name of the Location
	string description; // A description of the Location
	list<Location*> connectedLocations; // Connected one room to another
	list<Item*> items; // Conncet an item to a room

public:
	Location *hidden;
	Location(string newName, string newDescription); // Location Constructor
	Location(string newName, string newDescription, Location* loc); // Location Constructor
	string getName(); // Returns a string Name
	string getDescription();  // Returns a string Description
    void addConnectedLocation(Location* locationName); // Add a connected location to this location
	list<Location*> getConnectedLocations() const; // Get the list of connected locations
    void addItem(Item* item); // Add an item to the location
	list<Item*> getItems() const; // Get an item
	bool removeItem(Item* item); // Remove an item from a location
	bool hasItem(const Item* item) const; // Check if an item is in a location
	void printImage();
};