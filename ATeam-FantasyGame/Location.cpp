#include "Location.h"

//Location class

//Constructor
Location::Location(std::string name, std::string description)
{
	name = name;
	description = description;
}

// Returns a string of the Locations name
std::string Location::getName()
{
	return name;
}


// Returns a string of the Locations description
std::string Location::getDescription()
{
	return description;
}