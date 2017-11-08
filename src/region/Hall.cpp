#include "Hall.hpp"
#include "Region.hpp"
#include <SFML/Graphics.hpp>

/* Generate a random seed */
Hall::Hall() {
    playerIndex = 0;
    playerX = 0;
    seed = genRandomSeed();
}
/* Use the provided seed */
Hall::Hall(int s) {
    playerIndex = 0;
    playerX = 0;
    seed = s;
}

Hall::Hall(const Hall& orig) {
    
}
Hall::~Hall() {
    
}

int Hall::getPlayerIndex() {
    return playerIndex;
}
int Hall::getPlayerX() {
    return playerX;
}

void Hall::addRoom(Room* r) {
    listOfRooms.push_back(r);
}
/* Method to generate a random Room based on the seed */
void Hall::addRoom() {
    
}

/* Set the player's x position within the Hall */
void Hall::goTo(int n) {
    playerX = n;
    Hall::updateIndexAndRoom();
}

/* Special applications of goTo() */
void Hall::step(int n) {
    Hall::goTo(playerX + n);
}
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

void Hall::setActiveRoom(int n) {
    playerIndex = n;
}

Room* Hall::getActiveRoom() {
    return getRoom(playerIndex);
}
Room* Hall::getRoom(int index) {
    return listOfRooms.at(index);
}

void Hall::goToRoom(int n) {
    
}
void Hall::stepRoom(int n) {
    goToRoom(playerIndex+n);
}

//Temporary function - change to reflect actual algorithm
void Hall::updateIndexAndRoom() {
    //set current room (listOfRooms[playerIndex]) to not active
    //change index to reflect new playerX
    //set new room to active
}

/* Generate and return a random seed */
int Hall::genRandomSeed() {
    //return 5; //Temporary return value
    //srand(5);
    return time();
}