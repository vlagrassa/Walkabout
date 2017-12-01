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
    
    /* Set player's x position (absolute) */
    void goTo(int n);
    
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
    
    /* Return Player for a stream */
    friend std::ostream& operator<<(std::ostream &strm, const Player&);
};

#endif /* PLAYER_H */
