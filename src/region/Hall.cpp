#include "Hall.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "../player/Player.hpp"

// <editor-fold defaultstate="collapsed" desc=" Con/Destructors ">

/* Constructor - takes optional argument s */
Hall::Hall(int s) : seed(s) {
    playerIndex = 0;
}
/* Default constructor */
Hall::Hall(const Hall& orig) : seed(genRandomSeed()) {
    
}
/* Default destructor */
Hall::~Hall() {
    
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Getter Methods ">

/* Basic getter methods */
int Hall::getPlayerIndex() const {
    return playerIndex;
}
int Hall::getSeed() const {
    return seed;
}

/* Return the Room at the given index */
Room* Hall::getRoom(int index) const {
    return at(index);
}

/* Return the current active Room */
Room* Hall::getActiveRoom() const {
    return getRoom(playerIndex);
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Setter Methods ">

/* Set index of the active Room and update list */
void Hall::setActiveRoom(int index) {
    if (playerIndex >= 0) {
        at(playerIndex)->deactivate();
    }
    playerIndex = index;
    if (playerIndex >= 0) {
        at(playerIndex)->activate();
    }
}
void Hall::setActiveRoom() {
    if (playerIndex >= 0) {
        at(playerIndex)->activate();
    }
}

void Hall::setPlayerT(int n) {
    getActiveRoom()->setPlayerX(n);
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Adder Methods ">

/* Add a Room to the Hall */
void Hall::addRoom(Room* r) {
    push_back(r);
    totalLength += r->getLength();
    setActiveRoom();
}

/* Generate a random Room from the seed */
void Hall::addRoom() {
    srand(seed); //reset srand
    for (unsigned i = 0; i < size(); i++) {
        rand();
    }
    Room* r = new Room(rand());
    addRoom(r);
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" GoTo Methods ">

/* Get x position for number of steps into given Room (absolute) */
int Hall::goToRoom(int index, int steps) {
    unsigned l = 0;
    for (int i = 0; i < index; i++) {
        l += at(i)->getLength();
    }
    return l + steps;
}
int Hall::goToRoom(int index) {
    return goToRoom(index, 0);
}

/* Get x position for number of steps into given Room (relative) */
int Hall::stepRoom(int index, int steps) {
    return goToRoom(playerIndex+index, steps);

}
int Hall::stepRoom(int index) {
    return stepRoom(index, 0);
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Miscellaneous Methods ">

/* Calculate playerIndex based on playerX */
void Hall::updateIndex(Player& p) {
    unsigned l = 0;
    for (int i = 0; i < size(); i++) {
        l += at(i)->getLength();
        if (l > p.getX()) {
            setActiveRoom(i);
            setPlayerT(at(i)->getLength() - (l - p.getX()));
            return;
        }
    }
    
}

/* Generate seed based on the current time */
int Hall::genRandomSeed() {
    return std::time(NULL);
}

/* Return Hall for a stream */
std::ostream& operator<<(std::ostream &strm, const Hall &h) {
    strm << "Hall: Room " << h.getPlayerIndex() << ", Tic " << h.getActiveRoom()->getPlayerX() << "\n";
    for (Room* r : h) {
        strm << "  " << *r << "\n";
    }
    h.printDistances();
    return strm;
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
            if (i == playerIndex && j == getActiveRoom()->getPlayerX()) {
                std::cout << "o ";
            } else {
                std::cout << "_ ";
            }
        }
        if (i == playerIndex && at(i)->getLength()-1 == getActiveRoom()->getPlayerX()) {
            std::cout << "Ø | ";
        } else {
            std::cout << "X | ";
        }
    }
    std::cout << "\n";
}
// </editor-fold>
