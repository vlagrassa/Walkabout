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
    
    virtual EncounterScreen* getEncounterScreen() const;
    
    void initScreen();
    
    //virtual std::vector<int> getReward() const; //should return Item or something
    
    virtual void encounter();
    
private:
    bool skippable;
    EncounterScreen* screen;
};


#endif /* ENCOUNTERABLE_H */