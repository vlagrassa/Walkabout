#include "Hall.hpp"
#include <SFML/Graphics.hpp>
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

/* Getter methods */
int Hall::getPlayerIndex() {
    return playerIndex;
}
int Hall::getPlayerX() {
    return playerX;
}
int Hall::getSeed() {
    return seed;
}

/* Add a Room to the Hall */
void Hall::addRoom(Room* r) {
    listOfRooms.push_back(r);
}

/* Generate a random Room from the seed */
void Hall::addRoom() {
    
}

/* Set the player's x position within the Hall */
void Hall::goTo(int n) {
    playerX = n;
    Hall::updateIndexAndRoom();
}

/* Set the player's x position relative to current position */
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

/* Set index of the active Room and update list */
void Hall::setActiveRoom(int n) {
    playerIndex = n;
}

/* Return the current active Room */
Room* Hall::getActiveRoom() {
    return getRoom(playerIndex);
}

/* Return the Room at the given index */
Room* Hall::getRoom(int index) {
    return listOfRooms.at(index);
}

/* Return the list of Rooms */
std::vector<Room*> Hall::getListOfRooms() const {
    return listOfRooms;
}

/* Send player to position steps within Room at index */
void Hall::goToRoom(int index, int steps) {
    
}
/* Send player to beginning of Room at given index */
void Hall::goToRoom(int index) {
    goToRoom(index, 0);
}

/* Send player to position steps in a given Room relative to current Room */
void Hall::stepRoom(int index, int steps) {
    goToRoom(playerIndex+index, steps);
}

/* Send player to given Room relative to current Room */
void Hall::stepRoom(int n) {
    stepRoom(index, 0);
}

/* Initialize values common to all constructors */
void initialize() {
    playerIndex = 0;
    playerX = 0;
}

//Temporary function - change to reflect actual algorithm
void Hall::updateIndexAndRoom() {
    //set current room (listOfRooms[playerIndex]) to not active
    //change index to reflect new playerX
    //set new room to active
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