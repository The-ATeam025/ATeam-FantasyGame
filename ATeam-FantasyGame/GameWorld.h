#pragma once

#include "Location.h"
#include "Player.h"
#include "NPC.h"
#include "DialogueNPC.h"
#include "redCapDialogue.h"
#include <list>

class GameWorld {
private:
    Location* courtyard;
    Location* greatHall;
    Location* redCapDungeon;
    redCapDialogue* redCapDialogue;
    vector<NPC*> npcs;

public:
    GameWorld() : courtyard(nullptr), greatHall(nullptr), redCapDungeon(nullptr) {}

    void init(Player& player) {
        // Initialize locations
        courtyard = new Location("Courtyard",
            "You find yourself surrounded by a cirlce of dead grass replacing the mushrooms that brought you here. The air is filled with an otherworldly energy, and the sun is hidden behind the clouds");
        greatHall = new Location("Great Hall",
            "You step into a grand chamber adorned with towering arches and elaborately decorated walls. A sense of history and mystery fills the air.");
        redCapDungeon = new Location("Dungeon", "placeholder");

        // Create an item
        // "Name", "Description", "Equipment Slot - If none leave as null"
        Item* rustyKey = new Item("Rusty Key", "A normal looking key, besides the rust covering its surface", "hands");
        Item* celticCross = new Item("Celtic Cross", "An ornate, ancient cross symbolizing Celtic heritage and spirituality", "hands");

        // Create an NPC
        NPC* redCap = new NPC("Redcap", "Placeholder");

        // Add all NPCs to the npcs list
        npcs.push_back(redCap);

        // Add items/Dialogue to NPC

        // Redcap
        redCap->setItem(rustyKey);
        redCap->setDialogue(redCapDialogue);


        // Connect the locations
        courtyard->addConnectedLocation(greatHall);

        greatHall->addConnectedLocation(courtyard);
        greatHall->addConnectedLocation(redCapDungeon);

        redCapDungeon->addConnectedLocation(greatHall);

        // Add items to locations

        //Great Hall
        greatHall->addItem(celticCross);

        // Locate NPC's into their locations

        // Set the player's initial location
        player.walkToLocation(courtyard);

    }

    // Return the pointers to the locations so they can be accessed in the game
    Location* getCourtyard() { return courtyard; }
    Location* getGreatHall() { return greatHall; }
    Location* getredCapDungeon() { return redCapDungeon; }
};
