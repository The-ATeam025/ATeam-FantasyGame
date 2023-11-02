#pragma once

#include "Location.h"
#include "Player.h"
#include "NPC.h"
#include "DialogueNPC.h"
#include "redCapDialogue.h"
#include "fairyDialogue.h"
#include <list>
#include <vector>

class GameWorld {
private:
    Location* courtyard;
    Location* greatHall;
    Location* redCapDungeon;
    Location* banquetHall;
    std::vector<NPC*> npcs;

public:
    GameWorld();

    void init(Player& player);

    Location* getCourtyard();
    Location* getGreatHall();
    Location* getRedCapDungeon();
    Location* getBanquetHall();

    // Declarations for managing NPCs
    void addNPC(NPC* npc);
    std::list<NPC*> getNPCsInLocation(const Location* location);
};

