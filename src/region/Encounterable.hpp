#ifndef ENCOUNTERABLE_H
#define ENCOUNTERABLE_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../screen/EncounterScreen.hpp"

class Encounterable {
public:
    Encounterable();
    Encounterable(const Encounterable& orig);
    virtual ~Encounterable();
    
    bool isSkippable();
    
    virtual std::string getTypeName() const;
    
    EncounterScreen encounter();
    
private:
    bool skippable;
    EncounterScreen screen;
};


#endif /* ENCOUNTERABLE_H */