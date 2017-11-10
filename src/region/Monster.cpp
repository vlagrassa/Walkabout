#include "Monster.hpp"
#include "Encounterable.hpp"

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