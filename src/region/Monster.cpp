#include "Monster.hpp"
#include <cstdlib>
#include <iostream>

// <editor-fold defaultstate="collapsed" desc=" Con/Destructors ">

Monster::Monster(MonsterSpecies s, sf::Window& window) : healthbar(sf::Vector2f(164, 566), sf::Vector2f(626, 25), health, maxHealth) {
    name = "John";
    maxHealth = 20;
    health = maxHealth;
    species = s;
    healthbar.health.setFillColor(sf::Color::Red);
    
    monster_texture = new sf::Texture();
    if (!monster_texture->loadFromFile("resources/" + getSpeciesTexture())) {
        std::cout << "Failed to load Monster texture " << getSpeciesTexture() << " from directory " << "resources/" << "\n";
    }
    monster_texture->setSmooth(true);
    setTexture(*monster_texture);
}

Monster::Monster(const Monster& orig) : healthbar(orig.healthbar) {}

Monster::~Monster() {
    delete monster_texture;
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

/* Returns an enum MonsterSpecies value representing the monster's species */
MonsterSpecies Monster::getSpecies() const {
    return species;
}

// </editor-fold>

std::string Monster::getSpeciesTexture() {
    switch(species) {
        case (dinosaur):
            return "monster.png";
    }
    return "";
}
