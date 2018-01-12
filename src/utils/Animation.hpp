#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <stdlib.h> 
#include <iostream>
#include "Utils.hpp"

class Animation {
public:
    
    Animation(sf::Texture& texture, int rowNum, int colNum);
    Animation(const Animation& orig);
    virtual ~Animation();
    void setSpriteSheet();
    
private:
    float rectWidth;
    float heightWidth;
    Loop<sf::IntRect> frames;
    sf::Texture& texture;
    
    
};

#endif /* ANIMATION_H */