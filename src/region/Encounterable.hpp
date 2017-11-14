#ifndef ENCOUNTERABLE_H
#define ENCOUNTERABLE_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../screen/EncounterScreen.hpp"
#include "../player/Player.hpp"

enum RoomType {
    monster,
    treasure,
    puzzle
};

class Encounterable {
public:
    Encounterable();
    Encounterable(const Encounterable& orig);
    virtual ~Encounterable();
    
    /* Inherited */
    
    /* Returns a list of Items held by the Encounterable - as far as I can tell, all Encounterable subclasses will have one */
    virtual std::vector<int> getReward() const; //should return Item or something
    
    /* Returns the EncounterScreen associated with the Encounterable */
    virtual EncounterScreen* getEncounterScreen() const;
    
    /* Abstract Methods */
    
    /* Returns whether the Encounter can be passed without interacting with it - this value is the same for each subclass */
    virtual bool isSkippable() const = 0;
    
    /* Returns a string associated with the given subclass, eg "Monster" */
    virtual std::string getTypeName() const = 0;
    
    /* Returns the RoomType enum value associated with the given subclass */
    virtual RoomType getType() const = 0;
    
    /* Interact with the Encounterable - will vary for each subclass */
    virtual void encounter(Player& player) = 0;
    
private:
    /* A pointer to the associated EncounterScreen */
    EncounterScreen* screen;
    
    /* The list of Items associated with the given Encounterable */
    std::vector<int> reward;
};


#endif /* ENCOUNTERABLE_H */
