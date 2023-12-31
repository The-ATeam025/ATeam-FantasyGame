#pragma once

#include "Location.h"
#include "Player.h"
#include "NPC.h"
#include "DialogueNPC.h"
#include "redCapDialogue.h"
#include "fairyDialogue.h"
#include "ArmoryChest.h"
#include "marbleBust.h"
#include "hareDialogue.h"
#include "trollDialogue.h"
#include "TrechendDialogue.h"
#include "GoddessDialogue.h"
#include "Kelpie.h"
#include <list>
#include <vector>

// Initalizes all class instances that will be used during the game
// Only needs to be initalized with the player's name once at the beginning of the program
// Using pointers and functions to connect/add items/locations to objects
// Allows for it to be modified easier later on

class GameWorld {
private:
    Location* courtyard;
    Location* greatHall;
    Location* redCapDungeon;
    Location* banquetHall;
    Location* armory;
    Location* outside;
    Location* meadow;
    Location* bridge;
    Location* swamp;
    Location* crossedBridge;
    Location* lake;
    Location* lake1;
    Location* crossedLake;
    Location* nest;
    Location* bridge1;
    Location* goddessDwelling;
    std::list<NPC*> npcs;
    std::list<Objects*> objects;
    std::list<Location*> outsideLocations;

public:
    GameWorld();
    ~GameWorld();

    void init(Player& player);

    Location* getCourtyard();
    Location* getGreatHall();
    Location* getRedCapDungeon();
    Location* getBanquetHall();
    Location* getOutside();
    Location* getSwamp();
    Location* getMeadow();
    Location* getBridge();
    Location* getBridge1();
    Location* getCrossedBridge;
    Location* getLake();
    Location* getLake1();
    Location* getCrossedLake;
    Location* getNest();

    // Declarations for managing NPCs
    void addNPC(NPC* npc);
    std::list<NPC*> getNPCsInLocation(const Location* location);

    // Declarations for managing objects
    void addObject(Objects* object);
    std::list<Objects*> getObjectsInLocation(const Location* location);
};

