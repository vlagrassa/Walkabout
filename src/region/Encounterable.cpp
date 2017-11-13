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

std::string Encounterable::getTypeName() const {
    return "Encounterable";
}

EncounterScreen* Encounterable::getEncounterScreen() const {
    std::cout << "Returning default encounter screen!" << "\n";
    return screen;
}

//std::vector<int> Encounterable::getReward() const {
//    
//}

void Encounterable::initScreen() {
    screen = new EncounterScreen();
}