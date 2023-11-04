#pragma once
#include "Player.h"
#include "Item.h"

//Defines all the class for NPC Dialogue that can then be redefined in a derived class for multiple NPC's
//Allows for each NPC to have different dialogue that can be created in multiple cpp's and worked
//on at the same time

//@Jack

class DialogueNPC {
private:
    bool NPCDefeated;
public:
    virtual void startDialogue(Player& player) = 0;
    virtual void defeatedDialogue() = 0;
    bool isNPCDefeated();
    void setNPCDefeated(bool defeated);
};