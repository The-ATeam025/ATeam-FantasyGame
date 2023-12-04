#include "TrechendDialogue.h"

/*
    TrechendDialogue();  - Constructor to initialize member variables

    ~TrechendDialogue(); - Destructor (if needed)



    void resetBattle(); - Reset the battle state

    void promptUserForInstructions(Player& player); - Display initial instructions to the player

    std::string promptUserWithWords(); - Generate and display a word for the player to type

    void processUserInput(Player& player); - Process the player's input during the battle

    void dealDamage();  - Decrease the monster's health and display corresponding messages

    bool checkVictory(); - Check if the player has defeated the monster

    void defeatTrechend(); - Display victory message and mark the monster as defeated

    void hitPlayerRandomly(Player& player); - Simulate a random attack from the monster

    void handleLoss(Player& player);  - Handle the player's loss in the battle

    void startDialogue(Player& player) override;  - Start the dialogue and initiate the battle

    void defeatedDialogue() override;  - Display dialogue when the monster is defeated

*/

TrechendDialogue::TrechendDialogue() : maxHealth(6), maxAttempts(3), health(maxHealth), defeated(false) {
    // Sets randomizer based on current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

TrechendDialogue::~TrechendDialogue() {}

void TrechendDialogue::resetBattle() {
    health = maxHealth;
    maxAttempts = 3;
    defeated = false;
}

void TrechendDialogue::promptUserForInstructions(Player& player) {
    system("CLS");
    std::cout << "You take a deep breath and step towards Ellen Trechend." << std::endl;
    std::cout << "The creature stares at you. All three heads speak in harmony, 'You have brought this upon yourself'" << std::endl << std::endl;
    Item* weapon = player.getWeaponSlot();
    if (weapon && weapon->getName() == "Sword") {
        std::cout << "A word will appear on the screen, type the word to deal damage to the monster." << std::endl;
        std::cout << "You have a very limited time for each attack. If you are not quick enough, the creature will be able to strike." << std::endl << std::endl;
        std::cout << "You draw your sword and prepare to battle the beast." << std::endl;
        system("pause");
        std::cout << std::endl;
    }
}

std::string TrechendDialogue::promptUserWithWords() {
    std::vector<std::string> battleWords = { "bash", "attack", "strike", "hit", "swing", "smite", "slam", "beat", "pound", "jab", "chop", "whack", };
    std::string promptWord = battleWords[std::rand() % battleWords.size()];

    int spacesBefore = std::rand() % 60; // Random number of spaces before the word
    std::string spacePadding(spacesBefore, ' ');

    std::cout << spacePadding << promptWord << std::endl;
    return promptWord;
}

void TrechendDialogue::processUserInput(Player& player) {
    std::string promptWord = promptUserWithWords();
    Item* weapon = player.getWeaponSlot();
    if (weapon && weapon->getName() == "Sword") {
        std::string userInput;

        //Starts time for input
        auto startTime = std::chrono::high_resolution_clock::now();
        std::cin >> userInput;
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();

        //Converts the input string to lower case and ignores spaces
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
        userInput.erase(std::remove_if(userInput.begin(), userInput.end(), ::isspace), userInput.end());


        // Adjust the timeout duration
        constexpr int timeoutDuration = 2;

        if (duration <= timeoutDuration && userInput == promptWord){
            dealDamage();
        }
        else if (duration >= timeoutDuration){
            std::cout << std::endl << "You could not react in time, leaving yourself open to the Vulture's attack." << std::endl;
            hitPlayerRandomly(player);
            return;
        }
        else {
            std::cout << std::endl << "You try to hit the beast, but you miss. The bird takes advantage of this mistake." << std::endl;
            hitPlayerRandomly(player);
            return;
        }

    }
    else if (weapon && weapon->getName() != "Sword") {
        system("CLS");
        std::cout << "You swing your " << weapon->getName() << " at the creature, but it's not effective." << std::endl;
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
        std::cout << "Ellen Trechend lets out a final, agonizing cry as it succumbs to its injuries.\n";
        system("pause");
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
    case 5:
        std::cout << "The monster shrugs the hit off, barely affected by your efforts. ";
    default:
        break;
    }
    std::cout << std::endl;
    
}

bool TrechendDialogue::checkVictory() {
    return health <= 0;
}

void TrechendDialogue::defeatTrechend() {
    system("CLS");
    std::cout << "As the player stands triumphant, the Ellen Trechend, wounded and on the verge of demise, offers its parting words, the voices of its three heads \nweaving a melancholic tapestry.\n" << std::endl;
    std::cout << "First Head speaks with a resonance akin to ancient echoes, 'Alas, mortal, the threads of our existence unravel before you.'" << std::endl;
    std::cout << "The Second Head, its words carrying a solemn weight, adds, 'Ancient understanding, now but whispers lost to the winds.'" << std::endl;
    std::cout << "The Third Head, its voice a haunting melody, laments, 'Hear the fading echoes of our wings, a disrupted realm in our wake.'" << std::endl << std::endl;
    std::cout << "First Head continues, 'No desire for conflict, yet destiny's winds have chosen a somber path.'" << std::endl << std::endl;
    std::cout << "The Second Head, with a tone of fading wisdom, intones, 'Feathers fall, wisdom dissipates with the boundless sky.'" << std::endl;
    std::cout << "The Third Head, a final plea in its voice, concludes, 'In demise, a reminder: balance falters when harmony's dance is disrupted.'" << std::endl << std::endl;
    std::cout << "The giant monster tumbles to the ground and its breath halts. With one last blow, the monster's teeth knock loose." << std::endl << std::endl;
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
        std::cout << "The beast flies towards you, knocking you to the ground. ";
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
        std::cout << "You dig your feet in, prepared to charge again." << std::endl;
        system("pause");
        std::cout << std::endl;
    }
}

