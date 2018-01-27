#include "EncounterScreen.hpp"
#include "../utils/Defaults.hpp"
#include <SFML/Graphics.hpp>


void Oscillator::run(sf::Event event) {
    if (event.key.code == sf::Keyboard::T) {
        scramble();
    }
    attackSlider.currentPos += attackSlider.dir;
    if (attackSlider.currentPos >= outline.getPosition().x + outline.getSize().x - attackSlider.getSize().x) {
        attackSlider.dir = std::abs(attackSlider.dir) * -1;
        attackSlider.currentPos = outline.getPosition().x + outline.getSize().x - attackSlider.getSize().x;
    } else if (attackSlider.currentPos <= outline.getPosition().x) {
        attackSlider.dir = std::abs(attackSlider.dir);
        attackSlider.currentPos = outline.getPosition().x;
    }
    attackSlider.setPosition(sf::Vector2f(attackSlider.currentPos, attackSlider.getPosition().y));
}

void Oscillator::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(areas, 16, sf::TriangleStrip);
    target.draw(outline);
    target.draw(attackSlider);
}

float Oscillator::getStrength() {
    return 1.0;
}

void Oscillator::scramble() {
    srand(DEFAULT_GAMECLOCK.getElapsedTime().asMilliseconds());
    
    attackArea.center = (rand() % static_cast<int>(outline.getSize().x - 2*attackArea.width)) + attackArea.width;
    defendArea.center = attackArea.center;
    while (std::abs(defendArea.center-attackArea.center) < attackArea.width + defendArea.width) {
        defendArea.center = (rand() % static_cast<int>(outline.getSize().x - 2*defendArea.width)) + defendArea.width;
    }
    
    bool attackOnLeft = attackArea.center < defendArea.center;
    TargetArea first  = attackOnLeft ? attackArea : defendArea;
    TargetArea second = attackOnLeft ? defendArea : attackArea;
    
    sf::Color colors[] = {
        backgroundColor,
        backgroundColor,
        first.color,
        backgroundColor,
        backgroundColor,
        second.color,
        backgroundColor,
        backgroundColor,
    };
    
    int coords[] = {
        0,
        first.center - first.width,
        first.center,
        first.center + first.width,
        second.center - second.width,
        second.center,
        second.center + second.width,
        static_cast<int>(outline.getSize().x)
    };
    for (unsigned int i = 0; i < 16; i+=2) {
        areas[i]   = sf::Vertex(sf::Vector2f(outline.getPosition().x + coords[i/2], outline.getPosition().y                      ), colors[i/2]);
        areas[i+1] = sf::Vertex(sf::Vector2f(outline.getPosition().x + coords[i/2], outline.getPosition().y + outline.getSize().y), colors[i/2]);
    }
}

void Oscillator::initShapes(sf::Vector2f pos) {
    attackSlider.setFillColor(sf::Color::Cyan);
    attackSlider.setOutlineColor(sf::Color::Black);
    attackSlider.setOutlineThickness(3);
    attackSlider.setPosition(pos);
    outline.setFillColor(sf::Color::Transparent);
    outline.setOutlineColor(sf::Color::Black);
    outline.setOutlineThickness(3);
    outline.setPosition(pos);
    attackArea.center = 100;
    attackArea.width = 50;
    attackArea.color = sf::Color::Green;
    defendArea.center = 200;
    defendArea.width = 50;
    defendArea.color = sf::Color::Red;
}

void Oscillator::updateArea() {
    
}


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
