#include "Monster.hpp"
#include "Encounterable.hpp"
#include "../screen/EncounterScreen.hpp"
#include <cstdlib>
#include <iostream>

Monster::Monster() {
    name = "John";
    health = 20;
}
Monster::Monster(const Monster& orig) {
    
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

FightScreen Monster::encounter() const {
    std::cout << "Returning fight screen!" << "\n";
    return battle_screen;
}