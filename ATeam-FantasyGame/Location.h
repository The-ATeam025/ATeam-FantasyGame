#pragma once

#include <iostream>
#include <string>
#include <vector>

class Location
{
private:
	std::string name; // Name of the Location
	std::string description; // A description of the Location

public:
	Location(std::string name, std::string description) : name(name), description(description) {} // Location Constructor
	std::string getName() {} // Returns a string Name
	std::string getDescription() {}  // Returns a string Description
};
