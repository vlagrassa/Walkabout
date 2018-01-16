#include "Player.hpp"
#include "Item.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>


Player::Player() : posX(0), posInRoom(0), stepSize(10), stats({0, 0, 0}) {
    std::cout << "hi";
}

Player::Player(const Player& p) : posX(p.getX()), posInRoom(p.getPosInRoom()), stepSize(p.getStepSize()) {
    std::cout << "hello";
}

Player::~Player() {
    
}

unsigned int Player::getX() const {
    return posX;
}

unsigned int Player::getPosInRoom() const {
    return posInRoom;
}

int Player::getStepSize() const {
    return stepSize;
}

void Player::setPosInRoom(unsigned int n) {
    posInRoom = n;
}

void Player::setPos(unsigned int total, unsigned int inRoom) {
    posX = total;
    posInRoom = inRoom;
}

/* Set the player's x position within the Hall (absolute) */
void Player::goTo(unsigned int n) {
    posX = n;
}

/* Set the player's x position within the Hall (relative) */
void Player::step(int n) {
    movingRight = (n > 0) ? true : false;
    if (static_cast<int>(posX) + n < 0) {
        // Program is trying to send to a negative position - send to start instead
        goTo(0);
    } else {
        goTo(posX + static_cast<unsigned int>(n));
    }
}

/* Special applications of step() */
void Player::stepLeft() {
    //step(-stepSize);
    step(-1);
}

void Player::stepLeft(int n) {
    step(-n);
}

void Player::stepRight() {
    //step(stepSize);
    step(1);
}

void Player::stepRight(int n) {
    step(n);
}

bool Player::isMovingRight() {
    return movingRight;
}

bool Player::isMovingLeft() {
    return !isMovingRight();
}

/*Stats*/
void Player::modify(Stats stat){
    stats.body += stat.body;
    stats.mind += stat.mind;
    stats.soul += stat.soul;
}
/*INVENTORY and EQUIPING*/
    
void Player::addItem(Item& item){
    itemVector.push_back(item);
}

void Player::equip(Item& item){
    switch(item.type){
        case(head):
            equipped.head = item;
            break;
        case(Chest):
            equipped.chest = item;
            break;
        case(hand):
            equipped.hand = item;
            break;
        case(pocket1):
            equipped.pocket1 = item;
            break;
        case(pocket2):
            equipped.pocket2 = item;
            break;
        default:
            /*throw error*/
            break;
    }
    
}

/* Return Player for a stream */
std::ostream& operator<<(std::ostream &strm, const Player &p) {
    strm << "Player at position " << p.getX();
    return strm;
}
