#include "Player.h"
// Player Class
//Sets a Players name and changes Players current Location

//Constructor
// Sets the Players name
Player::Player(std::string newName)
{

}

// Changes the Players currentLocation* to a newLocation*
//To Do: How to validate the argument(example: incorrect values taht can lead to crashes)
// Try/Catch Block is an option
void Player::walkToLocation(Location* newLocation)
{
	Player::currentLocation = newLocation;
}