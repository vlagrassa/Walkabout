#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Item.hpp"
#include "../utils/AnimatedSprite.hpp"
#include "iostream"

class Player : public AnimatedSprite {
public:
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default constructor method. Initializes:
     *   -posX
     *   -posInRoom
     *   -stepSize
     */
    Player();
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default constructor method. Copies:
     *   -posX
     *   -posInRoom
     *   -stepSize
     * 
     * @param Original Room
     */
    Player(const Player& p);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default destructor method.
     */
    virtual ~Player();
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the absolute x position of the Player - the distance
     * from the start of the Hall to the current position. Note
     * that this is distinct from the Player's position within a
     * given Room.
     * 
     * @return Player's absolute x coordinate
     */
    unsigned int getX() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the x position of the Player within the current Room.
     * Note that this is distinct from the Player's x coordinate,
     * which is within the Hall as a whole - this is relative to
     * a specific Room.
     * 
     * @return Player's relative x coordinate within Room
     */
    unsigned int getPosInRoom() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Sets the x position of the Player within the current Room.
     * Note that this is distinct from the Player's x coordinate,
     * which is within the Hall as a whole - this is relative to
     * a specific Room.
     * 
     * @param New Player x coordinate within Room
     */
    void setPosInRoom(unsigned int n);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Explicitly set the Player's absolute position (posX) and
     * relative position within a Room (posInRoom).
     * 
     * @param total The new absolute position
     * 
     * @param inRoom The new relative position
     */
    void setPos(unsigned int total, unsigned int inRoom);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Set Player's x position. Absolute version of step().
     * Equivalent to:
     * 
     *   posX = n;
     * 
     * @param n New x position
     */
    void goTo(unsigned int n);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Set Player's x position relative to the current position.
     * Equivalent to:
     * 
     *   goTo(posX + n);
     * 
     * Note that if n is negative and larger than the current x
     * position -- that is, if posX + n is negative -- posX will
     * be set to 0.
     * 
     * @param n The number of steps to move
     */
    void step(int n);
    
    /* Move the player to the left (negative) */
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Move the Player to the left. Note that this means moving
     * the coordinate in the negative direction. Equivalent to:
     * 
     *   stepLeft(1);
     * 
     * See also stepLeft(int n)
     */
    void stepLeft();
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Move the Player to the left. Note that this means moving
     * the coordinate in the negative direction. Equivalent to:
     * 
     *   step(-n);
     * 
     * See also stepLeft()
     * 
     * @param n The number of steps to move
     */
    void stepLeft(int n);
    
    /* Move the player to the right (positive) */
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Move the Player to the right. Note that this means moving
     * the coordinate in the positive direction. Equivalent to:
     * 
     *   stepRight(1);
     * 
     * See also stepRight(int n)
     */
    void stepRight();
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Move the Player to the right. Note that this means moving
     * the coordinate in the positive direction. Equivalent to:
     * 
     *   step(n);
     * 
     * See also stepRight()
     * 
     * @param n The number of steps to move
     */
    void stepRight(int n);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the Player's step size.
     * 
     * @return Player step size
     */
    
    
    int getStepSize() const;
    
    bool isMovingRight();
    
    bool isMovingLeft();
    
    
    
    /*stats*/
    unsigned maxHealth;
    unsigned health;
    void changeHealth(int amount);
    Stats stats;
    void modify(Stats playerStat);
    unsigned money;
    void addMoney(int amount);
    
    /*Combat*/
    
    int getCombat();
    
    int getSkill();
    
    int getMagic();
    
    /*INVENTORY and EQUIPING*/
    std::vector<Item> itemVector;
    
    void addItem(Item& item);
    
    static Item testEmpty;
    
    struct equipped{
        Item* head = &testEmpty;
        Item* chest = &testEmpty;
        Item* hand = &testEmpty;
        Item* pocket1 = &testEmpty;
    } equipment;
    
    void equip(Item& item);
    
    /*Saving data*/
    void writeData(std::ostream &saveData,Item items[]);
    Player(std::istream& saveData,Item items[]);
    void run(sf::Event event);
    
private:
    /* Absolute position of the Player - in context of Hall */
    unsigned int posX;
    
    /* Relative position of the Player - in context of Room */
    unsigned int posInRoom;
    
    /* How far to move the Player */
    int stepSize;
    
    bool movingRight;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Friend method to return Player for an output stream.
     * 
     * @return Player for a stream
     */
    friend std::ostream& operator<<(std::ostream &strm, const Player&);
};

#endif /* PLAYER_H */
