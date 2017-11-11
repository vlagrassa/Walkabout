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
    
private:
    int posX;
};

#endif /* PLAYER_H */