void TrechendDialogue::handleLoss(Player& player) {
    std::cout << "As your vision fades to black, you see a black cat walking towards you on its hind legs." << std::endl;
    std::cout << "The cat whispers to you 'This will not be your final resting place.'" << std::endl << std::endl;
    std::cout << "A magical aura surrounds you, and you return before Ellen Trechend. It speaks to you as if you had never met." << std::endl;

    system("pause");
    system("CLS");

    // Reset the battle and check if the player wants to continue fighting
    resetBattle();
    defeated = true; // Mark as defeated to exit the loop in startDialogue
    startDialogue(player);
}

void TrechendDialogue::startDialogue(Player& player) {
    defeated = false;
    resetBattle();

    // Prompt the user to decide whether to battle the monster
    int choice;
    do {
        std::cout << "The creature's three heads turned in unison, eyes gleaming with a blend of wisdom and caution.\n" <<
            "\nThe first head, its voice resonant and echoing speaks, 'Wanderer, heed the warning of these ancient crags and the skies above."
            << "\nWe, the Ellen Trechend, guardians of the mystical realms, bear no quarrel with those who tread lightly.\n"
            << "\nThe second head, its words a solemn echo, continues, 'Yet, venture no closer, for the tapestry of our existence is woven with threads of "
            << "\nancient understanding. We do not seek conflict, but if you persist, the winds of fate may force our talons to defend the sanctity of these \ncelestial domains.'\n"
            << "\nThe third head, its voice like a haunting melody, added, 'Turn back, mortal, for within our wings lies both the shadow and the wisdom of eons."
            << "\nTread not the path of confrontation, for in our unity, we offer this plea: embrace the harmony of coexistence, or awaken the dormant storm \nthat slumbers within our avian hearts.'\n"
            << std::endl;
        std::cout << "1. Take a step forward" << std::endl;
        std::cout << "2. Head its warning" << std::endl << std::endl;

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
            std::cout << "You leave the creature to its own devices." << std::endl;
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
        std::cout << "The rest of its body fades into ash. The large pile is quickly picked up by the wind, dissipating in thousands of directions." << std::endl;
    }
}


