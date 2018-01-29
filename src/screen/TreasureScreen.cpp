#include "EncounterScreen.hpp"
#include <SFML/Graphics.hpp>

TreasureScreen::TreasureScreen(sf::Window& window) : Room(5, window) {
    
}
TreasureScreen::TreasureScreen(const TreasureScreen& orig) : Room(orig) {
    
}
TreasureScreen::~TreasureScreen() {
    
}

std::string TreasureScreen::testThing() {
    return "This is a treasure screen!";
}
