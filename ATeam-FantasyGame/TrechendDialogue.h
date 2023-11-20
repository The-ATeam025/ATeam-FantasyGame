#pragma once
#include "DialogueNPC.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cctype>
#include <vector>

class TrechendDialogue : public DialogueNPC {
private:
    int maxHealth;
    int maxAttempts;
    int health;
    bool defeated;
    

public:
    TrechendDialogue();
    ~TrechendDialogue();

    void resetBattle();
    void promptUserForInstructions(Player& player);
    std::string promptUserWithWords();
    void processUserInput(Player& player);
    void dealDamage();
    bool checkVictory();
    void defeatTrechend();
    void hitPlayerRandomly(Player& player);
    void handleLoss(Player& player);
    void startDialogue(Player& player) override;
    void defeatedDialogue() override;
};
