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

void AnimatedSprite::addAnimation(sf::Texture& spriteSheet, int rowNum, int colNum ){
    Animation* newAnimation = new Animation(spriteSheet, rowNum, colNum);
    Animations.add(*newAnimation);
}
void AnimatedSprite::setAnimation(){
    this->setTexture(Animations.getActive().getTexture());
//    this->setTextureRect(Animations.getActive().frames.getStart());
}



Animation& AnimatedSprite::getAnimation(){
    
}