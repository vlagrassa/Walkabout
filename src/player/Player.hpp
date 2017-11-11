#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>

class Player {
public:
    Player();
    Player(const Player& p);
    virtual ~Player();
    
    int getX() const;
    void setX(int n);
    
    /* Set player's x position (absolute) */
    void goTo(int n);
    
    /* Set player's x position (relative) */
    void step(int n);
    void stepLeft();
    void stepLeft(int n);
    void stepRight();
    void stepRight(int n);
    
private:
    int posX;
};

#endif /* PLAYER_H */