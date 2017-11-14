#include "Hall.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "../player/Player.hpp"

// <editor-fold defaultstate="collapsed" desc=" Con/Destructors ">

/* Constructor generating a random seed */
Hall::Hall() {
    initialize();
    seed = genRandomSeed();
}
/* Constructor using a provided seed */
Hall::Hall(int s) {
    initialize();
    seed = s;
}
/* Default constructor */
Hall::Hall(const Hall& orig) {
    
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
int Hall::getPlayerT() const {
    return playerT;
}
int Hall::getSeed() const {
    return seed;
}
std::vector<Room*> Hall::getListOfRooms() const {
    return listOfRooms;
}

/* Return the Room at the given index */
Room* Hall::getRoom(int index) {
    return listOfRooms.at(index);
}

/* Return the current active Room */
Room* Hall::getActiveRoom() {
    return getRoom(playerIndex);
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Setter Methods ">
/* Set index of the active Room and update list */
void Hall::setActiveRoom(int index) {
    if (playerIndex >= 0) {
        listOfRooms.at(playerIndex)->deactivate();
    }
    playerIndex = index;
    if (playerIndex >= 0) {
        listOfRooms.at(playerIndex)->activate();
    }
}
void Hall::setActiveRoom() {
    if (playerIndex >= 0) {
        listOfRooms.at(playerIndex)->activate();
    }
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Adder Methods ">
/* Add a Room to the Hall */
void Hall::addRoom(Room* r) {
    listOfRooms.push_back(r);
    totalLength += r->getLength();
    setActiveRoom();
}

/* Generate a random Room from the seed */
void Hall::addRoom() {
    srand(seed); //reset srand
    for (unsigned i = 0; i < listOfRooms.size(); i++) {
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
        l += listOfRooms.at(i)->getLength();
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
/* Initialize values common to all constructors */
void Hall::initialize() {
    playerIndex = 0;
}

/* Calculate playerIndex based on playerX */
void Hall::updateIndex(Player& p) {
    unsigned l = 0;
    for (int i = 0; i < listOfRooms.size(); i++) {
        l += listOfRooms.at(i)->getLength();
        if (l > p.getX()) {
            setActiveRoom(i);
            playerT = listOfRooms.at(i)->getLength() - (l - p.getX());
            //std::cout << "\nSending to position " << std::to_string(playerT) << " in room " << std::to_string(playerIndex) << "\n";
            return;
        }
    }
    
}

/* Generate seed based on the current time */
int Hall::genRandomSeed() {
    return std::time(NULL);
    //std::srand(static_cast<unsigned int>(std::time(NULL)));
}

/* Return Hall for a stream */
std::ostream& operator<<(std::ostream &strm, const Hall &h) {
    strm << "Hall: Room " << h.getPlayerIndex() << ", Tic " << h.getPlayerT() << "\n";
    for (Room* r : h.getListOfRooms()) {
        strm << "  " << *r << "\n";
    }
    h.printDistances();
    return strm;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Distances ">
void Hall::recalcLength() {
    totalLength = 0;
    for (Room* r : listOfRooms) {
        totalLength += r->getLength();
    }
}

void Hall::printDistances() const {
    std::cout << "| ";
    for (unsigned i = 0; i < listOfRooms.size(); i++) {
        for (unsigned j = 0; j < (listOfRooms.at(i)->getLength())-1; j++) {
            if (i == playerIndex && j == playerT) {
                std::cout << "o ";
            } else {
                std::cout << "_ ";
            }
        }
        if (i == playerIndex && listOfRooms.at(i)->getLength()-1 == playerT) {
            std::cout << "Ø | ";
        } else {
            std::cout << "X | ";
        }
    }
    std::cout << "\n";
}
// </editor-fold>