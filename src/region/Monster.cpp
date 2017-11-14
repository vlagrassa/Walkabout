#include "Monster.hpp"
#include "Encounterable.hpp"
#include "../screen/EncounterScreen.hpp"
#include <cstdlib>
#include <iostream>

Monster::Monster() {
    name = "John";
    health = 20;
    initScreen();
    battle_screen = new FightScreen();
}
Monster::Monster(const Monster& orig) {
    battle_screen = new FightScreen();
}
Monster::~Monster() {
    
}

std::string Monster::getName() {
    return name;
}
int Monster::getHealth() {
    return health;
}
std::vector<int> Monster::getReward() {
    return reward;
}

std::string Monster::getTypeName() const {
    return "Monster";
}

RoomType Monster::getType() const {
    return monster;
}

FightScreen* Monster::getEncounterScreen() const {
    std::cout << "Returning fight screen!" << "\n";
    return battle_screen;
}

//void Monster::initialize() {
//    battle_screen = new FightScreen();
//    std::cout << "Just initialized battle_screen as " << battle_screen << " from initialize function... ";
//}

void Monster::encounter() {
    std::cout << "This is a monster!\n";
}

bool Monster::isSkippable() const {
    return false;
}