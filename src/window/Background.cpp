#include "Background.hpp"
#include <SFML/Graphics.hpp>

Background::Background(sf::Texture* skyTexture, sf::Texture* horizonBgTexture, sf::Texture* imBgTexture, sf::Texture* groundTexture, sf::RenderWindow& window) {
    sky.setTexture(skyTexture);
    horizonBg.setTexture(horizonBgTexture);
    imBg.setTexture(imBgTexture);
    ground.setTexture(groundTexture);
    
    horizonBg.setTextureRect({ 0, 0, static_cast<int>(window.getSize().x), static_cast<int>(horizonBgTexture.getSize().y) });
    imBg.setTextureRect({ 0, 0, static_cast<int>(window.getSize().x), static_cast<int>(window.getSize().y*3/5)});
    horizonBg.setTextureRect({ 0, 0, static_cast<int>(window.getSize().x), static_cast<int>(horizonBgTexture.getSize().y) });
    
    sky.setPosition(0,0);
    horizonBg.setPosition(0,window.getSize().y*3/16);
    imBg.setPosition(0,window.getSize().y*3/16+15);
    ground.setPosition(0,window.getSize().y*10/16+15);
    
    sky.scale(1, 1);
    horizonBg.scale(1,.9);
    imBg.scale(1, .8);
    ground.setScale(1, .35);
}
Background::Background(const Background& orig) {
    
}
Background::~Background() {
    
}
