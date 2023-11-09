// ATeam-FantasyGame.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Backstory.h"
#include "Player.h"
#include "Location.h"
#include "UI.h"
#include "GameWorld.h"
#include "dialogue.h"
#include "better-dialogue.h"

using namespace std;

int main() {
    // Create a player instance
    Player player("Player's Name");

    // Create a game world instance
    GameWorld gameWorld;

    gameWorld.init(player);
    
    // Create an instance of the Backstory class
    Backstory backstory;

    // Display backstory
    backstory.displayIntro();
    system("CLS");

    // Create an instance of the Dialogue class
    Dialogue dial;

    // Call the CatIntro function to continue the story 
    dial.CatIntro();

    // Prompt user to continue
    system("pause");

    // Clear the screen
    system("CLS");

    // Flag to control the game loop
    bool quitGame = false;
    UI::displayCurrentLocation(player);
    // Game loop
    while (!quitGame) {
        // Display the current location and menu
        UI::displayMenu();

        // Handle player input
        int choice;
        while (!(cin >> choice) || cin.peek() != '\n') {
            // Handle non-numeric input or input with spaces
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("CLS");
            cout << "Enter a non-spaced, numeric value." << endl;
        
        }

        switch (choice) {
        case 1:
            UI::movePlayer(player);
            break;
        case 2:
            UI::lookAround(player.getCurrentLocation(), gameWorld); //Change this so it also shows Npcs in the room
            break;
        case 3:
            UI::interactWith(player, gameWorld);
            break;
        case 4:
            UI::pickUpItem(player);
            break;
        case 5:
            UI::displayInventory(player);
            break;
        case 6:
            system("CLS");
            UI::equipmentMenu(player);
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
            // FIXED INPUT LOOPING with cin.clear() and cin.ignore after every invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        // Check if a game-ending condition occurred
        if (player.getShouldRestartGame() == true) {
            int restartChoice;
            cout << endl << "You have been doomed to stay in this dimension forever." << endl;
            cout << "Would you like to restart the game (after meeting the cat) or quit?" << endl;
            cout << "1. Restart" << endl;
            cout << "2. Quit" << endl;

            while (!(cin >> restartChoice) || restartChoice < 1 || restartChoice > 2) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter 1 to restart or 2 to quit." << endl << endl;
            }

            if (restartChoice == 1) {
                system("CLS");
                player.setShouldRestartGame(false); // Resets the shouldRestartGame check to false;
                player.clearInventoryAndEquipment(); // Clears the players inventory and slots

                // Restart the game by recreating the game world
                gameWorld.~GameWorld(); // Destruct the current game world
                new (&gameWorld) GameWorld(); // Recreate a new game world
                gameWorld.init(player); // Reinitalize the gameWorld

                UI::displayCurrentLocation(player); // Redisplays the current location
            }
            else {
                // Quit the game
                quitGame = true;
            }
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
