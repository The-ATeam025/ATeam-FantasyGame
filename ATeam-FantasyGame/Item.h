#pragma once

#include <string>

using namespace std;

class Item {
private:
    string name;
    string description;

public:
    // Constructor
    Item(string newName, string newDescription);

    // Get the name of the item
    string getName();

    // Get the description of the item
    string getDescription();
};
