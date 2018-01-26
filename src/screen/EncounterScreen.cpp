#include "EncounterScreen.hpp"
#include <SFML/Graphics.hpp>

EncounterScreen::EncounterScreen(sf::Window& window) : ScreenMode(window) {
    showPrevious = true;
}
EncounterScreen::EncounterScreen(const EncounterScreen& orig) : ScreenMode(orig.window) {
    
}
EncounterScreen::~EncounterScreen() {
    
}

std::string EncounterScreen::testThing() {
    return "This is a default encounter!";
}
