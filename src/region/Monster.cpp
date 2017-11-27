#include "Monster.hpp"
#include "Encounterable.hpp"
#include "../screen/EncounterScreen.hpp"
#include <cstdlib>
#include <iostream>

// <editor-fold defaultstate="collapsed" desc=" Con/Destructors ">

Monster::Monster() {
    name = "John";
    health = 20;
    battle_screen = new FightScreen();
    
    monster_texture = new sf::Texture();
    monster_texture->loadFromFile("resources/monster.png");
    setTexture(*monster_texture);
}
Monster::Monster(const Monster& orig) {
    battle_screen = new FightScreen();
}
Monster::~Monster() {
    delete monster_texture;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Inherited Methods ">

/* Returns the FightScreen associated with the Monster */
FightScreen* Monster::getEncounterScreen() const {
    std::cout << "Returning fight screen!" << "\n";
    return battle_screen;
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
    std::cout << "This is a monster!\n";
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Original Methods ">

/* Returns the Monster's name (necessary?) */
std::string Monster::getName() {
    return name;
}

/* Returns the maximum health possible for the Monster */
int Monster::getMaxHealth() {
    return maxHealth;
}

/* Returns the Monster's current health */
int Monster::getHealth() {
    return health;
}

/* Returns an enum MonsterSpecies value representing the monster's species */
MonsterSpecies Monster::getSpecies() {
    return species;
}

// </editor-fold>


/* Return Monster for a stream */
std::ostream& operator<<(std::ostream &strm, const Monster &orig) {
    strm << "Monster encountered ";
    return strm;
}
