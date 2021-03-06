#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <SFML/Graphics.hpp>
#include <stdlib.h> 
#include <iostream>
#include "Utils.hpp"
#include "Animation.hpp"
#include "Constructs.hpp"


class AnimatedSprite: public sf::Sprite, public FrameRate{
public:
    AnimatedSprite();
    AnimatedSprite(const AnimatedSprite& orig);
    virtual ~AnimatedSprite();
    void addAnimation(sf::Texture& spriteSheet, int rowNum, int colNum );
    void setAnimation();
    Animation& getAnimation();
    ActiveList<Animation&> Animations;
    
    
    
    
private:
    
    
        
    
};

#endif /* ANIMATEDSPRITE_H */