#include "EncounterScreen.hpp"
#include "../utils/Defaults.hpp"
#include <SFML/Graphics.hpp>

FightScreen::FightScreen(sf::Window& window) : EncounterScreen(window), attackBar(sf::Vector2f(10,436), sf::Vector2f(780,154), 8) {
    
}
FightScreen::FightScreen(const FightScreen& orig) : FightScreen(orig.window) {
    
}
FightScreen::~FightScreen() {
    
}

std::string FightScreen::testThing() {
    return "This is a fight screen!";
}

void FightScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(attackBar, states);
    EncounterScreen::draw(target, states);
}

ScreenMode* FightScreen::run(sf::Event event) {
    attackBar.updateFrames(DEFAULT_GAMECLOCK, event);
    return EncounterScreen::run(event);
};
