#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>

class Player : public sf::Sprite {
public:
    Player();
    Player(const Player& p);
    virtual ~Player();
    
    /* Return Player's x position */
    unsigned int getX() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the x position of the Player within the current Room.
     * Note that this is distinct from the Player's x coordinate,
     * which is within the Hall as a whole - this is relative to
     * a specific Room.
     * 
     * @return Player's x coordinate within Room
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
    
    /* Set player's x position (absolute) */
    void goTo(unsigned int n);
    
    /* Set player's x position (relative) */
    //void move()
    void step(int n);
    
    /* Move the player to the left (negative) */
    void stepLeft();
    //void stepLeft(int n);
    
    /* Move the player to the right (positive) */
    void stepRight();
    //void stepRight(int n);
    
    /* Return Player's step size */
    int getStepSize() const;
    
private:
    /* Position of the Player (absolute) */
    unsigned int posX;
    
    /* How far to move the Player */
    int stepSize;
    
    /* Player's x coordinate in the room (relative) */
    unsigned int posInRoom;
    
    /* Return Player for a stream */
    friend std::ostream& operator<<(std::ostream &strm, const Player&);
};

#endif /* PLAYER_H */
