// ATeam-FantasyGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
// test test

#include <iostream>
#include "Backstory.h"
#include "Player.h"
#include "Location.h"
#include "UI.h"

using namespace std;

// Testing a pull request

int main() {


    //ToDo - Create a class that will initialize locations, items, etc
    // Declaring Instances of Rooms
    // Will connect to greatHall after it is declared.
    Location* mushroomRing = Location::createLocation("Mushroom Ring",
        "You find yourself in a mystical circle of mushrooms. The air is filled with an otherworldly energy, and the sun is hidden behind the clouds",
        {},
        {});

    // Item to be stored in greatHall
    Item* rustyKey = new Item("A Key",
        "There is a key on the ground, its surface covered almost entirely rust");

    // Create the "Great Hall" location with the "Key" item and a connection to the "Mushroom Ring"
    Location* greatHall = Location::createLocation("Great Hall",
        "You are in the Great Hall of Blarney Castle, a large room with ancient tapestries and dimly lit chandeliers",
        {mushroomRing},
        { rustyKey });

    // Connect mushroomRing to greatHall
    mushroomRing->addConnectedLocation(greatHall);

    //Create Player instance and start his location in the mushroomRing
    Player player("Player's Name", mushroomRing);

    // Create an instance of the Backstory class
    Backstory backstory;

    backstory.displayIntro();

    // Game loop

    UI::displayCurrentLocation(player);
    while (true) {
        // Display the current location and menu
        UI::displayMenu();

        // Handle player input
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            UI::movePlayer(player);
            break;
        case 2:
            UI::lookAround(player.getCurrentLocation());
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
            break;
        }
    }




    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
