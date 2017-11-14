#include "Room.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// <editor-fold defaultstate="collapsed" desc=" Con/Destructors ">

/* Constructor, takes length and Encounterable */
Room::Room(int d, Encounterable* t) {
    active = false;
    length = d;
    thing = t;
    type = unknown;
}
Room::Room(int seed) {
    active = false;
    length = (seed%15)+2;
    thing = new Encounterable();
    type = unknown;
}
/* Default constructor */
Room::Room(const Room& orig) {
    
}
/* Default destructor */
Room::~Room() {
    
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Getters ">

/* Getter method for length */
int Room::getLength() const {
    return length;
}

/* Get distance from Player to Encounterable */
int Room::getDistance() const {
    //DEFAULT RETURN VALUE - UPDATE WITH ACTUAL CODE
    return 5;
}

/* Getter method for Encounterable */
Encounterable* Room::getEncounter() const {
    return thing;
}

RoomType Room::getType() const {
    std::cout << "Attempting to get type " << type << "... ";
    return type;
}

EncounterScreen* Room::getScreen() const {
    return getEncounter()->getEncounterScreen();
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Setters ">

void Room::setType(RoomType t) {
    type = t;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Check and set active ">

/* Check if Room is active */
bool Room::isActive() const {
    return active;
}

/* Setter method for active */
void Room::setActive(const bool& b) {
    active = b;
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
    strm << "size " << std::to_string(r.getLength()) << " " << r.getEncounter()->getTypeName();
    return strm;
}

// </editor-fold>