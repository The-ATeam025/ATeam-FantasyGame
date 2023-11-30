#pragma once
#include "DialogueNPC.h"
#include "better-dialogue.h"

//Class to override the npc dialogue for the troll

class trollDialogue : public DialogueNPC {
private:
    bool NPCDefeated;
    bool talkedTo;
    DialogueTree dtree;
public:
    trollDialogue();
    void startDialogue(Player& player) override;
    // Define dialogue specific to this NPC
    void defeatedDialogue() override;
    // Defined the dialogue specific to the NPC being defeated
};
