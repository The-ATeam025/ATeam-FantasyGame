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

std::string TrechendDialogue::promptUserWithWords() {
    std::vector<std::string> battleWords = { "bash", "attack", "strike", "hit", "swing" };
    std::string promptWord = battleWords[std::rand() % battleWords.size()];

    int spacesBefore = std::rand() % 40; // Random number of spaces before the word
    std::string spacePadding(spacesBefore, ' ');

    std::cout << spacePadding << promptWord << std::endl;
    return promptWord;
}

void TrechendDialogue::processUserInput(Player& player) {
    std::string promptWord = promptUserWithWords();
    Item* weapon = player.getWeaponSlot();
    if (weapon && weapon->getName() == "Sword") {
        std::string userInput;
        auto startTime = std::chrono::high_resolution_clock::now();
        std::cin >> userInput;
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
        userInput.erase(std::remove_if(userInput.begin(), userInput.end(), ::isspace), userInput.end());


        // Adjust the timeout duration as needed
        constexpr int timeoutDuration = 2;

        if (duration <= timeoutDuration && userInput == promptWord){
            dealDamage();
        }
        else {
            std::cout << std::endl << "You could not react in time, leaving yourself open to the Vulture's attack." << std::endl;
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
    std::cout << "The giant monster tumbles to the ground. Needing proof of your victory, you chop off one of its heads. It rolls towards you on the ground." << std::endl << std::endl;
    defeated = true;
    setNPCDefeated(true);
}

void TrechendDialogue::hitPlayerRandomly(Player& player) {
    const int numberOfWaysToHit = 5;
    int randomHit = std::rand() % numberOfWaysToHit;
    std::cout << std::endl;
    switch (randomHit) {
    case 0:
        std::cout << "The Vulture spreads its claws and swings at you. ";
        break;
    case 1:
        std::cout << "The monster rears one of its head back and bites you. ";
        break;
    case 2:
        std::cout << "Ellen Trechend spits venom at you. ";
        break;
    case 3:
        std::cout << "The creature tail-slaps you. ";
        break;
    case 4:
        std::cout << "The beast flies in towards you, knocking you to the ground. ";
        break;
    default:
        break;
    }
    std::cout << std::endl;

    maxAttempts--;
  
    if (maxAttempts <= 1) {
        std::cout << "You topple to the ground, unable to stand back up." << std::endl;
        system("pause");
        system("CLS");
        handleLoss(player);
    }
    else {
        std::cout << "You are badly beaten. The monster is much stronger than you, and you know you cannot be hit by it again." << std::endl;
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

        while (!(cin >> choice) || cin.peek() != '\n' || choice < 0 || choice > 2 ){
            // Handle non-numeric input or input with spaces
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a non-spaced, numeric value listed." << endl << endl;
        }

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
            processUserInput(player);
        }
    }
}


void TrechendDialogue::defeatedDialogue() {
    if (isNPCDefeated()) {
        std::cout << "The defeated monster dissolves into dush, leaving only the severed head on the ground." << std::endl;
    }
}


