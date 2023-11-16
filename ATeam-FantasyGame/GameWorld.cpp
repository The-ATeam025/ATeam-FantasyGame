#include "GameWorld.h"

//Constructor
GameWorld::GameWorld() : courtyard(nullptr), greatHall(nullptr), redCapDungeon(nullptr), banquetHall(nullptr), armory(nullptr), outside(nullptr), swamp(nullptr) {}

//Deconstructor
GameWorld::~GameWorld() {
    // Delete the dynamically allocated locations (if they exist)
    delete courtyard;
    delete greatHall;
    delete redCapDungeon;
    delete banquetHall;
    delete armory; // Include this line if armory is dynamically allocated

    // You might also need to delete other dynamically allocated resources
    // related to the game world, like NPCs, items, dialogues, etc.
}

void GameWorld::init(Player& player) {
    // Initialize locations
    courtyard = new Location("Courtyard",
        "You find yourself surrounded by a circle of dead grass replacing the mushrooms that brought you here. The air is filled with an otherworldly energy, and the sun is hidden behind the clouds");
    greatHall = new Location("Great Hall",
        "You step into a grand chamber adorned with towering arches and elaborately decorated walls. A sense of history and mystery fills the air.");
    redCapDungeon = new Location("Dungeon",
        "The air is damp and cold, and the stench of decay lingers in the underground chamber. An unsettling feeling creeps over you. ");
    banquetHall = new Location("Banquet Hall",
        "The doors of this magnificent banquet hall are slightly tilted, but you can see light and hear laughter coming from within.");
    armory = new Location("Armory",
        "In the armory, all that remains is a lonely chest. The nearby shelves are bare, and must have already been looted by someone or something.");
    outside = new Location("Outside",
        "An untamed, enigmatic forest lies ahead, teeming with otherwordly magic and energy you have never experienced.");
         swamp = new Location("Swamp",
        "The Culra Swamp is a quiet expanse of twisted trees and still waters, alive with the hums of insects and the croaks of hidden creatures. Light filters through the canopy, casting shifting shadows across the landscape.");

    // Create an item
    // "Name", "Description", "Equipment Slot - If none, leave as null"
    Item* rustyKey = new Item("Rusty Key", "A normal looking key, besides the rust covering its surface.", "hands");
    Item* celticCross = new Item("Celtic Cross", "An ornate, ancient cross symbolizing Celtic heritage and spirituality.", "hands");
    Item* sword = new Item("Sword", "A sharp and sturdy sword for combat.", "hands");
    Item* helmet = new Item("Helmet", "A protective helmet for your head.", "head");
    Item* carrot = new Item("carrot", "Normal looking carrot","hands");


    // Create room Objects
    Objects* armoryChest = new ArmoryChest("Chest", "An old chest that has had its surface almost compleltely consumed by moss.");
    Objects* MarbleBust = new marbleBust("Marble Bust", "A pristine looking statued of a head you do not recognize. It's eyes somehow seem to follow you around.", outside);
    
    // Create an NPC
    NPC* redCap = new NPC("Redcap", 
        "Its skin is as red as fresh blood, and its eyes gleam with sinister intent. Dressed in tattered rags, it carries an aura of malevolence.");
    NPC* fairies = new NPC("Fairies",
        "Winged humanoid figures seated at a table, their radiant wings shimmering in the dim candlelight, laughing in hushed tones. Disturbingly enough, you notice their unnatural amount of sharp teeth.");
    NPC* oneEyedHare = new NPC("One Eyed Hare",
        "The one-eyed hare, with its silvery coat, moves gracefully through the forest, its solitary emerald eye gleaming with a mysterious wisdom.");


    // Add all NPCs to the npcs list
    npcs.push_back(redCap);
    npcs.push_back(fairies);
    npcs.push_back(oneEyedHare);

    // Add all objects to the objects list
    objects.push_back(armoryChest);
    objects.push_back(MarbleBust);

    // Initalize Dialogues
    DialogueNPC* DialogueRedCap = new redCapDialogue();
    DialogueNPC* Dialoguefairies = new fairyDialogue();
    DialogueNPC* DialogueOneEyedHare = new hareDialogue();

    // Add items/Dialogue/location to NPC/Object
    // Redcap
    redCap->setItem(rustyKey);
    redCap->setLocation(redCapDungeon);
    redCap->setDialogue(DialogueRedCap);

    // Fairies
    fairies->setLocation(banquetHall);
    fairies->setDialogue(Dialoguefairies);

    // armoryChest
    armoryChest->setLocation(armory);
    armoryChest->addItemToInventory(sword);
    armoryChest->addItemToInventory(helmet);

    // MarbleBust
    MarbleBust->setLocation(greatHall);

    // One Eyed Hare
    oneEyedHare->setLocation(swamp);
    oneEyedHare->setDialogue(DialogueOneEyedHare);

    // Connect the locations
    courtyard->addConnectedLocation(greatHall);

    greatHall->addConnectedLocation(banquetHall);
    greatHall->addConnectedLocation(courtyard);
    greatHall->addConnectedLocation(armory);

    armory->addConnectedLocation(greatHall);

    redCapDungeon->addConnectedLocation(banquetHall);

    banquetHall->addConnectedLocation(greatHall);
    banquetHall->addConnectedLocation(redCapDungeon);
    testing: banquetHall->addConnectedLocation(outside);


    outside->addConnectedLocation(greatHall);
    outside->addConnectedLocation(swamp);

    swamp->addConnectedLocation(outside);

    // Add pre-existing items to locations

    // Great Hall
    greatHall->addItem(celticCross);

    //Outside
    outside->addItem(carrot);

    // Set the player's initial location
    player.walkToLocation(courtyard);
}

Location* GameWorld::getCourtyard() { return courtyard; }
Location* GameWorld::getGreatHall() { return greatHall; }
Location* GameWorld::getRedCapDungeon() { return redCapDungeon; }
Location* GameWorld::getBanquetHall() { return banquetHall; }
Location* GameWorld::getOutside() { return outside; }
Location* GameWorld::getSwamp() { return swamp; }



// Add's NPC's to the GameWorld instance
void GameWorld::addNPC(NPC* npc) {
    npcs.push_back(npc);
}

void GameWorld::addObject(Objects* object) {
    objects.push_back(object);
}

// Allows for the UI to check for if a certain NPC is in an area
std::list<NPC*> GameWorld::getNPCsInLocation(const Location* location) {
    list<NPC*> locationNPCs;
    for (NPC* npc : npcs) {
        if (npc->getCurrentLocation() == location) {
            locationNPCs.push_back(npc);
        }
    }
    return locationNPCs;
}

// Allows for the UI to check for if a certain Object is in an area
std::list<Objects*> GameWorld::getObjectsInLocation(const Location* location) {
    std::list<Objects*> locationObjects;

    for (Objects* obj : objects) {
        if (obj->getCurrentLocation() == location) {
            locationObjects.push_back(obj);
        }
    }

    return locationObjects;
}