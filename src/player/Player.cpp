#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>


Player::Player() {
    std::cout << "hi";
    posX = 0;
    stepSize = 10;
}
Player::Player(const Player& p) {
    std::cout << "hello";
}
Player::~Player() {
    
}

unsigned int Player::getX() const {
    return posX;
}

int Player::getStepSize() const {
    return stepSize;
}

/* Set the player's x position within the Hall (absolute) */
void Player::goTo(int n) {
    posX = n;
}

/* Set the player's x position within the Hall (relative) */
void Player::step(int n) {
    goTo(posX + n);
}

/* Special applications of step() */
void Player::stepLeft() {
    //move(-stepSize, 0);
    step(-stepSize);
}

//void Player::stepLeft(int n) {
//    step(-n);
//}

void Player::stepRight() {
    //move(stepSize,0);
    step(stepSize);
}

//void Player::stepRight(int n) {
//    step(n);
//}

/* Return Player for a stream */
std::ostream& operator<<(std::ostream &strm, const Player &p) {
    strm << "Player at position " << p.getX();
    return strm;
}
