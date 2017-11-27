#include "Ambience.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

Ambience::Ambience(std::string& resources){
    std::cout << resources;
     if (!skyTexture.loadFromFile(resources + "sky.png"))
    {
         std::cout << "failed to load image sky\n";
    }
    if (!horizonBgTexture.loadFromFile(resources + "horizon_background.png"))
    {
        std::cout << "failed to load image horizon_background\n";
    }
    if (!imBgTexture.loadFromFile(resources + "immidiate_background.png"))
    {
        std::cout << "failed to load image immidiate\n";
    }
    if (!groundTexture.loadFromFile(resources + "ground_outside.png"))
    {
        std::cout << "failed to load image ground\n";
    }
     
    skyTexture.setRepeated(true);
    horizonBgTexture.setRepeated(true);
    imBgTexture.setRepeated(true);
    groundTexture.setRepeated(true);
}

Ambience::Ambience(sf::Texture& sky, sf::Texture& horizon, sf::Texture& immediate, sf::Texture& ground) {
    skyTexture = sky;
    horizonBgTexture = horizon;
    imBgTexture = immediate;
    groundTexture = ground;
    
    skyTexture.setRepeated(true);
    horizonBgTexture.setRepeated(true);
    imBgTexture.setRepeated(true);
    groundTexture.setRepeated(true);
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