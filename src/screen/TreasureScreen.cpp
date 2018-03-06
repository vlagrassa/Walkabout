#include "EncounterScreen.hpp"
#include <SFML/Graphics.hpp>
#include "../region/Treasure.hpp"

TreasureScreen::TreasureScreen(Player& player, int seed, Ambience& ambience, sf::Window& window) :
        //Room(seed, window) //This is the ideal but throws seg fault, for some reason
        Room(player, (seed%15)+42, genRandomEncounterable(seed, window, ambience))
{}

TreasureScreen::TreasureScreen(const TreasureScreen& orig) : Room(orig) {
    
}

TreasureScreen::~TreasureScreen() {
    
}

std::string TreasureScreen::testThing() {
    return "This is a treasure screen!";
}

Encounterable& TreasureScreen::genRandomEncounterable(unsigned int seed, sf::Window& window, Ambience& ambience) {
    return *new Treasure(window);
}
