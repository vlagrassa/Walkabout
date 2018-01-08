#ifndef ENCOUNTERSCREEN_H
#define ENCOUNTERSCREEN_H

#include "ScreenMode.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class EncounterScreen: public ScreenMode {
public:
    EncounterScreen(sf::Window& window);
    EncounterScreen(const EncounterScreen&);
    virtual ~EncounterScreen();
    
    virtual std::string testThing();
private:
    
};

#endif /* ENCOUNTERSCREEN_H */
