#ifndef DEATHSCREEN_H
#define DEATHSCREEN_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "ScreenMode.hpp"

class DeathScreen: public ScreenMode{
public:
    DeathScreen();
    DeathScreen(const DeathScreen& orig);
    virtual ~DeathScreen();
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual ScreenMode* update(sf::Event event);
    virtual ScreenMode* run(sf::Event event);
    sf::Text deathMessage;
    

private: 
    int help;
            
};
        



#endif /* DEATHSCREEN_HPP */

