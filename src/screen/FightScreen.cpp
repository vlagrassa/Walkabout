#include "FightScreen.hpp"
#include <SFML/Graphics.hpp>

FightScreen::FightScreen(sf::Window& window) : EncounterScreen(window) {
    
}
FightScreen::FightScreen(const FightScreen& orig) : EncounterScreen(orig.window) {
    
}
FightScreen::~FightScreen() {
    
}

std::string FightScreen::testThing() {
    return "This is a fight screen!";
}
