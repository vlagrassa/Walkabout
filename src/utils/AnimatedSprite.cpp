#include "Animation.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utils.hpp"
#include "AnimatedSprite.hpp"

AnimatedSprite::AnimatedSprite() : FrameRate(83){
    
}


AnimatedSprite::AnimatedSprite(const AnimatedSprite& orig) : FrameRate(83){
    
}
AnimatedSprite::~AnimatedSprite(){
}

void AnimatedSprite::addAnimation(sf::Texture& spriteSheet, int rowNum, int colNum, int extra){
    Animation* newAnimation = new Animation(spriteSheet, rowNum, colNum, extra);
    Animations.add(*newAnimation);
}

void AnimatedSprite::resetTo( int animationIndex){
    if (Animations.getActiveIndex() != animationIndex){
        Animations.getActive().frames.shift();
        if (Animations.getActive().frames.isFinished()){
            Animations.getActive().frames.reset();
            Animations.setActiveIndex(animationIndex);
            Animations.getActive().frames.reset();
            
        }
    }
    else{
        
    }
}

void AnimatedSprite::setAnimation(){
    
    if (getTexture() != &Animations.getActive().getTexture()){
        setTextureRect(Animations.getActive().frames.getStart());
        Animations.getActive().frames.reset();
    }   
    setTexture(Animations.getActive().getTexture());
    
}



Animation& AnimatedSprite::getAnimation(){
    return Animations.getActive();
}