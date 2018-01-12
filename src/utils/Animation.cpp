#include "Animation.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utils.hpp"

Animation::Animation (sf::Texture& texture, int rowNum, int colNum) :texture(texture), frames(){
    setSpriteSheet(rowNum, colNum);
}

Animation::Animation(const Animation& orig) :texture(texture) {
    
}
Animation::~Animation() {
    
}


void Animation::setSpriteSheet(int rowNum, int colNum){
    
    int width = texture.getSize().x/rowNum;
    int height = texture.getSize().y/colNum;
    
    
    
    for(int i = 0; i <rowNum; i++){
        for(int j = 0; i < colNum; i++){
            frames.append(sf::IntRect(j, i, width, height));
        }
    }
}
