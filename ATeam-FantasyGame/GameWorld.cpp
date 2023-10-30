#include "GameWorld.h"


//Constructor
GameWorld::GameWorld() : courtyard(nullptr), greatHall(nullptr), redCapDungeon(nullptr) {}


void GameWorld::init(Player& player) {
    // Initialize locations
    courtyard = new Location("Courtyard",
        "You find yourself surrounded by a circle of dead grass replacing the mushrooms that brought you here. The air is filled with an otherworldly energy, and the sun is hidden behind the clouds");
    greatHall = new Location("Great Hall",
        "You step into a grand chamber adorned with towering arches and elaborately decorated walls. A sense of history and mystery fills the air.");
    redCapDungeon = new Location("Dungeon",
        "The air is damp and cold, and the stench of decay lingers in the underground chamber. An unsettling feeling creeps over you. ");

    // Create an item
    // "Name", "Description", "Equipment Slot - If none, leave as null"
    Item* rustyKey = new Item("Rusty Key", "A normal looking key, besides the rust covering its surface", "hands");
    Item* celticCross = new Item("Celtic Cross", "An ornate, ancient cross symbolizing Celtic heritage and spirituality", "hands");

    // Create an NPC
    NPC* redCap = new NPC("Redcap", 
        "Its skin is as red as fresh blood, and its eyes gleam with sinister intent. Dressed in tattered rags, it carries an aura of malevolence.");

    // Add all NPCs to the npcs list
    npcs.push_back(redCap);

    // Initalize Dialogues
    DialogueNPC* DialogueRedCap = new redCapDialogue();

    // Add items/Dialogue/lcoation to NPC

    // Redcap
    redCap->setItem(rustyKey);
    redCap->setLocation(redCapDungeon);
    redCap->setDialogue(DialogueRedCap);

    // Connect the locations
    courtyard->addConnectedLocation(greatHall);

    greatHall->addConnectedLocation(courtyard);
    greatHall->addConnectedLocation(redCapDungeon);

    redCapDungeon->addConnectedLocation(greatHall);

    // Add items to locations

    // Great Hall
    greatHall->addItem(celticCross);

    // Locate NPCs in their locations

    // Set the player's initial location
    player.walkToLocation(courtyard);
}

Location* GameWorld::getCourtyard() { return courtyard; }
Location* GameWorld::getGreatHall() { return greatHall; }
Location* GameWorld::getRedCapDungeon() { return redCapDungeon; }

void GameWorld::addNPC(NPC* npc) {
    npcs.push_back(npc);
}

std::list<NPC*> GameWorld::getNPCsInLocation(const Location* location) {
    list<NPC*> locationNPCs;
    for (NPC* npc : npcs) {
        if (npc->getCurrentLocation() == location) {
            locationNPCs.push_back(npc);
        }
    }
    return locationNPCs;
}
