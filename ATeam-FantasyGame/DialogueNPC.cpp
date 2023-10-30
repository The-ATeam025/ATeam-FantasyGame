#include "DialogueNPC.h"

bool DialogueNPC::isNPCDefeated(){
    return NPCDefeated;
}

void DialogueNPC::setNPCDefeated(bool defeated) {
    NPCDefeated = defeated;
}