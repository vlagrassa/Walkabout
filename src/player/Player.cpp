#include "Player.hpp"
#include "Item.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

Player::Player() : posX(0), posInRoom(0), stepSize(10), stats({0, 0, 0}), healthbar(sf::Vector2f(164, 536), sf::Vector2f(626, 25), health) {
    std::cout << "hi";
}

Player::Player(const Player& p) : posX(p.getX()), posInRoom(p.getPosInRoom()), stepSize(p.getStepSize()), healthbar(p.healthbar) {
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
unsigned maxHealth = 0;
unsigned health = 0;
void Player::changeHealth(int amount){
    health += amount;
}
void Player::modify(Stats playerStat){
    stats.body += playerStat.body;
    stats.mind += playerStat.mind;
    stats.soul += playerStat.soul;
}
unsigned money = 0;
void addMoney(int amount){
    if(amount > money){
        throw std::out_of_range("cost exceed value");
    }
    money += amount;
}

    

        
/*Combat*/
int Player::getCombat(){
    int num = 0;
    num = stats.body + equipment.head->stats.body + equipment.chest->stats.body + equipment.hand->stats.body +
equipment.pocket1->stats.body;
    return num;
}

int Player::getSkill(){
    int num = 0;
    num = stats.mind + equipment.head->stats.mind + equipment.chest->stats.mind + equipment.hand->stats.mind +
equipment.pocket1->stats.mind;
    return num;
}

int Player::getMagic(){
    int num = 0;
    num = stats.soul+ equipment.head->stats.soul + equipment.chest->stats.soul + equipment.hand->stats.soul +
equipment.pocket1->stats.soul;
    return num;
}

/*INVENTORY and EQUIPING*/
Item Player::testEmpty = Item(Bow, "testEmpty",{0,0,0});


void Player::addItem(Item& item){
    itemVector.push_back(item);
}

void Player::equip(Item& item){
    switch(item.type){
        case(Head):
            equipment.head = &item;
            break;
        case(Chest):
            equipment.chest = &item;
            break;
        case(Sword):
        case(Bow):
        case(Staff):
            equipment.hand = &item;
            break;
        case(Book):
        case(Potion):      
            equipment.pocket1 = &item;
            break;
        default:
            /*throw error*/
            break;
    }
}

void Player::run(sf::Event event){
    if (event.type == sf::Event::KeyPressed){
        switch (event.key.code){
            case(sf::Keyboard::Up):
                Animations.getActive().frames.shiftNode();
                this->setTextureRect(Animations.getActive().frames.getActive());
        }
    }
    else {
        this->setTextureRect(sf::IntRect(0,0,0,2));
    }
    
}

/* Return Player for a stream */
std::ostream& operator<<(std::ostream &strm, const Player &p) {
    strm << "Player at position " << p.getX();
    return strm;
}
