#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <stdlib.h> 
#include <iostream>
#include "Utils.hpp"

class Animation {
public:
    
    Animation(sf::Texture& texture, int rowNum, int colNum, int extra);
    Animation(const Animation& orig);
    virtual ~Animation();
    void setSpriteSheet(int rowNum, int colNum, int extra);
    sf::Texture& getTexture();
    Loop<sf::IntRect> frames;
    
private:
    float rectWidth;
    float heightWidth;
    
    
    sf::Texture& texture;
    
    
};

#endif /* ANIMATION_H */