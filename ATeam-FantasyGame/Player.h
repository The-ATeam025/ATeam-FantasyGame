#pragma once
#include "Location.h"


class Player
{
private:
	std::string name; // Player name
	Location* currentLocation; // Pointer to Players Current Location


public:
	Player(std::string newName) : name(newName), currentLocation(nullptr) {} // Player Constructor
	void walkToLocation(Location* newLocation) {} // Sets the Players currentLocation to a newLocation
};