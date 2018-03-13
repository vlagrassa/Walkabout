#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Ambience.hpp"


class Background: public sf::Drawable {
public:
    Background(Ambience& setting, sf::RenderWindow& window);
    Background(const Background& orig);
    virtual ~Background();
    
    void move(int stepSize);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    Ambience ambience;
    
private:
    sf::Sprite sky;
    sf::Sprite horizonBg;
    sf::Sprite imBg;
    sf::Sprite ground;
};


#endif /* BACKGROUND_H */