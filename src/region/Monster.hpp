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
    
    std::string getName();
    int getHealth();
    std::vector<int> getReward();
    
    std::string getTypeName() const;
    
    RoomType getType() const;
    
    FightScreen* getEncounterScreen() const;
    
    //void initialize();
    
    void encounter();
    
private:
    std::string name;
    int health;
    std::vector<int> reward; //should hold Items
    FightScreen* battle_screen; //should be of type Screen& or something
};

#endif /* MONSTER_H */