#include "Player.h"
// Player Class
//Sets a Players name and changes Players current Location

//Constructor
Player::Player(string newName) : name(newName), currentLocation(nullptr) {}

// Changes the Players currentLocation* to a newLocation*
//To Do: How to validate the argument(example: incorrect values that can lead to crashes)
// Try/Catch Block is an option
void Player::walkToLocation(Location* newLocation)
{
	Player::currentLocation = newLocation;
}

// Get the current location of the player
Location* Player::getCurrentLocation() {
    return currentLocation;
    // Return the current location of the player.
}