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
    for (Item* inventoryItem : player.getInventory()) {
        std::cout << i << ". " << inventoryItem->getName() << std::endl;
        ++i;
    }

    // Get the player's choice.
    int choice;
    while (true) {
        std::cin >> choice;

        if (choice >= 1 && choice <= i - 1) {
            // Valid choice
            auto chosenItemIterator = std::next(player.getInventory().begin(), choice - 1);

            // Check if the chosen item is the right one
            if ((*chosenItemIterator)->getName() == "Helmet") {
                system("CLS");
                setDescription("A magical aura surrounds the activated marble bust.");
                std::cout<< "You place the " << (*chosenItemIterator)->getName() << " on the marble bust, and its magical aura consumes the room." << std::endl;
                std::cout << "A power beyond your comprehension connects to the helmet, and ties it to the bust." << std::endl;

                // Iterate through player's inventory to place items on the bust
                std::cout << "A section of the wall slides open, and a new passageway leading back outside opens up." << std::endl;

                // Connect the hidden location when the bust is activated
                player.getCurrentLocation()->addConnectedLocation(hiddenLocation);                
                items.push_back(*chosenItemIterator);
                player.removeItemFromInventory(*chosenItemIterator);
            }
            else {
                std::cout << "Nothing happens. The marble bust doesn't react to the " << (*chosenItemIterator)->getName() << "." << std::endl;
            }

            break;
        }
        else {
            std::cout << "Invalid choice. Please enter a valid number." << std::endl;
        }
    }
}