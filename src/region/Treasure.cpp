#include "Treasure.hpp"
#include "Encounterable.hpp"
#include "../screen/EncounterScreen.hpp"
#include <cstdlib>
#include <iostream>

// <editor-fold defaultstate="collapsed" desc=" Con/Destructors ">

Treasure::Treasure() {
    treasure_screen = new TreasureScreen();
    
    treasure_texture = new sf::Texture();
    if (!treasure_texture->loadFromFile("resources/treasure_chest.png")) {
        std::cout << "Failed to load Treasure texture " << "treasure_chest.png" << " from directory " << "resources/" << "\n";
    };
    treasure_texture->setSmooth(true);
    setTexture(*treasure_texture);
}

Treasure::Treasure(const Treasure& orig) {
    treasure_screen = new TreasureScreen();
}

Treasure::~Treasure() {
    delete treasure_screen;
    delete treasure_texture;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Inherited Methods ">

/* Returns the TreasureScreen associated with the Treasure */
TreasureScreen* Treasure::getEncounterScreen() const {
    std::cout << "Returning treasure screen!" << "\n";
    return treasure_screen;
}

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

/* Return Treasure for a stream */
std::ostream& operator<<(std::ostream &strm, const Treasure &orig) {
    strm << "Treasure encountered ";
    return strm;
}
