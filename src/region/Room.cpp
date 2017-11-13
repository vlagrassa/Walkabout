#include "Room.hpp"
#include <SFML/Graphics.hpp>

/* Constructor, takes length and Encounterable */
Room::Room(int d, Encounterable t) {
    active = false;
    length = d;
    thing = Encounterable(t);
}
Room::Room(int seed) {
    active = false;
    length = (seed%15)+2;
}
/* Default constructor */
Room::Room(const Room& orig) {
    
}
/* Default destructor */
Room::~Room() {
    
}

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
Encounterable Room::getEncounter() const {
    return thing;
}

RoomType Room::getType() const {
    return type;
}

/* Setter method for length */
void Room::setLength(const int& n) {
    length = n;
}

/* Setter method for Encounterable */
//void Room::setEncounter(const Encounterable& e) {
//    thing = Encounterable(e);
//}

void Room::setType(RoomType t) {
    type = t;
}

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

/* Return Room for a stream */
std::ostream& operator<<(std::ostream &strm, const Room &r) {
    if (r.isActive()) {
        strm << "*  ACTIVE ";
    } else {
        strm << " Inactive ";
    }
    strm << "size " << std::to_string(r.getLength()) << " " << r.getEncounter().getTypeName();
    return strm;
}