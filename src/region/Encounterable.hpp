#ifndef ENCOUNTERABLE_H
#define ENCOUNTERABLE_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Region.hpp"

class Encounterable {
public:
    Encounterable();
    Encounterable(const Encounterable& orig);
    virtual ~Encounterable();
    
    bool isSkippable();
    
private:
    bool skippable;
};


#endif /* ENCOUNTERABLE_H */