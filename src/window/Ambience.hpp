#ifndef AMBIENCE_H
#define AMBIENCE_H

#include <SFML/Graphics.hpp>
#include <stdlib.h> 
#include <iostream>

class Ambience {
public:
    Ambience(std::string& resources);
    Ambience(const Ambience& orig);
    virtual ~Ambience();
    sf::Texture* getSky();
    sf::Texture* getHorizonBg();
    sf::Texture* getImBg();
    sf::Texture* getGround();
    
private:
    sf::Texture* skyTexture;
    sf::Texture* horizonBgTexture;
    sf::Texture* imBgTexture;
    sf::Texture* groundTexture;
};

#endif /* AMBIENCE_H */
