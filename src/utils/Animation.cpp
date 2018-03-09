#include "Animation.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utils.hpp"

Animation::Animation (sf::Texture& texture, int rowNum, int colNum, int extra) :texture(texture), frames(){
    setSpriteSheet(rowNum, colNum, extra);
}

Animation::Animation(const Animation& orig) :texture(texture) {
    
}
Animation::~Animation() {
    
}


void Animation::setSpriteSheet(int rowNum, int colNum, int extra){
    
    int width = texture.getSize().x/colNum;
    int height = texture.getSize().y/rowNum;
    
    
    
    for(int i = 0; i <rowNum; i++){
        for(int j = 0; j < colNum; j++){
            if (((i)*colNum + j) < rowNum*colNum-extra){
               frames.append(sf::IntRect(j*width, i*height, width, height));
            }
        }
    }
    //std::cout<< "boom shakalaka " << (frames.getStart().left==frames.getEnd().left) ;
}

sf::Texture& Animation::getTexture(){
    return texture;
}