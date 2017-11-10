#include "Room.hpp"
#include <SFML/Graphics.hpp>

Room::Room(int d, Encounterable t) {
    size = d;
    thing = Encounterable(t);
}
Room::Room(int d) {
    size = d;
}
Room::Room() {
    size = -1;
}
Room::Room(const Room& orig) {
    
}
Room::~Room() {
    
}

int Room::getSize() const {
    //const int c = size;
    return size;
}

Encounterable Room::getEncounter() const {
    return thing;
}

//void Room::setEncounter(const Encounterable& e) {
//    thing = Encounterable(e);
//}

bool Room::isActive() const {
    return active;
}

void Room::setActive(const bool& b) {
    active = b;
}
void Room::activate() {
    setActive(true);
}
void Room::deactivate() {
    setActive(false);
}



std::ostream& operator<<(std::ostream &strm, const Room &r) {
    if (r.isActive()) {
        strm << "*  ACTIVE ";
    } else {
        strm << " Inactive ";
    }
    strm << "size " << std::to_string(r.getSize()) << " " << r.getEncounter().getTypeName();
    return strm;
}