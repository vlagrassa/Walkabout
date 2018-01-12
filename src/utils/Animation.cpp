#include "Animation.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utils.hpp"

Animation::Animation (sf::Texture& texture, int rowNum, int colNum) :texture(texture), frames(){
    
    
    
}

Animation::Animation(const Animation& orig) :texture(texture) {
    
}
Animation::~Animation() {
    
}


//void Animation::setSpriteSheet(){
//    
//    int width = spriteSheet.getSize()[0]/rowNum;
//    int height = spriteSheet.getSize()[1]/culNum;
//    
//    
//    
//    for(int i = 0; i <rowNum; i++){
//        for(int j = 0; i < colNum; i++){
//            monster1.addFrame(sf::IntRect(j, i, width, height));
//        }
//    }
//}
