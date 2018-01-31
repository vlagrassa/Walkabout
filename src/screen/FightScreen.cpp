#include "EncounterScreen.hpp"
#include "../utils/Defaults.hpp"
#include <SFML/Graphics.hpp>
#include "../region/Monster.hpp"


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
    
    TargetArea tempAreas[2];
    tempAreas[0] = attackArea.center < defendArea.center ? attackArea : defendArea;
    tempAreas[1] = attackArea.center < defendArea.center ? defendArea : attackArea;
    
    int coords[] = {
        0,
        tempAreas[0].center - tempAreas[0].width,
        tempAreas[0].center,
        tempAreas[0].center + tempAreas[0].width,
        tempAreas[1].center - tempAreas[1].width,
        tempAreas[1].center,
        tempAreas[1].center + tempAreas[1].width,
        static_cast<int>(outline.getSize().x)
    };
    
    for (unsigned int i = 0; i < 16; i+=2) {
        areas[i]   = sf::Vertex(
                        sf::Vector2f(
                            outline.getPosition().x + coords[i/2],
                            outline.getPosition().y
                        ),
                        ((i/2+1) % 3 == 0) ?
                            tempAreas[((i/2)-2)/3].color :
                            backgroundColor);
        areas[i+1] = sf::Vertex(
                        sf::Vector2f(
                            outline.getPosition().x + coords[i/2],
                            outline.getPosition().y + outline.getSize().y
                        ),
                        ((i/2+1) % 3 == 0) ?
                            tempAreas[((i/2)-2)/3].color :
                            backgroundColor);
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


FightScreen::FightScreen(Player& player, int seed, sf::Window& window) : 
        //Room(seed, window), //This is the ideal but throws seg fault, for some reason
        Room(player, (seed%15)+42, genRandomEncounterable(seed, window)),
        attackBar(sf::Vector2f(164,436), sf::Vector2f(626,90), 8)
{}

FightScreen::FightScreen(const FightScreen& orig) : FightScreen(orig.player, 5, orig.window) {
    
}

FightScreen::~FightScreen() {
    
}

std::string FightScreen::testThing() {
    return "This is a fight screen!";
}

void FightScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(attackBar, states);
    target.draw(player.healthbar, states);
    Room::draw(target, states);
}

ScreenMode* FightScreen::update(sf::Event event) {
    //If space pressed, grab the strength & switch the attack bar's current area
    if (event.key.code == sf::Keyboard::Space) {
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
    
    return Room::update(event);
}

ScreenMode* FightScreen::run(sf::Event event) {
    attackBar.updateFrames(DEFAULT_GAMECLOCK, event);
    player.healthbar.update();
    encounter->encounter(player);
    
    //Previous line will update which region the attack bar is currently in
    
    
    return Room::run(event);
};

Encounterable& FightScreen::genRandomEncounterable(unsigned int seed, sf::Window& window) {
    return *new Monster(dinosaur, window);
}
