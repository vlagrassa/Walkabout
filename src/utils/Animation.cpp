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
        for(int j = 0; j < colNum; j++){
            frames.append(sf::IntRect(j*width, i*height, width, height));
        }
    }
    //std::cout<< "boom shakalaka " << (frames.getStart().left==frames.getEnd().left) ;
}

sf::Texture& Animation::getTexture(){
    return texture;
}