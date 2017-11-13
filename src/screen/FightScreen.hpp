#ifndef FIGHTSCREEN_H
#define FIGHTSCREEN_H

#include "EncounterScreen.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class FightScreen: public EncounterScreen {
public:
    FightScreen();
    FightScreen(const FightScreen&);
    virtual ~FightScreen();
private:
    
};

#endif /* FIGHTSCREEN_H */