#include "Hall.hpp"
#include "Region.hpp"
#include <SFML/Graphics.hpp>

Hall::Hall() {
    playerIndex = 0;
    playerX = 0;
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

//void Hall::addRoom(Room newRoom) {
//    listOfRooms.push_back(newRoom);
//}

void Hall::addRoom(int n) {
    testVector.push_back(n);
}

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

int Hall::getActiveRoom() {
    return testVector.at(playerIndex);
}

//Temporary function - change to reflect actual algorithm
void Hall::updateIndexAndRoom() {
    //set current room (listOfRooms[playerIndex]) to not active
    //change index to reflect new playerX
    //set new room to active
}