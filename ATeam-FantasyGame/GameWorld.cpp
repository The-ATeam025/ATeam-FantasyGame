#include "GameWorld.h"

//Constructor
GameWorld::GameWorld() : courtyard(nullptr), greatHall(nullptr), redCapDungeon(nullptr), banquetHall(nullptr), armory(nullptr), outside(nullptr), nest(nullptr), meadow(nullptr), bridge(nullptr), swamp(nullptr), crossedBridge(nullptr), lake(nullptr), goddessDwelling(nullptr) {}

//Deconstructor
GameWorld::~GameWorld() {
    // Delete the dynamically allocated locations (if they exist)
    delete courtyard;
    delete greatHall;
    delete redCapDungeon;
    delete banquetHall;
    delete armory;
    delete swamp;
    delete nest;
    delete crossedBridge;
    delete lake;
    delete bridge;
    delete bridge1;
    delete goddessDwelling;
}



void GameWorld::init(Player& player) {
    // Initialize locations
    crossedBridge = new Location("Other side of the bridge", "As you cross the bridge, bridle in hand, you notice a thick fog gather around you. When you get to the other side and turn to wave goodbye to the troll, you notice that the bridge has been entirely enshrouded in the mist. Ahead of you lies a gloomy-looking lake. ");
    lake = new Location("Lake", "You see a kelpie in the lake, and prepare to capture it.");
    swamp = new Location("Swamp", "The Culra Swamp is a quiet expanse of twisted trees and still waters, alive with the hums of insects and the croaks of hidden creatures. Thick vines grow from the trees.");
    courtyard = new Location("Courtyard",
        "You find yourself surrounded by a circle of dead grass replacing the mushrooms that brought you here. The air is filled with an otherworldly energy, and the sun is hidden behind the clouds");
    greatHall = new Location("Great Hall",
        "You step into a grand chamber adorned with towering arches and elaborately decorated walls. A sense of history and mystery fills the air.");
    redCapDungeon = new Location("Dungeon",
        "The air is damp and cold, and the stench of decay lingers in the underground chamber. An unsettling feeling creeps over you. ");
    banquetHall = new Location("Banquet Hall",
        "The doors of this magnificent banquet hall are slightly tilted, but you can see light and hear laughter coming from within.", swamp);
    armory = new Location("Armory",
        "In the armory, all that remains is a lonely chest. The nearby shelves are bare, and must have already been looted by someone or something.");
    outside = new Location("Outside",
        "An untamed, enigmatic forest lies ahead, teeming with otherwordly magic and energy you have never experienced.");
    meadow = new Location("Meadow", "You see a pretty meadow.");
    bridge1 = new Location("Bridge", "Same bridge. he troll has lumbered off into the distance.");
    bridge = new Location("Bridge",
        "The landscape becomes more and more rugged and swampy, until it becomes an impassable marsh. A wooden bridge connects this wetland to whatever lies up ahead, but it is guarded by a troll.", bridge1);
    nest = new Location("Nest",
        "A colossal intertwining of twisted branches, their gnarled forms interwoven with moss-covered stones weathered by the passage of countless seasons.\nWithin this labyrinthine structure, ethereal feathers, shimmering like the moonlit night, are delicately entwined");
    goddessDwelling = new Location("The Goddess's Dwelling", "A celestial sanctuary, adorned with vibrant blossoms and iridescent flora. The air is filled with the sweet fragrance of blooming flowers");
    //  crossedBridge = new Location("Other side of the bridge","As you cross the bridge, bridle in hand, you notice a thick fog gather around you. When you get to the other side and turn to wave goodbye to the troll, you notice that the bridge has been entirely enshrouded in the mist. Ahead of you lies a gloomy-looking lake. ");
    
    // Create an item
    // "Name", "Description", "Equipment Slot - If none, leave as none"
    Item* rustyKey = new Item("Rusty Key", "A normal looking key, besides the rust covering its surface.", "hands");
    Item* celticCross = new Item("Celtic Cross", "An ornate, ancient cross symbolizing Celtic heritage and spirituality.", "hands");
    Item* sword = new Item("Sword", "A sharp and sturdy sword for combat.", "hands");
    Item* helmet = new Item("Helmet", "A protective helmet for your head.", "head");
    Item* carrot = new Item("carrot", "Normal looking carrot","hands");
    Item* trechenTooth = new Item("Tooth", "One of Ellen Trechend's teeth", "none");
    Item* vine = new Item("Vine", "Thick piece of flexible vine a few feet long", "hands");

    // Create room Objects
    Objects* armoryChest = new ArmoryChest("Chest", "An old chest that has had its surface almost compleltely consumed by moss.");
    Objects* MarbleBust = new marbleBust("Marble Bust", "A pristine looking statued of a head you do not recognize. It's eyes somehow seem to follow you around.", outside);
    
    //Send hidden location
    // 
    // 
    
    // Create an NPC
    NPC* redCap = new NPC("Redcap", 
        "Its skin is as red as fresh blood, and its eyes gleam with sinister intent. Dressed in tattered rags, it carries an aura of malevolence.");
    NPC* fairies = new NPC("Fairies",
        "Winged humanoid figures seated at a table, their radiant wings shimmering in the dim candlelight, laughing in hushed tones. Disturbingly enough, you notice their unnatural amount of sharp teeth.");
    NPC* oneEyedHare = new NPC("One Eyed Hare",
        "The one-eyed hare, with its silvery coat, sniffs the air curiously. Its one emerald eye makes direct eye contact with you.");
    NPC* troll = new NPC("Troll",
        "Sitting on an old tree stump. The troll's face is craggy and weathered, like an old boulder, with a crooked nose and deep-set eyes. His frown is almost permanent, etched into his face by countless years of solitude and the irritation of the rare disturbances caused by passersby.");
    NPC* Trechend = new NPC("Mythical Bird",
        "A colossal vulture with three regal heads catches your gaze. Towering wings, adorned with mystic symbols, stretch majestically, \ncasting shadows that ripple across the landscape.");
    NPC* Goddess = new NPC("Aine", "A radiant figure with flowing golden hair, adorned in a shimmering gown");

    // Add all NPCs to the npcs list
    npcs.push_back(redCap);
    npcs.push_back(fairies);
    npcs.push_back(oneEyedHare);
    npcs.push_back(Trechend);
    npcs.push_back(Goddess);
    npcs.push_back(troll);

    // Add all objects to the objects list
    objects.push_back(armoryChest);
    objects.push_back(MarbleBust);

    // Initalize Dialogues
    DialogueNPC* DialogueRedCap = new redCapDialogue();
    DialogueNPC* Dialoguefairies = new fairyDialogue();
    DialogueNPC* DialogueOneEyedHare = new hareDialogue();
    DialogueNPC* DialogueTrechend = new TrechendDialogue();
    DialogueNPC* DialogueGoddess = new GoddessDialogue();
    DialogueNPC* DialogueTroll = new trollDialogue();

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
    oneEyedHare->setLocation(meadow);
    oneEyedHare->setDialogue(DialogueOneEyedHare);

    // Ell�n Trechend
    Trechend->setLocation(nest);
    Trechend->setItem(trechenTooth);
    Trechend->setDialogue(DialogueTrechend);

    // Goddess
    // Test - 
    Goddess->setLocation(goddessDwelling);
    Goddess->setDialogue(DialogueGoddess);

    // troll
    troll->setLocation(bridge);
    troll->setDialogue(DialogueTroll);

    // Connect the locations
    courtyard->addConnectedLocation(greatHall);
    // delete after testing
    courtyard->addConnectedLocation(bridge);

    
    greatHall->addConnectedLocation(banquetHall);
    greatHall->addConnectedLocation(courtyard);
    greatHall->addConnectedLocation(armory);

    armory->addConnectedLocation(greatHall);

    redCapDungeon->addConnectedLocation(banquetHall);

    banquetHall->addConnectedLocation(greatHall);
    banquetHall->addConnectedLocation(redCapDungeon);
    
    outside->addConnectedLocation(greatHall);
    outside->addConnectedLocation(meadow);

    meadow->addConnectedLocation(outside);
    meadow->addConnectedLocation(swamp);
    swamp->addConnectedLocation(bridge);

    bridge->addConnectedLocation(swamp);
    bridge1->addConnectedLocation(crossedBridge);
    crossedBridge->addConnectedLocation(lake);
    
    nest->addConnectedLocation(goddessDwelling);
    goddessDwelling->addConnectedLocation(nest);

    // Add pre-existing items to locations

    // Great Hall
    greatHall->addItem(celticCross);

    //Outside
    outside->addItem(carrot);

    //Meadow
    swamp->addItem(vine);

    // Set the player's initial location
    player.walkToLocation(courtyard);

    // Test for battle
    //player.wearItem(sword, "hands");
    //nest->addItem(trechenTooth);
    //player.walkToLocation(nest);
}

Location* GameWorld::getCourtyard() { return courtyard; }
Location* GameWorld::getGreatHall() { return greatHall; }
Location* GameWorld::getRedCapDungeon() { return redCapDungeon; }
Location* GameWorld::getBanquetHall() { return banquetHall; }
Location* GameWorld::getOutside() { return outside; }
Location* GameWorld::getSwamp() { return meadow; }
Location* GameWorld::getBridge() { return bridge; }
Location* GameWorld::getMeadow() { return swamp; }



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
