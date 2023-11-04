#pragma once
#include <string>
#include <list>
#include "Item.h"
#include "Location.h"
#include "Player.h"

// Virtual class to be used for inheritence for all game objects in the world
// Will create some base functions that can be called through inheritance
// Note that game objects are different from items, as they can be interacted with

class Objects{
private:
    std::string name; // Object Name
    std::string description; // Object Description
    std::list<Item*> items; // Object is holding specific items
    Location* location; // Keeps hold of the Object's location

public:
    Objects(std::string newName, std::string newDescription); // Constructor
    virtual void interactWithObject(Player& player) = 0; // Function to be overwritten
    void setLocation(Location* newLocation); // Sets Object location
    Location* getCurrentLocation(); // Getter for Object location
    void addItemToInventory(Item* item); // Adds an item to the Object's items list
    void giveItemsToPlayer(Player& player); // Gives all items to a player
    void dropItems(); // Returns the item from the Object and adds it to the locations inventory
    void setName(std::string newName); // Setter for Object name
    std::string getName(); // Getter for Object name
    void setDescription(std::string newDescription); // Setter for Object description
    std::string getDescription(); // Getter for Object description
};
