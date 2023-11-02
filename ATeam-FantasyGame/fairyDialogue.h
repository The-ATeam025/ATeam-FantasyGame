#pragma once
#include "DialogueNPC.h"
#include "better-dialogue.h"

//Class to override the npc dialogue for the Fairies

class fairyDialogue : public DialogueNPC {
private:
    bool NPCDefeated;
    DialogueTree dtree;
public:
    fairyDialogue();
    void startDialogue(Player& player) override;
    // Define dialogue specific to this NPC
    void defeatedDialogue() override;
    // Defined the dialogue specific to the NPC being defeated
};