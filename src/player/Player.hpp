#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>

class Player {
public:
    int getX() const;
    int setX();
    
private:
    int posX;
};

#endif /* PLAYER_H */