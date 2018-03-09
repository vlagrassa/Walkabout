#include "EncounterScreen.hpp"
#include <SFML/Graphics.hpp>
#include "../region/Treasure.hpp"

TreasureScreen::TreasureScreen(GameInfo& defaults, int seed) :
        //Room(seed, window) //This is the ideal but throws seg fault, for some reason
        Room(defaults, (seed%15)+42, genRandomEncounterable(defaults, seed))
{}

TreasureScreen::TreasureScreen(const TreasureScreen& orig) : Room(orig) {
    
}

TreasureScreen::~TreasureScreen() {
    
}

std::string TreasureScreen::testThing() {
    return "This is a treasure screen!";
}

Encounterable& TreasureScreen::genRandomEncounterable(GameInfo& defaults, unsigned int seed) {
    return *new Treasure(defaults.window);
}
