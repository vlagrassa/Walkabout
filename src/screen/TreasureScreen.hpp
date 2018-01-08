#ifndef TREASURESCREEN_H
#define TREASURESCREEN_H

#include "EncounterScreen.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class TreasureScreen: public EncounterScreen {
public:
    TreasureScreen(sf::Window& window);
    TreasureScreen(const TreasureScreen&);
    virtual ~TreasureScreen();
    
    std::string testThing();
private:
    
};

#endif /* TREASURESCREEN_H */
