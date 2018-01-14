#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <SFML/Graphics.hpp>
#include <stdlib.h> 
#include <iostream>
#include "Utils.hpp"

AnimatedSprite: public sf::Sprite {
public:
    AnimatedSprite(sf::Vector spriteSheets);
    AnimatedSprite();
    virtual ~AnimatedSprite;
    
    
private:
        
        
    
}

#endif /* ANIMATEDSPRITE_H */