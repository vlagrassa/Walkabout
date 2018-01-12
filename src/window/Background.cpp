#include "Background.hpp"
#include "Ambience.hpp"
#include <SFML/Graphics.hpp>

Background::Background(Ambience& setting, sf::RenderWindow& window) {
       /*put textures into background sprite objects*/
    sky.setTexture(*setting.getSky());
    horizonBg.setTexture(*setting.getHorizonBg());
    imBg.setTexture(*setting.getImBg());
    ground.setTexture(*setting.getGround());
    
    /*set sizes for texturess*/
    horizonBg.setTextureRect({ 0, 0, static_cast<int>(window.getSize().x)*3, static_cast<int>(setting.getHorizonBg()->getSize().y) });
    imBg.setTextureRect({ 0, 0, static_cast<int>(window.getSize().x)*5, static_cast<int>(window.getSize().y*3/5)});
    ground.setTextureRect({ 0, 0, static_cast<int>(window.getSize().x)*5, static_cast<int>(setting.getGround()->getSize().y) });
    
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

void Background::move(int stepSize) {
    horizonBg.move(stepSize/2,0);
    imBg.move(stepSize,0);
    ground.move(stepSize,0);
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sky);
    target.draw(horizonBg);
    target.draw(imBg);
    target.draw(ground);
}