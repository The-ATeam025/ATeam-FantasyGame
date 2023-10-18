#include "Player.h"
// Player Class

//Constructor
// Sets the Players name
Player::Player(std::string name)
{
	name = name;
}

// Changes the Players currentLocation* to a newLocation*
void Player::walkToLocation(Location* newLocation)
{
	Player::currentLocation = newLocation;
}