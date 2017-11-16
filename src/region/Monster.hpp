#ifndef MONSTER_H
#define MONSTER_H

#include <stdlib.h>
#include "Encounterable.hpp"
#include "../screen/FightScreen.hpp"

class Monster: public Encounterable {
public:
    Monster();
    Monster(const Monster& orig);
    virtual ~Monster();
    
    /* Inherited Methods */
    
    FightScreen* getEncounterScreen() const;
    
    /* Implemented Abstract Methods */
    
    bool isSkippable() const;
    
    std::string getTypeName() const;
    
    RoomType getType() const;
    
    void encounter(Player& player);
    
    /* Original Methods */
    
    std::string getName();
    int getHealth();
    
private:
    std::string name;
    int health;
    FightScreen* battle_screen; //should be of type Screen& or something
};

#endif /* MONSTER_H */
