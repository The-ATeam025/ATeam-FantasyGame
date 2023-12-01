#pragma once
//Class to override the npc dialogue for the Hare

class goddessDialogue : public DialogueNPC {
private:
    bool NPCDefeated;
    bool talkedTo;
    DialogueTree dtree;
public:
    goddessDialogue();
    void startDialogue(Player& player) override;
    // Define dialogue specific to this NPC
    void defeatedDialogue() override;
    // Defined the dialogue specific to the NPC being defeated
};