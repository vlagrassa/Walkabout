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
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
        float strength = attackBar.getStrength();
        switch (attackBar.area) {
            case (Oscillator::attack):
                //Case attack region: take that from the monster's health
            case (Oscillator::defend):
                //Case defend region: take from the player's health, but decreased
            case (Oscillator::critical):
                //Case crit region: take double from the monster's health??
            case (Oscillator::empty):
                //Case blank region: don't really do anything
                break;
        }
        //After switch statement, scramble the areas to reset
        attackBar.scramble();
    }
    //If the bar passes the defense region without space, take full damage
    
    return EncounterScreen::run(event);
};
