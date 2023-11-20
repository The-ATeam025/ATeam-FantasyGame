#include "TrechendDialogue.h"

TrechendDialogue::TrechendDialogue() : maxHealth(5), maxAttempts(3), health(maxHealth), defeated(false) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

TrechendDialogue::~TrechendDialogue() {}

void TrechendDialogue::resetBattle() {
    health = maxHealth;
    defeated = false;
}

void TrechendDialogue::promptUserForInstructions() {
    std::cout << "You take a deep breath and stare Ellén Trechend!" << std::endl;
    std::cout << "A word will be appear on the screen, type the word to deal damage to the monster." << std::endl;
    std::cout << "You have a limited time for each attack. Be quick!" << std::endl;
}

void TrechendDialogue::promptUserWithWords() {
    std::vector<std::string> battleWords = { "sword", "attack", "strike", "hit", "swing" };
    std::string promptWord = battleWords[std::rand() % battleWords.size()];

    int randomPosition = std::rand() % 3;
    std::string positionText;
    switch (randomPosition) {
    case 0:
        positionText = "";
        break;
    case 1:
        positionText = "                        ";
        break;
    case 2:
        positionText = "                                                    ";
        break;
    default:
        break;
    }

    std::cout << positionText << promptWord << std::endl;
}

void TrechendDialogue::processUserInput(Player& player) {
    Item* weapon = player.getWeaponSlot();
    if (weapon && weapon->getName() == "Sword") {
        std::string userInput;
        std::cin >> userInput;
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
        userInput.erase(std::remove_if(userInput.begin(), userInput.end(), ::isspace), userInput.end());

        if (userInput == "sword" || userInput == "attack" || userInput == "strike" || userInput == "defend" || userInput == "victory") {
            dealDamage();
        }
        else {
            handleLoss(player);
        }
    }
    else {
        std::cout << "You are unarmed and defenseless. Ellén Trechend attacks you, striking you down swiftly." << std::endl;
        handleLoss(player);
    }
}

void TrechendDialogue::dealDamage() {
    health--;
    std::cout << "You hit Trechend!" << std::endl;
}

bool TrechendDialogue::checkVictory() {
    return health <= 0;
}

void TrechendDialogue::defeatTrechend() {
    std::cout << "Congratulations! Trechend has been defeated." << std::endl;
    defeated = true;
    setNPCDefeated(true);
}

void TrechendDialogue::hitPlayerRandomly(Player& player) {
    const int numberOfWaysToHit = 5;
    int randomHit = std::rand() % numberOfWaysToHit;

    switch (randomHit) {
    case 0:
        std::cout << "Trechend scratches you. ";
        break;
    case 1:
        std::cout << "Trechend bites you. ";
        break;
    case 2:
        std::cout << "Trechend spits venom at you. ";
        break;
    case 3:
        std::cout << "Trechend tail-slaps you. ";
        break;
    case 4:
        std::cout << "Trechend roars loudly, stunning you. ";
        break;
    default:
        break;
    }

    int remainingHits = maxAttempts - health;
    std::cout << "You have " << remainingHits << " hits left." << std::endl;

    if (remainingHits <= 0) {
        std::cout << "You've run out of hits. Game over!" << std::endl;
        handleLoss(player);
    }
}

void TrechendDialogue::handleLoss(Player& player) {
    std::cout << "As you were struck down, your vision fades to black. The last thing you see is a black cat." << std::endl;
    std::cout << "A magical aura surrounds you, and you find yourself back before Trechend." << std::endl;

    // Revive the player
    resetBattle();
}

void TrechendDialogue::startDialogue(Player& player) {
    resetBattle();

    // Prompt the user to decide whether to battle the monster
    int choice;
    std::cout << "Do you want to battle Trechend?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;

    while (true) {
        std::cin >> choice;
        if (choice == 1) {
            break;
        }
        else if (choice == 2) {
            std::cout << "You chose not to battle Trechend. You can continue exploring." << std::endl;
            return;
        }
        else {
            std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
        }
    }

    std::cout << "You draw your sword and prepare to battle Trechend!" << std::endl;
    promptUserForInstructions();

    while (!defeated) {
        promptUserWithWords();
        processUserInput(player);
        if (checkVictory()) {
            defeatTrechend();
            resetBattle();
        }
    }
}

void TrechendDialogue::defeatedDialogue() {
    if (isNPCDefeated()) {
        std::cout << "The defeated Trechend lies motionless on the ground." << std::endl;
    }
}


