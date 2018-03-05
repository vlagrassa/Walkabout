#include "Monster.hpp"
#include <cstdlib>
#include <iostream>

// <editor-fold defaultstate="collapsed" desc=" Con/Destructors ">

Monster::Monster( sf::Window& window) : healthbar(sf::Vector2f(164, 566), sf::Vector2f(626, 25), health, maxHealth) {
    name = "John";
    maxHealth = 20;
    health = maxHealth;
    healthbar.health.setFillColor(sf::Color::Red);
    
    
}

Monster::Monster(const Monster& orig) : healthbar(orig.healthbar) {}

Monster::~Monster() {
    
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Implemented Abstract Methods ">

/* Returns whether Monster is a skippable Encounterable (false) */
bool Monster::isSkippable() const {
    return false;
}

/* Returns the name of the Encounterable subclass ("Monster") */
std::string Monster::getTypeName() const {
    return "Monster";
}

/* Returns an enum RoomType value corresponding to the subclass (monster) */
RoomType Monster::getType() const {
    return monster;
}

/* Interact with the Encounterable */
void Monster::encounter(Player& player) {
    healthbar.update();
}

void Monster::drawExtras(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(healthbar, states);
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Original Methods ">

/* Returns the Monster's name (necessary?) */
std::string Monster::getName() const {
    return name;
}

/* Returns the maximum health possible for the Monster */
int Monster::getMaxHealth() const {
    return maxHealth;
}

/* Returns the Monster's current health */
int Monster::getHealth() const {
    return health;
}


// </editor-fold>


//void Monster::run(sf::Event event){
//    Animations.getActive().frames.shiftNode();
//    this->setTextureRect(Animations.getActive().frames.getActive());
//    
//}

void Monster::changeHealth(int n) {
    if (static_cast<signed int>(health) + n <= 0) {
        std::cout << "  Changing health (" << health << ") by " << n << "\n";
        health = 0;
    }
    else if (health + n > maxHealth) {
        health = maxHealth;
    }
    else {
        health += n;
    }
}
