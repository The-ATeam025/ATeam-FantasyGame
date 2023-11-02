#pragma once

#include <string>

using namespace std;

class Item {
private:
    string name;
    string description;
    string type;         // Type of item ("armor," "helmet," "boots," "weapon")
public:
    //Constructor
    Item(string newName, string newDescription, string newType);
    // Get the name of the item
    string getName();
    // Get the description of the item
    string getDescription();
    // Get what type of equipment an item is
    string getType() const;
};

