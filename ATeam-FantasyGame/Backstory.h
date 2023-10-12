#ifndef BACKSTORY_H
#define BACKSTORY_H

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>

using namespace std;

class Backstory {
public:
    Backstory() {}

    // Display the game introduction
    void displayIntro() {

        // Define the introduction texts
        string introTexts[6] = {
            "It is summer vacation, and you are visiting Ireland. You have been looking forward to sight-seeing for a while now. You decided to take a tour of Blarney Castle, a medieval stronghold",
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

        // Prompt user for input to continue the introduction
        system("pause");
        cout << "\n";

        // Transition to the next phase of the story
        ApproachMushroomRing();
    }

    // Describe the moment of stepping into the mushroom ring
    void ApproachMushroomRing() {
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

        system("pause");
        cout << "\n";
    }

    // Function to display text and delay between displaying it
    void displayTextAndWait(const std::string& text) {
        wrap(text, 130, cout, 0);
        cout << endl << endl;

        // Pause for 4 seconds between outputting text.
        wait(4);

    }

    // Function to wrap text to a specified width to avoid wrapping
    void wrap(const std::string& input, size_t width, std::ostream& os, size_t indent = 0) {
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

    // Function to pause the program for a specified duration in seconds
    void wait(int seconds) {

        // std::this_thread::sleep_for is used to pause execution for a specific duration
        std::this_thread::sleep_for(seconds * 1s);
    }
};

#endif // BACKSTORY_H
