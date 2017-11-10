#include "Hall.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>

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

/* Basic getter methods */
int Hall::getPlayerIndex() const {
    return playerIndex;
}
int Hall::getPlayerX() const {
    return playerX;
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

/* Add a Room to the Hall */
void Hall::addRoom(Room* r) {
    listOfRooms.push_back(r);
    distances.push_back(r->getLength());
    totalLength += r->getLength();
    setActiveRoom();
}

/* Generate a random Room from the seed */
void Hall::addRoom() {
    srand(seed);
    for (unsigned i = 0; i < 10; i++) {
        std::cout << std::to_string(i) << ": " << std::to_string(rand()%32) << "\n";
    }
    std::cout << "\n";
    srand(seed);
    for (unsigned i = 0; i < 10; i++) {
        std::cout << std::to_string(i) << ": " << std::to_string(rand()%32) << "\n";
    }
    //Room* r(i);
}

/* Set the player's x position within the Hall (absolute) */
void Hall::goTo(int n) {
    playerX = n;
    Hall::updateIndex();
}

/* Set the player's x position within the Hall (relative) */
void Hall::step(int n) {
    Hall::goTo(playerX + n);
}

/* Special applications of step() */
void Hall::stepLeft() {
    Hall:stepLeft(1);
}
void Hall::stepLeft(int n) {
    Hall::step(-n);
}
void Hall::stepRight() {
    Hall:stepRight(1);
}
void Hall::stepRight(int n) {
    Hall::step(n);
}

/* Send player to position steps in given Room (absolute) */
void Hall::goToRoom(int index, int steps) {
    playerIndex = index;
    playerT = steps;
}
void Hall::goToRoom(int index) {
    goToRoom(index, 0);
}

/* Send player to position steps in given Room (relative) */
void Hall::stepRoom(int index, int steps) {
    goToRoom(playerIndex+index, steps);
}
void Hall::stepRoom(int index) {
    stepRoom(index, 0);
}

/* Initialize values common to all constructors */
void Hall::initialize() {
    playerIndex = 0;
    playerX = 0;
}

/* Calculate playerIndex based on playerX */
void Hall::updateIndex() {
    unsigned l = 0;
    for (int i = 0; i < distances.size(); i++) {
        l += distances.at(i);
        if (l > playerX) {
            playerIndex = i;
            playerT = distances.at(i) - (l - playerX);
            //std::cout << "\n" << std::to_string(l-playerX);
            std::cout << "\nSending to position " << std::to_string(playerT) << " in room " << std::to_string(playerIndex) << "\n";
            return;
        }
    }
    
}

/* Generate seed based on the current time */
int Hall::genRandomSeed() {
    //return 5; //Temporary return value
    return std::time(NULL);
    //std::srand(static_cast<unsigned int>(std::time(NULL)));
}

/* Return Hall for a stream */
std::ostream& operator<<(std::ostream &strm, const Hall &h) {
    strm << "Hall:\n";
    for (Room* r : h.getListOfRooms()) {
        strm << "  " << *r << "\n";
    }
    return strm;
}



void Hall::calcDistances() {
    distances.clear();
    totalLength = 0;
    for (Room* r : listOfRooms) {
        distances.push_back(r->getLength());
        totalLength += r->getLength();
    }
}

void Hall::printDistances() {
    std::cout << "| ";
    for (unsigned i = 0; i < distances.size(); i++) {
        for (unsigned j = 0; j < (distances.at(i))-1; j++) {
            if (i == playerIndex && j == playerT) {
                std::cout << "o ";
            } else {
                std::cout << "_ ";
            }
        }
        if (i == playerIndex && distances.at(i)-1 == playerT) {
            std::cout << "Ø | ";
        } else {
            std::cout << "X | ";
        }
    }
    std::cout << "\n";
}