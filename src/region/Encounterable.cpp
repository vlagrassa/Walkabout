#include "Encounterable.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

Encounterable::Encounterable() {
    
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

EncounterScreen Encounterable::encounter() {
    std::cout << "Returning default encounter screen!" << "\n";
    return screen;
}