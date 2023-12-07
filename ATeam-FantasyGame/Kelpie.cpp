#include "Kelpie.h"

Kelpie::Kelpie(string newName, string newDescription, Location* newHiddenLocation)
	: Objects(newName, newDescription), noBridle(true), hiddenLocation(newHiddenLocation) {}

void Kelpie::interactWithObject(Player& player) {
	if (!items.empty()) {
		// The kelpie is ready to ride, and the bridle is attached 
		std::cout << "The Kelpie has been bridled already.\n";
		return;
	}
	
	std::cout << "You cautiously approach the powerful horse like creature near the lake, wondering if its too late to turn back.\n";
	std::cout << "*Starts digging in inventory and pulls out the...*\n";
	
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
			if (itemName == "Bridle") {
				system("CLS");
				noBridle = false;
				setDescription("The once threatening kelpie is now bridled.");
				std::cout << "You rush to place the " << itemName << " on the Kelpie, and to your suprise, it turns docile and kneels down, as if to accomodate a rider.\n";

				// Connect the hidden location when the bridle is placed on the kelpie
				player.getCurrentLocation()->addConnectedLocation(hiddenLocation);
				items.push_back(chosenItem);
				player.removeItemFromInventory(chosenItem);
			}
			else {
				std::cout << "Hooves fly and you're forced to retreat as you attempt to put the " << itemName << " on the Kelpie.\n";
			}
			break;
		}
		else {
			std::cout << "Invalid choice. Please enter a valid number." << std::endl;
		}
				player.walkToLocation(player.getCurrentLocation()->hidden);
	}
}