#include "Ambience.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

Ambience::Ambience(std::string resources) {
     if (!skyTexture.loadFromFile(resources + "sky.png"))
    {
         std::cout << "Failed to load image sky.png from directory " << resources << "\n";
    }
    if (!horizonBgTexture.loadFromFile(resources + "horizon_background.png"))
    {
        std::cout << "Failed to load image horizon_background.png from directory " << resources << "\n";
    }
    if (!imBgTexture.loadFromFile(resources + "immidiate_background.png"))
    {
        std::cout << "Failed to load image immidiate_background.png from directory " << resources << "\n";
    }
    if (!groundTexture.loadFromFile(resources + "ground_outside.png"))
    {
        std::cout << "Failed to load image ground_outside.png from directory " << resources << "\n";
    }
     
     initTextures();
}

Ambience::Ambience(sf::Texture& sky, sf::Texture& horizon, sf::Texture& immediate, sf::Texture& ground) {
    skyTexture = sky;
    horizonBgTexture = horizon;
    imBgTexture = immediate;
    groundTexture = ground;
    
    initTextures();
}

Ambience::Ambience( const Ambience& orig){
    
}

Ambience::~Ambience(){
    
}

sf::Texture* Ambience::getSky(){
    return &skyTexture;
}

sf::Texture* Ambience::getHorizonBg(){
    return &horizonBgTexture;
}

sf::Texture* Ambience::getImBg(){
    return &imBgTexture;
}

sf::Texture* Ambience::getGround(){
    return &groundTexture;
}

void Ambience::initTextures() {
    skyTexture.setRepeated(true);
    horizonBgTexture.setRepeated(true);
    imBgTexture.setRepeated(true);
    groundTexture.setRepeated(true);
}