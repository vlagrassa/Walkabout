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
    
    //Previous line will update which region the attack bar is currently in
    //If space pressed, grab the strength & switch the attack bar's current area
    //Case attack region: take that from the monster's health
    //Case defend region: take from the player's health, but decreased
    //Case crit region: take double from the monster's health??
    //Case blank region: don't really do anything
    //After switch statement, scramble the areas to reset
    //If the bar passes the defense region without space, take full damage
    
    return EncounterScreen::run(event);
};
