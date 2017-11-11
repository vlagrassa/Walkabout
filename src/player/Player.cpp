#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>


Player::Player() {
    
}
Player::Player(const Player& p) {
    
}
Player::~Player() {
    
}

int Player::getX() const {
    return posX;
}

void Player::setX(int n) {
    posX = n;
}