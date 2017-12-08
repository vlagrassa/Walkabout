#include "Hall.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "../player/Player.hpp"

// <editor-fold defaultstate="collapsed" desc=" Con/Destructors ">

/* Constructor - takes optional argument s */
Hall::Hall(Player& p, unsigned int s) : activeIndex(0), seed(s), totalLength(0), player(p)  {}

/* Default constructor */
Hall::Hall(const Hall& orig) : Hall(orig.getPlayer(), orig.getSeed()) {}

/* Default destructor */
Hall::~Hall() {}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Getter Methods ">

/* Basic getter methods */

unsigned int Hall::getSeed() const {
    return seed;
}

/* Return the Room at the given index */
Room* Hall::getRoom(unsigned int index) const {
    return at(index);
}

unsigned int Hall::getRoomPos(unsigned int index, unsigned int steps) {
    unsigned l = 0;
    for (unsigned int i = 0; i < index; i++) {
        l += at(i)->getLength();
    }
    return l + steps;
}

std::vector<Room*> Hall::getRange(unsigned int start, unsigned int end) const {
    if (start > size() || start > end) {
        std::cout << "Start index invalid";
    }
    if (end > size() || end < start) {
        std::cout << "End index invalid";
    }
    
    std::vector<Room*> temp;
    for (unsigned int i = start; i < end; i++) {
        temp.push_back(at(i));
    }
    return temp;
}

/* Get vector of the Rooms with space within the window's borders */
std::vector<Room*> Hall::getOnscreenRooms(sf::RenderTarget& w) const {
    //std::vector<Room*> temp;
    //temp.push_back(getActiveRoom());
    return getRange(0,size()); //default return value
}

Player& Hall::getPlayer() const {
    return player;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Setter Methods ">

/* Set index of the active Room and update list */
void Hall::setActiveRoom(unsigned int index) {
    at(activeIndex)->deactivate();
    activeIndex = index;
    at(activeIndex)->activate();
}

void Hall::setActiveRoom() {
    at(activeIndex)->activate();
}

void Hall::setActiveRoomPlayerX(unsigned int n) { //Give more intuitive name
    //getActive()->setPlayerX(n);
    player.setPosInRoom(n);
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Adder Methods ">

/* Add a Room to the Hall */
void Hall::addRoom(Room* r) {
    push_back(r);
    totalLength += r->getLength();
    r->getEncounter()->setPosition(totalLength * 50, 100);
    setActiveRoom();
}

/* Generate a random Room from the seed */
void Hall::addRoom() {
    srand(seed); //reset srand
    for (unsigned i = 0; i < size(); i++) {
        rand();
    }
    Room* r = new Room(static_cast<unsigned int>(rand()));
    addRoom(r);
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Miscellaneous Methods ">

/* Calculate playerIndex based on playerX */
void Hall::updateIndex(const Player& p) {
    at(activeIndex)->deactivate();
    unsigned l = 0;
    for (unsigned int i = 0; i < size(); i++) {
        l += at(i)->getLength();
        if (l > p.getX()) {
            setActiveRoom(i);
            setActiveRoomPlayerX(at(i)->getLength() - (l - p.getX()));
            return;
        }
    }
    
}

void Hall::updateIndex() {
    updateIndex(getPlayer());
}

/* Generate seed based on the current time */
unsigned int Hall::genRandomSeed() {
    return std::time(NULL);
}

/* Return Hall for a stream */
std::ostream& operator<<(std::ostream &strm, const Hall &h) {
    strm << "Hall: Room " << h.getActiveIndex() << "\n";
    for (Room* r : h) {
        strm << "  " << *r << "\n";
    }
    h.printDistances();
    return strm;
}

void Hall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (Room* r : getOnscreenRooms(target)) {
        target.draw(*r->getEncounter());
    }
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Distances ">

void Hall::recalcLength() {
    totalLength = 0;
    for(unsigned i = 0; i < size(); i++) {
        totalLength += at(i)->getLength();
    }
}

void Hall::printDistances() const {
    std::cout << "| ";
    for (unsigned i = 0; i < size(); i++) {
        for (unsigned j = 0; j < (at(i)->getLength())-1; j++) {
            if (i == activeIndex && j == player.getX()) {
                std::cout << "o ";
            } else {
                std::cout << "_ ";
            }
        }
        if (i == activeIndex && at(i)->getLength()-1 == player.getX()) {
            std::cout << "Ø | ";
        } else {
            std::cout << "X | ";
        }
    }
    std::cout << "\n";
}
// </editor-fold>
