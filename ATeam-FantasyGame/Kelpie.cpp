#include "Kelpie.h"

Kelpie::Kelpie(string newName, string newDescription, Location* newHiddenLocation)
	: Objects(newName, newDescription), hiddenLocation(newHiddenLocation) {}

void Kelpie::interactWithObject(Player& player) {
	if (player.getInventory().empty()) {
		// The player has nothing in their inventory
		std::cout << "The untamed kelpie...\n"; // descirbes state of kelpie before interacting (look around maybe)
		return;
	}

	if (!items.empty()) {
		// The kelpie is ready to ride, and the bridle is attached 
		std::cout << "The enraged Kelpie begins to calm as it senses the bridle.\n";
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
				setDescription("The once life-threatening kelpie lowers to be bridled.");
				std::cout << "You place the " << itemName << " on the Kelpie, and it extends it's back to accompany a rider.\n";
				std::cout << "The kelpie is mounted and takes off without your discretion.\n";
				std::cout << "In the distance you notice land that fits the description of Aine's domain.\n";

				// Iterate through player's inventory to place items on the bust
				std::cout << "After crossing the lake, you arrive at the neverseen domain of Aine.\n";

				// Connect the hidden location when the bust is activated
				player.getCurrentLocation()->addConnectedLocation(hiddenLocation);
				items.push_back(chosenItem);
				player.removeItemFromInventory(chosenItem);
			}
			else {
				std::cout << "Hooves fly as you attempt to put the " << itemName << " on the kelpie.\n";
			}

			break;
		}
		else {
			std::cout << "Invalid choice. Please enter a valid number." << std::endl;
		}
	}
}