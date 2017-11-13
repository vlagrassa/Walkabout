#ifndef ENCOUNTERSCREEN_H
#define ENCOUNTERSCREEN_H

#include "ScreenMode.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class EncounterScreen: public ScreenMode {
public:
    EncounterScreen();
    EncounterScreen(const EncounterScreen&);
    virtual ~EncounterScreen();
private:
    
};

#endif /* ENCOUNTERSCREEN_H */