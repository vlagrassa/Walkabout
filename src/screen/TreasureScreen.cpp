#include "EncounterScreen.hpp"
#include <SFML/Graphics.hpp>

TreasureScreen::TreasureScreen(sf::Window& window) : EncounterScreen(window) {
    
}
TreasureScreen::TreasureScreen(const TreasureScreen& orig) : EncounterScreen(orig.window) {
    
}
TreasureScreen::~TreasureScreen() {
    
}

std::string TreasureScreen::testThing() {
    return "This is a treasure screen!";
}
