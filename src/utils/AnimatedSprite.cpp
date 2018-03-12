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
    std::cout<<"\n first test";
    Animation* newAnimation = new Animation(spriteSheet, rowNum, colNum, extra);
    std::cout<<"\n second test";
    Animations.add(*newAnimation);
    std::cout<<"\n third test";
}
void AnimatedSprite::setAnimation(){
    
    if (getTexture() != &Animations.getActive().getTexture()){
//        std::cout << this <<"helloooooooooooooo\n";
        setTextureRect(Animations.getActive().frames.getStart());
        Animations.getActive().frames.reset();
    }   
    setTexture(Animations.getActive().getTexture());
    
}



Animation& AnimatedSprite::getAnimation(){
    return Animations.getActive();
}