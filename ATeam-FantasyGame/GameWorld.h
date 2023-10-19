#pragma once

#include "Location.h"
#include "Player.h"

class GameWorld {
private:
    Location* mushroomRing;
    Location* greatHall;

public:
    GameWorld() : mushroomRing(nullptr), greatHall(nullptr) {}

    void init(Player& player) {
        // Initialize locations
        mushroomRing = new Location("Courtyard",
            "You find yourself surrounded by a cirlce of dead grass replacing the mushrooms that brought you here. The air is filled with an otherworldly energy, and the sun is hidden behind the clouds");
        greatHall = new Location("Great Hall",
            "You step into a grand chamber adorned with towering arches and elaborately decorated walls. A sense of history and mystery fills the air."
        );

        // Create an item
        Item* rustyKey = new Item("A Key", "There is a key on the ground, its surface covered almost entirely in rust");

        // Connect the locations
        mushroomRing->addConnectedLocation(greatHall);
        greatHall->addConnectedLocation(mushroomRing);

        // Add the item to the great hall
        greatHall->addItem(rustyKey);

        // Set the player's initial location
        player.walkToLocation(mushroomRing);
    }

    // Return the pointers to the locations so they can be accessed in the game
    Location* getMushroomRing() { return mushroomRing; }
    Location* getGreatHall() { return greatHall; }
};
