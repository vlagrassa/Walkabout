#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <SFML/Graphics.hpp>
#include <stdlib.h> 
#include <iostream>
#include "Utils.hpp"
#include "Animation.hpp"

class AnimatedSprite: public sf::Sprite {
public:
    AnimatedSprite();
    AnimatedSprite(const AnimatedSprite& orig);
    virtual ~AnimatedSprite();
    void addAnimation(sf::Texture spriteSheet, int rowNum, int colNum );
    void setAnimation();
    Animation& getAnimation();
    
    
    
    
private:
        
        
    
};

#endif /* ANIMATEDSPRITE_H */