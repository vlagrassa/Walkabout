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


class FightScreen: public EncounterScreen {
public:
    FightScreen(sf::Window &window);
    FightScreen(const FightScreen&);
    virtual ~FightScreen();
    
    std::string testThing();
private:
    
};


class TreasureScreen: public EncounterScreen {
public:
    TreasureScreen(sf::Window& window);
    TreasureScreen(const TreasureScreen&);
    virtual ~TreasureScreen();
    
    std::string testThing();
private:
    
};

#endif /* ENCOUNTERSCREEN_H */
