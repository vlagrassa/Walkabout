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
    
    bool isSkippable();
    
    virtual std::string getTypeName() const;
    
    virtual EncounterScreen* getEncounterScreen() const;
    
    void initScreen();
    
    //virtual std::vector<int> getReward() const; //should return Item or something
    
    virtual void encounter();
    
    virtual RoomType getType() const = 0;
    
private:
    bool skippable;
    EncounterScreen* screen;
};


#endif /* ENCOUNTERABLE_H */