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

void AnimatedSprite::resetTo( int animationIndex){
//    if (Animations.getActive().frames.isFinished()) {
//        
//    }
    
    if (Animations.getActiveIndex() != animationIndex){
//        std::cout << "Changing " << Animations.getActiveIndex() << " to " << animationIndex << "\n";\
        std::cout << "on frame " << Animations.getActive().frames.active <<"\n";
        Animations.getActive().frames.shift();
        if (Animations.getActive().frames.isFinished()){
//            std::cout << "blaze it frames are finished (just like this meme)\n";
            Animations.getActive().frames.reset();
//            std::cout << "on frame after reset" << Animations.getActive().frames.active <<"\n";
            Animations.setActiveIndex(animationIndex);
            Animations.getActive().frames.reset();
//            Animations.getActive().frames.shift();
            
        }
    }
    else{
        
    }
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