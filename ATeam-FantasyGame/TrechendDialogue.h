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

/*
    TrechendDialogue();  - Constructor to initialize member variables

    ~TrechendDialogue(); - Destructor (if needed)



    void resetBattle();  - Reset the battle state

    void promptUserForInstructions(Player& player); - Display initial instructions to the player

    std::string promptUserWithWords(); - Generate and display a word for the player to type

    void processUserInput(Player& player); - Process the player's input during the battle

    void dealDamage();   - Decrease the monster's health and display corresponding messages

    bool checkVictory(); - Check if the player has defeated the monster

    void defeatTrechend();      - Display victory message and mark the monster as defeated

    void hitPlayerRandomly(Player& player); - Simulate a random attack from the monster

    void handleLoss(Player& player);   - Handle the player's loss in the battle

    void startDialogue(Player& player) override;   - Start the dialogue and initiate the battle

    void defeatedDialogue() override;  - Display dialogue when the monster is defeated

*/

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
