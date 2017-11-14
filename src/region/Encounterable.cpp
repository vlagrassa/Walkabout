#include "Encounterable.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

// <editor-fold defaultstate="collapsed" desc=" Con/Destructors ">

Encounterable::Encounterable() {
    screen = new EncounterScreen();
}
Encounterable::Encounterable(const Encounterable& orig) {
    
}
Encounterable::~Encounterable() {
    
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Inherited Methods ">

/* Returns a list of Items held by the Encounterable */
std::vector<int> Encounterable::getReward() const {
    return reward;
}

/* Returns the EncounterScreen associated with the Encounterable */
EncounterScreen* Encounterable::getEncounterScreen() const {
    std::cout << "Returning default encounter screen!" << "\n";
    return screen;
}

// </editor-fold>
