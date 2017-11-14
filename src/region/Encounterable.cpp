#include "Encounterable.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

Encounterable::Encounterable() {
    initScreen();
}
Encounterable::Encounterable(const Encounterable& orig) {
    
}
Encounterable::~Encounterable() {
    
}

bool Encounterable::isSkippable() {
    return skippable;
}

EncounterScreen* Encounterable::getEncounterScreen() const {
    std::cout << "Returning default encounter screen!" << "\n";
    return screen;
}

std::vector<int> Encounterable::getReward() const {
    return reward;
}

void Encounterable::initScreen() {
    screen = new EncounterScreen();
}