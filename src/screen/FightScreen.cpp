#include "EncounterScreen.hpp"
#include "../utils/Defaults.hpp"
#include <SFML/Graphics.hpp>
#include "../region/Monster.hpp"
#include "DeathScreen.hpp"


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
    updateArea();
}

void Oscillator::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(areas, 10, sf::TriangleStrip);
    target.draw(outline);
    target.draw(attackSlider);
}

float Oscillator::getStrength() {
    switch (area) {
        case (attack):
//            attackSlider.currentPos = attackArea.center + outline.getPosition().x; // In the middle -> 1.0
//            attackSlider.currentPos = attackArea.center + attackArea.width/2 + outline.getPosition().x; //Halfway between -> 0.5
//            attackSlider.currentPos = attackArea.center + attackArea.width + outline.getPosition().x; //On the edge -> 0.0
            return 1-std::abs((outline.getPosition().x + attackArea.center - attackSlider.currentPos) / attackArea.width);
            break;
//        case (defend):
//            return 1-std::abs((outline.getPosition().x + defendArea.center - attackSlider.currentPos) / defendArea.width);
//            break;
        default:
            break;
    }
    return 0;
}

void Oscillator::scramble() {
    srand(DEFAULT_GAMECLOCK.getElapsedTime().asMilliseconds());
    
    attackArea.center = (rand() % static_cast<int>(outline.getSize().x - 2*attackArea.width)) + attackArea.width;
    while (std::abs(attackArea.center - static_cast<signed>(attackSlider.currentPos)) + 10 < attackArea.width) {
        attackArea.center = (rand() % static_cast<int>(outline.getSize().x - 2*attackArea.width)) + attackArea.width;
    }
//    defendArea.center = attackArea.center;
//    while (std::abs(defendArea.center-attackArea.center) < attackArea.width + defendArea.width) {
//        defendArea.center = (rand() % static_cast<int>(outline.getSize().x - 2*defendArea.width)) + defendArea.width;
//    }
    
//    TargetArea tempAreas[2];
//    tempAreas[0] = attackArea.center < defendArea.center ? attackArea : defendArea;
//    tempAreas[1] = attackArea.center < defendArea.center ? defendArea : attackArea;
    
    recalcAreaPoints();
}

