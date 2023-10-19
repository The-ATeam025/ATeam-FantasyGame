#pragma once
#include "Location.h"

using namespace std;

class Player
{
private:
	string name; // Player name
	Location* currentLocation; // Pointer to Players Current Location


public:
	Player(string newName, Location* currentLocation); // Constructor
	void walkToLocation(Location* newLocation); // Sets the Players currentLocation to a newLocation
	Location* getCurrentLocation(); // Getter for player location
};