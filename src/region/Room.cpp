#include "Room.hpp"
#include <SFML/Graphics.hpp>

Room::Room(int d, Encounterable t) {
    size = d;
    thing = t;
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
    const int c = size;
    return c;
}

int Room::getSize() {
    return size;
}

std::ostream& operator<<(std::ostream &strm, const Room &r) {
    return strm << "Print room test, size = " + std::to_string(r.getSize());
}