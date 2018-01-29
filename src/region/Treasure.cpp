#include "Treasure.hpp"
#include <cstdlib>
#include <iostream>

// <editor-fold defaultstate="collapsed" desc=" Con/Destructors ">

Treasure::Treasure(sf::Window& window) {
    treasure_texture = new sf::Texture();
    if (!treasure_texture->loadFromFile("resources/treasure_chest.png")) {
        std::cout << "Failed to load Treasure texture " << "treasure_chest.png" << " from directory " << "resources/" << "\n";
    };
    treasure_texture->setSmooth(true);
    setTexture(*treasure_texture);
}

Treasure::Treasure(const Treasure& orig) {}

Treasure::~Treasure() {
    delete treasure_texture;
}

// </editor-fold>

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Implemented Abstract Methods ">

/* Returns whether Treasure is a skippable Encounterable (true) */
bool Treasure::isSkippable() const {
    return true;
}

/* Returns the name of the Encounterable subclass ("Treasure") */
std::string Treasure::getTypeName() const {
    return "Treasure";
}

/* Returns an enum RoomType value corresponding to the subclass (treasure) */
RoomType Treasure::getType() const {
    return treasure;
}

/* Interact with the Encounterable */
void Treasure::encounter(Player& player) {
    std::cout << "This is a treasure!\n";
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Original Methods ">


// </editor-fold>
