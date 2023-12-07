#include "GameWorld.h"

//Constructor
GameWorld::GameWorld() : courtyard(nullptr), greatHall(nullptr), redCapDungeon(nullptr), banquetHall(nullptr), armory(nullptr), outside(nullptr), nest(nullptr), meadow(nullptr), bridge(nullptr), swamp(nullptr), crossedBridge(nullptr), lake(nullptr), lake1(nullptr), crossedLake(nullptr), goddessDwelling(nullptr) {}

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
    delete lake1;
    delete crossedLake;
    delete bridge;
    delete bridge1;
    delete goddessDwelling;
}



void GameWorld::init(Player& player) {
    // Initialize locations
    crossedBridge = new Location("other side of the bridge", "As you cross the bridge, bridle in hand, you notice thick fog gathering around you. \nWhen you get to the other side and turn to wave goodbye to the troll, you notice that the bridge has been entirely enshrouded in the mist. \nAhead of you lies a gloomy-looking lake. ");
    lake = new Location("Lake", "A scaled horse-like creature is standing on the lake's rocky shore. You realize that this must be the kelpie, and prepare to capture it.", lake1);
    lake1 = new Location("Lake", "Now subdued, the kelpie bends its head, as if inviting you onto its back. you on its back as a way reaching your next destination.");
    crossedLake = new Location("Other side of the lake", "The Kelpie is lending its back to you as a way to cross the gloomy lake. In the distance you notice land that fits the description of Aine's domain and you decided to approach the mysterious shore.");
    swamp = new Location("Swamp", "The swamp is a quiet expanse of twisted trees and still waters, alive with the hums of insects and the croaks of hidden creatures. Thick vines grow from the trees.");
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
        "A refreshing breeze hits your face, in stark contrast to the musty air of the castle. A meadow lies ahead, and you can see a forest in the distance.");
    meadow = new Location("Meadow", "The meadow contains fields of wildflowers and tall grasses. The wind blows through them, making a soft rustling noise.");
    bridge1 = new Location("Bridge", "Same bridge. The troll has lumbered off back to his tree stump.");
    bridge = new Location("Bridge",
        "The landscape becomes more and more swampy, until it becomes an impassable marsh. \nAn old stone bridge connects this wetland to whatever lies up ahead, but it is guarded by a troll.", bridge1);
    nest = new Location("Nest",
        "A colossal intertwining of twisted branches, their gnarled forms interwoven with moss-covered stones weathered by the passage of countless seasons.\nWithin this labyrinthine structure, ethereal feathers, shimmering like the moonlit night, are delicately entwined");
    goddessDwelling = new Location("The Goddess's Dwelling", "A celestial sanctuary, adorned with vibrant blossoms and other ethereal flora. \nThe air is filled with the sweet fragrance of blooming flowers");
   
    // Create an item
    // "Name", "Description", "Equipment Slot - If none, leave as none"
    Item* rustyKey = new Item("Rusty Key", "A normal looking key, besides the rust covering its surface.", "hands");
    Item* celticCross = new Item("Celtic Cross", "An ornate, ancient cross symbolizing Celtic heritage and spirituality.", "hands");
    Item* sword = new Item("Sword", "A sharp and sturdy sword for combat.", "hands");
    Item* helmet = new Item("Helmet", "A protective helmet for your head.", "head");
    Item* carrot = new Item("Carrot", "Normal looking carrot","hands");
    Item* trechenTooth = new Item("Tooth", "One of the monster's teeth", "none");
    Item* vine = new Item("Vine", "Thick piece of flexible vine a few feet long", "hands");

    // Create room Objects
    Objects* armoryChest = new ArmoryChest("Chest", "An old chest that has had its surface almost compleltely consumed by moss.");
    Objects* MarbleBust = new marbleBust("Marble Bust", "A pristine looking statued of a head you do not recognize. Its eyes somehow seem to follow you around.", outside); 
    Objects* kelpie = new Kelpie("Kelpie", "A scaled, horse-like creature with glowing red eyes is watching your every movement from the shore.", crossedLake);
    //Send hidden location
    // 
    // 
    
    // Create an NPC
    NPC* redCap = new NPC("Redcap", 
        "Its skin is as red as fresh blood, and its eyes gleam with sinister intent. Dressed in tattered rags, it carries an aura of malevolence.");
    NPC* fairies = new NPC("Fairies",
        "Winged humanoid figures seated at a table, their radiant wings shimmering in the dim candlelight, laughing in hushed tones.\nDisturbingly enough, you notice their unnatural amount of sharp teeth.");
    NPC* oneEyedHare = new NPC("One Eyed Hare",
        "The one-eyed hare, with its silvery coat, sniffs the air curiously. Its one emerald eye makes direct eye contact with you.");
    NPC* troll = new NPC("Troll",
        "Sitting on an old tree stump. The troll's face is craggy and weathered, like an old boulder, with a crooked nose and small eyes. \n His frown is almost permanent, etched into his face by countless years of irritation at passerbys.");
    NPC* Trechend = new NPC("Mythical Bird",
        "A colossal vulture with three regal heads catches your gaze. Towering wings, adorned with mystic symbols, stretch majestically, \ncasting shadows that ripple across the landscape.");
    NPC* Goddess = new NPC("Aine", "A radiant figure with flowing golden hair, adorned in a shimmering white and blue mantle.");

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
    objects.push_back(kelpie);

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

    // kelpie
    kelpie->setLocation(lake);

    // Connect the locations
    courtyard->addConnectedLocation(greatHall);

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
    swamp->addConnectedLocation(meadow);

    bridge->addConnectedLocation(swamp);
    bridge1->addConnectedLocation(crossedBridge);
    crossedBridge->addConnectedLocation(lake);

    lake1->addConnectedLocation(crossedLake);
    crossedLake->addConnectedLocation(goddessDwelling);
    
    nest->addConnectedLocation(goddessDwelling);
    goddessDwelling->addConnectedLocation(nest);

    // Add pre-existing items to locations

    // Great Hall
    greatHall->addItem(celticCross);

    //Outside
    meadow->addItem(carrot);

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
