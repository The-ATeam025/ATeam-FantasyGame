#pragma once

#include "Location.h"
#include "Player.h"
#include "NPC.h"
#include "DialogueNPC.h"
#include "redCapDialogue.h"
#include <list>
#include <vector>

class GameWorld {
private:
    Location* courtyard;
    Location* greatHall;
    Location* redCapDungeon;
    std::vector<NPC*> npcs;

public:
    GameWorld();

    void init(Player& player);

    Location* getCourtyard();
    Location* getGreatHall();
    Location* getRedCapDungeon();

    // Declarations for managing NPCs
    void addNPC(NPC* npc);
    std::list<NPC*> getNPCsInLocation(const Location* location);
};

