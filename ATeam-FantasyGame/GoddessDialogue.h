#pragma once
#include "DialogueNPC.h"
#include "better-dialogue.h"

class GoddessDialogue : public DialogueNPC {
private:
    bool NPCDefeated;
    bool itemGiven;
    DialogueTree dtree;
public:
    GoddessDialogue();
    void startDialogue(Player& player) override;
    // Define dialogue specific to this NPC
    void defeatedDialogue() override;
    // Defined the dialogue specific to the NPC being defeated
};