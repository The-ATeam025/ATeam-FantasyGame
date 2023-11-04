#pragma once
#include "DialogueNPC.h"

// Class to override the npc dialogue for the Redcap
// Will allow the Redcap to display different dialouge dependant on whether
//  the player has the cross equipped or not.

class redCapDialogue : public DialogueNPC {
private:
    bool NPCDefeated;
public:
    redCapDialogue();
    void startDialogue(Player& player) override;
    // Define dialogue specific to this NPC
    void defeatedDialogue() override;
    // Defined the dialogue specific to the NPC being defeated
};