void Oscillator::recalcAreaPoints() {
    int coords[] = {
        0,
        attackArea.center - attackArea.width,
        attackArea.center,
        attackArea.center + attackArea.width,
//        tempAreas[0].center - tempAreas[0].width,
//        tempAreas[0].center,
//        tempAreas[0].center + tempAreas[0].width,
//        tempAreas[1].center - tempAreas[1].width,
//        tempAreas[1].center,
//        tempAreas[1].center + tempAreas[1].width,
        static_cast<int>(outline.getSize().x)
    };
    
    for (unsigned int i = 0; i < 10; i+=2) {
        areas[i]   = sf::Vertex(
                        sf::Vector2f(
                            outline.getPosition().x + coords[i/2],
                            outline.getPosition().y
                        ),
                        ((i/2+1) % 3 == 0) ?
//                            tempAreas[((i/2)-2)/3].color :
                            attackArea.color :
                            backgroundColor);
        areas[i+1] = sf::Vertex(
                        sf::Vector2f(
                            outline.getPosition().x + coords[i/2],
                            outline.getPosition().y + outline.getSize().y
                        ),
                        ((i/2+1) % 3 == 0) ?
//                            tempAreas[((i/2)-2)/3].color :
                            attackArea.color :
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
//    defendArea.center = 200;
//    defendArea.width = 50;
//    defendArea.color = sf::Color::Red;
}

void Oscillator::updateArea() {
    if (std::abs(outline.getPosition().x + attackArea.center - attackSlider.currentPos) < attackArea.width) {
        if (area == empty) {
            area = attack;
            attackSlider.setFillColor(sf::Color::Yellow);
        } else if (area == emptydefend) {
            area = defend;
            attackSlider.setFillColor(sf::Color::Yellow);
        }
    }
//    else if (std::abs(outline.getPosition().x + defendArea.center - attackSlider.currentPos) < defendArea.width) {
//        area = defend;
//        attackSlider.setFillColor(sf::Color::Magenta);
//    }
    else if (area == attack) {
//        area = damage;
        std::cout << "Switching to defense\n";
        area = emptydefend;
        attackSlider.setFillColor(sf::Color::Blue);
    }
    else if (area == defend) {
        area = damage;
        attackSlider.setFillColor(sf::Color::Blue);
    }
    else if (area == empty) {
        attackSlider.setFillColor(sf::Color::Cyan);
        attackArea.color = sf::Color::Green;
        recalcAreaPoints();
    }
    else if (area == emptydefend) {
        attackSlider.setFillColor(sf::Color::Magenta);
        attackArea.color = sf::Color::Red;
        recalcAreaPoints();
    }
}


FightScreen::FightScreen(Player& player, int seed, Ambience& ambience, sf::Window& window ) : 
        //Room(seed, window), //This is the ideal but throws seg fault, for some reason
        ambience(ambience),
        Room(player, (seed%31)+100, genRandomEncounterable(seed, window, ambience)),
        attackBar(sf::Vector2f(164,436), sf::Vector2f(626,90), 8)
        
{
std::cout << "Monster standing texture Fight Screen 1 @" << &this->ambience.monsterStanding << "\n";
}
    
FightScreen::FightScreen(const FightScreen& orig) : FightScreen(orig.player, 5,orig.ambience, orig.window) {
    
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
    //If space pressed, take the strength & switch the attack bar's current area
    if (event.type != sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
        float strength = attackBar.getStrength();
        switch (attackBar.area) {
            case (Oscillator::attack):
                //Case attack region: take that from the monster's health
                player.Animations.setActiveIndex(2);
                player.setAnimation();
                monster->changeHealth(-strength * 5);
                attackBar.area = Oscillator::empty;
                attackBar.scramble();
                break;
            case (Oscillator::defend):
//                 Case defend region: take from the player's health, but decreased
                player.health -= 5 - (strength * 5);
                attackBar.area = Oscillator::empty;
                attackBar.scramble();
                break;
            case (Oscillator::damage):
                attackBar.scramble();
                break;
            case (Oscillator::critical):
                //Case critical region: take double from the monster's health??
                break;
            case (Oscillator::empty):
                //Case blank region: no action necessary
                attackBar.area = Oscillator::emptydefend;
                break;
            case (Oscillator::emptydefend):
                //Case blank region: no action necessary
                break;
        }
//        if (monster->getHealth() <= 0) {
//            passed = true;
//            return 0;
//        }
    }
    
    return Room::update(event);
}

ScreenMode* FightScreen::run(sf::Event event) {
    attackBar.updateFrames(DEFAULT_GAMECLOCK, event);
    player.healthbar.update();
    player.updateFrames(DEFAULT_GAMECLOCK, event);
    encounter->encounter(player);
    monster->updateFrames(DEFAULT_GAMECLOCK, event);
    std::cout<<monster->Encounterable::getTexture() << "\n";
    if (monster->getHealth() <= 0) {
        monster->setActiveAnimation(3);
        monster->setTheAnimation();
//        std::cout<< "420 blaze it" <<monster->Encounterable::getTexture() << "\n";
        passed = true;
        return 0;
    }
    if (player.health > player.maxHealth) {
//        DEFAULT_WINDOW.close();
        return new DeathScreen();
//        monster->changeHealth(-1000000);
//        passed = true;
//        return 0;
    }
    
    //Previous line will update which region the attack bar is currently in
    
    if (attackBar.area == Oscillator::damage) {
        monster->setActiveAnimation(1);
        monster->setTheAnimation();
        player.health -= 5;
        attackBar.area = Oscillator::empty;
    }
    
    return Room::run(event);
};

Encounterable& FightScreen::genRandomEncounterable(unsigned int seed, sf::Window& window, Ambience& ambience) {
    std::cout << "Monster standing texture Fight Screen @" << &ambience.monsterStanding << "\n";
    monster = new Monster( window, ambience);
    return *monster;
}
