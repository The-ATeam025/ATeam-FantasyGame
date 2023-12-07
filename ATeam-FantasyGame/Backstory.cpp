#include "backstory.h"

using namespace std;

Backstory::Backstory() {
    // Constructor - Initialize the Backstory object
}

void Backstory::displayIntro() {
    // Display the game introduction

    // Define the introduction texts
    string introTexts[6] = {
        "It is summer vacation, and you are visiting Ireland. You have been looking forward to sightseeing for a while now. You decided to take a tour of Blarney Castle, a medieval stronghold",
        "You have reached the Grand Hall. You can see a door leading outside and suddenly, you want to take a breath of fresh air. You step away from the tour group and make your way outside.",
        "You see a stone path into the garden and decide to take it. When looking down, you are now next to a large ring of mushrooms.",
        "The mushroom circle before you beckons with an eerie allure. The air around it crackles with a strange, otherworldly energy, and you feel a compelling urge to step closer.",
        "Each footfall is a heartbeat, your senses heightened by the anticipation of what awaits.",
        "You swallow hard, wondering whether to continue or turn back. But curiosity prevails, and you find yourself taking another step closer."
    };

    // Loop through and display each intro text
    for (const string& introText : introTexts) {
        displayTextAndWait(introText);
    }

    // Pause to allow the player to read the introduction
    system("pause");
    cout << "\n";

    // Transition to the next phase of the story
    ApproachMushroomRing();
}

void Backstory::ApproachMushroomRing() {
    // Describe the moment of stepping into the mushroom ring

    // Define the approach texts
    string approachTexts[3] = {
        "With each step, your heart beats louder in your chest. The world around you seems to blur, the forest fading into obscurity. You're now standing at the very edge of the mystical ring, tingling with anticipation.",
        "As you take one final, hesitant step into the ring, a powerful gust of wind envelops you. The air is thick with an ancient presence, and you feel an irresistible force pulling you toward the center. Your surroundings spin, and reality itself seems to unravel.",
        "You are surrounded by a kaleidoscope of colors and sounds. Whispers fill the air as you are transported into a realm unknown.",
    };

    // Loop through and display each approach text
    for (const string& approachText : approachTexts) {
        displayTextAndWait(approachText);
    }

    // Pause to allow the player to read the description
    system("pause");
    cout << "\n";
}

void Backstory::displayTextAndWait(const std::string& text) {
    // Function to display text and pause between displaying it

    // Wrap the text to fit a specified width and output it
    wrap(text, 130, cout, 0);
    cout << endl << endl;

    // Pause for 2 seconds between outputting text
    wait(2);
}

void Backstory::wrap(const std::string& input, size_t width, std::ostream& os, size_t indent) {
    // Function to wrap text to a specified width to avoid text overflow

    std::istringstream in(input); // Create a string stream to read the input text
    os << std::string(indent, ' '); // Output the specified indentation
    size_t current = indent; // Initialize the current line width
    std::string word; // Initialize a variable to store each word

    while (in >> word) { // Iterate through each word in the input
        if (current + word.size() > width) { // If adding the word exceeds the line width
            os << "\n" << std::string(indent, ' '); // Start a new line with the specified indentation
            current = indent; // Reset the current line width
        }
        os << word << ' '; // Output the word followed by a space
        current += word.size() + 1; // Update the current line width
    }
}

void Backstory::wait(int seconds) {
    // Function to pause the program for a specified duration in seconds

    // std::this_thread::sleep_for is used to pause execution for a specific duration
    std::this_thread::sleep_for(seconds * 1s);
}

void Backstory::epilogue() {
    // Display the epilogue of the game
    system("CLS");
    
    // Define the epilogue texts
    string epilogueTexts[5] = {
        "As you stand within the mystical ring, the goddess manifests before you. A warm light surrounds her, and her presence exudes tranquility.",
        "With a gentle smile, she opens a portal that shimmers with ethereal energy. The portal is your gateway back to the world you know.",
        "Stepping through the portal, you find yourself back at Blarney Castle. The familiar sights and sounds of the tour group greet you, but your memory is hazy.",
        "You finish your tour, and your mind still feels disconnected from the rest of your body. You can tell you do not remember something, but you are unable to figure out what it may be.",
        "In the days that follow, you often see dreamlike visions of the otherworldly realm. The experiences linger in your mind, just out of grasp, like fragments of a fading dream."
    };

    // Loop through and display each epilogue text
    for (const string& epilogueText : epilogueTexts) {
        displayTextAndWait(epilogueText);
    }

    system("pause");

    // Mention the recurring vision and the black cat
    string epilogueTexts2[4] = {
        "\nYou notice that visions of your otherworldly experiences continue to visit you in dreams, elusive and fleeting.",
        "Among these dreams, a black cat with a curiously familiar expression often appears, offering a mysterious comfort.",
        "You disregard this, thinking it to be some random manifestation of your subconscious. You go about your life, still feeling like there is a part of you lost to your subconscious.",
        "That is until you see that same cat, sitting in front of your house. It almost looks like it is watching out for you."
    };

    for (const string& epilogueText : epilogueTexts2) {
        displayTextAndWait(epilogueText);
    }

    // Pause to allow the player to read the epilogue
    system("pause");
    system("CLS");

    cout << "Thank you for playing! This was a student project created by: \nJack\nWeronika\nMelissa\nTim\nRob\nValerie";
    cout << "\n\n Press any button to close the game";
    exit(0);
}
