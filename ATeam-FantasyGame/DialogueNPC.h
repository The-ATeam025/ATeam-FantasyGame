#pragma once

//Defines all the class for NPC Dialogue that can then be redefined in a derived class for multiple NPC's
//Allows for each NPC to have different dialogue that can be created in multiple cpp's and worked
//on at the same time

//@Jack

class Dialogue {
public:
    virtual void startDialogue() = 0;
};