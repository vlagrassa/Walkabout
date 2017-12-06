#include "Room.hpp"
#include "Monster.hpp"
#include "Treasure.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// <editor-fold defaultstate="collapsed" desc=" Con/Destructors ">

/* Constructor, takes length and Encounterable */
Room::Room(unsigned int size, Encounterable* enc) : encounter(enc), length(size), playerX(-1), active(false) {}

/* Constructor, takes seed for Room & generates length and Encounterable */
Room::Room(unsigned int seed) : Room((seed%15)+2, genRandomEncounterable(seed)) {};

/* Default constructor */
Room::Room(const Room& orig) : length(orig.getLength()) {
    
}

/* Default destructor */
Room::~Room() {
    
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Getters ">

/* Getter method for length */
unsigned int Room::getLength() const {
    return length;
}

/* Getter method for player's x coordinate within Room */
int Room::getPlayerX() const {
    return playerX;
}

/* Getter method for Encounterable */
Encounterable* Room::getEncounter() const {
    return encounter;
}

RoomType Room::getType() const {
    return encounter->getType();
}

EncounterScreen* Room::getScreen() const {
    return getEncounter()->getEncounterScreen();
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Setters ">

void Room::setPlayerX(int n) {
    playerX = n;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Check and set active ">

/* Check if Room is active */
bool Room::isActive() const {
    return active;
}

/* Setter method for active */
void Room::setActive(const bool& b, int n) {
    active = b;
    if (b) {
        if (playerX == -1) {
            playerX = n;
        }
    } else {
        playerX = -1;
    }
}

/* Set active to true */
void Room::activate() {
    setActive(true);
}

/* Set active to false */
void Room::deactivate() {
    setActive(false);
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Friend Methods ">

/* Return Room for a stream */
std::ostream& operator<<(std::ostream &strm, const Room &r) {
    if (r.isActive()) {
        strm << "*  ACTIVE ";
    } else {
        strm << " Inactive ";
    }
    strm << "size " << std::to_string(r.getLength()) << " " << r.getEncounter()->getTypeName() << " at tic " << r.getPlayerX();
    return strm;
}

// </editor-fold>

Encounterable* Room::genRandomEncounterable(unsigned int seed) {
    RoomType temp = static_cast<RoomType>(seed % 2);
    if (temp == monster) {
        return new Monster(dinosaur);
    }
    if (temp == treasure) {
        return new Treasure();
    }
    std::cout << "Something went wrong in Room::genRandomEncounterable\n";
    return NULL;
}