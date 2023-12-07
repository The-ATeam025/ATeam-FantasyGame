// marbleBust.cpp
#include "marbleBust.h"

marbleBust::marbleBust(std::string newName, std::string newDescription, Location* newHiddenLocation)
    : Objects(newName, newDescription), hiddenLocation(newHiddenLocation) {}

void marbleBust::interactWithObject(Player& player) {
    if (player.getInventory().empty()) {
        // The player has nothing in their inventory
        std::cout << "You feel a magical aura emanating from the marble bust." << std::endl;
        return;
    }

    if (!items.empty()) {
        // The bust is already activated, and the helmet is magically bound
        std::cout << "The magical aura from the bust is now bound to the helmet, locking it into place." << std::endl;
        return;
    }

    std::cout << "You approach the marble bust, and a magical aura surrounds it." << std::endl;
    std::cout << "What do you want to use on the marble bust?" << std::endl << std::endl;

    // Display the player's inventory with numbered options
    int i = 1;

    list<Item*> inventory = player.getInventory();

    for (list<Item*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
        cout << i << ". " << (*it)->getName() << endl;
        i++;
    }

    // Get the player's choice.
    int choice;
    while (true) {
        while (!(cin >> choice) || cin.peek() != '\n') {
            // Handle non-numeric input or input with spaces
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a non-spaced, numeric value." << endl << endl;
        }

        if (choice >= 1 && choice <= i - 1) {
            // Valid choice
            list<Item*>::iterator it = inventory.begin();
            advance(it, choice - 1);
            Item* chosenItem = *it;
            string itemName = (chosenItem->getName());
            // Check if the chosen item is the right one
            if (itemName == "Helmet") {
                system("CLS");
                setDescription("A magical aura surrounds the activated marble bust.");
                std::cout<< "You place the " << itemName << " on the marble bust, and its magical aura consumes the room.\n" << std::endl;
                std::cout << "A power beyond your comprehension connects to the helmet, and ties it to the bust.\n" << std::endl;

                // Iterate through player's inventory to place items on the bust
                std::cout << "A section of the wall slides open, and a new passageway leading back outside opens up." << std::endl;

                // Connect the hidden location when the bust is activated
                player.getCurrentLocation()->addConnectedLocation(hiddenLocation);                
                items.push_back(chosenItem);
                player.removeItemFromInventory(chosenItem);
            }
            else {
                std::cout << "Nothing happens. The marble bust doesn't react to the " << itemName << "." << std::endl;
            }

            break;
        }
        else {
            std::cout << "Invalid choice. Please enter a valid number." << std::endl;
        }
    }
}