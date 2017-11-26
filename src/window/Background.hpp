#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>


class Background {
public:
    Background(sf::Texture* skyTexture, 
            sf::Texture* horizonBgTexture, 
            sf::Texture* imBgTexture, 
            sf::Texture* groundTexture, 
            sf::RenderWindow& window
            );
    Background(const Background& orig);
    virtual ~Background();
    
    
private:
    sf::Sprite sky;
    sf::Sprite horizonBg;
    sf::Sprite imBg;
    sf::Sprite ground;
};


#endif /* BACKGROUND_H */