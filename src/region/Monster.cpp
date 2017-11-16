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
}
Monster::Monster(const Monster& orig) {
    battle_screen = new FightScreen();
}
Monster::~Monster() {
    
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Inherited Methods ">

FightScreen* Monster::getEncounterScreen() const {
    std::cout << "Returning fight screen!" << "\n";
    return battle_screen;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Implemented Abstract Methods ">

bool Monster::isSkippable() const {
    return false;
}

std::string Monster::getTypeName() const {
    return "Monster";
}

RoomType Monster::getType() const {
    return monster;
}

void Monster::encounter(Player& player) {
    std::cout << "This is a monster!\n";
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Original Methods ">

std::string Monster::getName() {
    return name;
}
int Monster::getHealth() {
    return health;
}

// </editor-fold>
