#ifndef ENCOUNTERABLE_H
#define ENCOUNTERABLE_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../screen/EncounterScreen.hpp"

enum RoomType {
    unknown,
    monster,
    treasure,
    puzzle
};

class Encounterable {
public:
    Encounterable();
    Encounterable(const Encounterable& orig);
    virtual ~Encounterable();
    
    virtual bool isSkippable() = 0;
    
    virtual std::string getTypeName() const = 0;
    
    virtual EncounterScreen* getEncounterScreen() const;
    
    void initScreen();
    
    virtual std::vector<int> getReward() const; //should return Item or something
    
    virtual void encounter() = 0;
    
    virtual RoomType getType() const = 0;
    
private:
    //bool skippable;
    EncounterScreen* screen;
    std::vector<int> reward;
};


#endif /* ENCOUNTERABLE_H */