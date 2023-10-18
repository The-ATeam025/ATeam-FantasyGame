#ifndef BACKSTORY_H
#define BACKSTORY_H

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>

class Backstory {
public:
    Backstory(); // Constructor
    void displayIntro();
    void ApproachMushroomRing();

private:
    void displayTextAndWait(const std::string& text);
    void wrap(const std::string& input, size_t width, std::ostream& os, size_t indent = 0);
    void wait(int seconds);
};

#endif // BACKSTORY_H
