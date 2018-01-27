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
    this->setTextureRect(Animations.getActive().frames.getStart());
}

void AnimatedSprite::run(sf::Event event){
    if (event.type == sf::Event::KeyPressed){
        //std::cout << "hello hello";
        switch (event.key.code){
            case(sf::Keyboard::Up):
                Animations.getActive().frames.shiftNode();
                this->setTextureRect(Animations.getActive().frames.getActive());
        }
    }
    else {
        this->setTextureRect(sf::IntRect(0,0,0,2));
    }
    
}

//void AnimatedSprite::update(sf::Clock clock){
//    framerate.update(clock, )
//    if(clock.getElapsedTime() => framerate){
//        
//        clock.reset
//    }
//}



Animation& AnimatedSprite::getAnimation(){
    
}