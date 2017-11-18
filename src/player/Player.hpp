#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>

class Player : public sf::Sprite {
public:
    Player();
    Player(const Player& p);
    virtual ~Player();
    
    int getX() const;
    
    /* Set player's x position (absolute) */
    void goTo(int n);
    
    /* Set player's x position (relative) */
    //void move()
    //void step(int n);
    void stepLeft();
    //void stepLeft(int n);
    void stepRight();
    //void stepRight(int n);
    
private:
    int posX;
    int stepSize;
    
    
    /* Return Player for a stream */
    friend std::ostream& operator<<(std::ostream &strm, const Player&);
};

#endif /* PLAYER_H */
