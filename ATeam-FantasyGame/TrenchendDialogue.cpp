#include "TrechendDialogue.h"

TrechendDialogue::TrechendDialogue() : maxHealth(5), maxAttempts(3), health(maxHealth), defeated(false) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

TrechendDialogue::~TrechendDialogue() {}

void TrechendDialogue::resetBattle() {
    health = maxHealth;
    defeated = false;
}

void TrechendDialogue::promptUserForInstructions(Player& player) {
    system("CLS");
    std::cout << "You take a deep breath and stare at Ellen Trechend." << std::endl;
    std::cout << "The creature stares at you. It appears as a mix of a hydra and a vulture, sporting multiple heads, feathers, and wings." << std::endl << std::endl;
    Item* weapon = player.getWeaponSlot();
    if (weapon && weapon->getName() == "Sword") {
        std::cout << "A word will be appear on the screen, type the word to deal damage to the monster." << std::endl;
        std::cout << "You have a limited time for each attack. Be quick." << std::endl << std::endl;
        std::cout << "You draw your sword and prepare to battle the beast." << std::endl;
        system("pause");
    }
}

void TrechendDialogue::promptUserWithWords() {
    std::vector<std::string> battleWords = { "Bash", "Attack", "Strike", "Hit", "Swing" };
    std::string promptWord = battleWords[std::rand() % battleWords.size()];

    int randomPosition = std::rand() % 3;
    std::string positionText;
    switch (randomPosition) {
    case 0:
        positionText = "";
        break;
    case 1:
        positionText = "                            ";
        break;
    case 2:
        positionText = "                                                           ";
        break;
    default:
        break;
    }

    std::cout << positionText << promptWord << std::endl;
}

void TrechendDialogue::processUserInput(Player& player) {
    Item* weapon = player.getWeaponSlot();
    if (weapon && weapon->getName() == "Sword") {
        std::cout << std::endl;
        std::string userInput;
        std::cin >> userInput;
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
        userInput.erase(std::remove_if(userInput.begin(), userInput.end(), ::isspace), userInput.end());

        if (userInput == "bash" || userInput == "attack" || userInput == "strike" || userInput == "hit" || userInput == "swing") {
            dealDamage();
        }
        else {
            hitPlayerRandomly(player);
            return;
        }
    }
    else if (weapon && weapon->getName() != "Sword") {
        std::cout << "You swing your " << weapon->getName() << " at Trechend, but it's not effective." << std::endl;
        handleLoss(player);
    }
    else {
        system("CLS");
        std::cout << "You are unarmed and defenseless. Ellen Trechend attacks you, striking you down swiftly." << std::endl << std::endl;
        handleLoss(player);
    }
}


void TrechendDialogue::dealDamage() {
    health--;
    std::cout << std::endl;
    switch(health) {
    case 0:
        system("CLS");
        std::cout << "Ellen Trechend lets out a final, agonizing cry as it succumbs to its injuries.";
        break;
    case 1:
        std::cout << "Battered and on the brink of defeat, the monstrosity struggles to stay upright.";
        break;
    case 2:
        std::cout << "The creature is now noticeably hurt, its movements becoming less coordinated.";
        break;
    case 3:
        std::cout << "Your attack leaves it visibly wounded, but it remains formidable ";
        break;
    case 4:
        std::cout << "Ellen Trechend winces in pain, showing the first signs of damage. ";
        break;
    default:
        break;
    }
    std::cout << std::endl;
    
}

bool TrechendDialogue::checkVictory() {
    return health <= 0;
}

void TrechendDialogue::defeatTrechend() {
    std::cout << "The giant monster tumbles to the ground. Lifeless, you chop off one of its heads and it rolls towards you on the ground." << std::endl;
    defeated = true;
    setNPCDefeated(true);
}

void TrechendDialogue::hitPlayerRandomly(Player& player) {
    const int numberOfWaysToHit = 5;
    int randomHit = std::rand() % numberOfWaysToHit;
    std::cout << std::endl;
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
    std::cout << std::endl;

    int remainingHits = health - 1;

    if (remainingHits <= 0) {
        std::cout << "You topple to the ground." << std::endl;
        handleLoss(player);
    }
    else {
        std::cout << "You can only take " << remainingHits << " more hits." << std::endl;
        system("pause");
    }
}

void TrechendDialogue::handleLoss(Player& player) {
    std::cout << "As you were struck down, your vision fades to black. The last thing you see is a black cat." << std::endl;
    std::cout << "A magical aura surrounds you, and you find yourself back before Trechend." << std::endl;

    system("pause");
    system("CLS");

    // Reset the battle and check if the player wants to continue fighting
    resetBattle();
    defeated = true; // Mark Trechend as defeated to exit the loop in startDialogue
    startDialogue(player);
}

void TrechendDialogue::startDialogue(Player& player) {
    defeated = false;
    resetBattle();

    // Prompt the user to decide whether to battle the monster
    int choice;
    do {
        std::cout << "The large vulture looks at you with all three of its heads. Would you like to fight it?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl << std::endl;

        std::cin >> choice;

        if (choice == 1) {
            break;
        }
        else if (choice == 2) {
            system("CLS");
            std::cout << "You chose not to battle Ellen Trechend right now." << std::endl;
            defeated = true;
            return;
        }
        else {
            std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while (true);

    promptUserForInstructions(player);

    while (!defeated) {
        if (checkVictory()) {
            defeatTrechend();
            break;
        }
        else {
            promptUserWithWords();
            processUserInput(player);
        }
    }
}


void TrechendDialogue::defeatedDialogue() {
    if (isNPCDefeated()) {
        std::cout << "The defeated Trechend lies motionless on the ground." << std::endl;
    }
}


