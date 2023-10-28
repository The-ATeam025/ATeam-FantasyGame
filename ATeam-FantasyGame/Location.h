#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "NPC.h"
#include <list>

using namespace std;

class Location
{
private:
	string name; // Name of the Location
	string description; // A description of the Location
	list<Location*> connectedLocations; // Connected one room to another
	list<Item*> items; // Conncet an item to a room
	list<NPC*> npcs; // Connect NPCS to a room


public:
	Location(string newName, string newDescription); // Location Constructor
	string getName(); // Returns a string Name
	string getDescription();  // Returns a string Description
    void addConnectedLocation(Location* locationName); // Add a connected location to this location
	list<Location*> getConnectedLocations() const; // Get the list of connected locations
    void addItem(Item* item); // Add an item to the location
	list<Item*> getItems() const; // Get an item
	bool removeItem(Item* item); // Remove an item from a location
	bool hasItem(const Item* item) const; // Check if an item is in a location
	void addNpc(NPC* npc); // Add an npc to the location
	list<NPC*> getNpcs() const; // Returns an Npc
	bool removeNpc(NPC* npc); // Remove an npc from a location
	bool hasNpc(const NPC* npc) const ; // Check if there is an npc in a location

};