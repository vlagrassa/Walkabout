#ifndef MONSTER_H
#define MONSTER_H

#include <stdlib.h>
#include "Encounterable.hpp"

class Monster: public Encounterable {
public:
    Monster();
    Monster(const Monster& orig);
    virtual ~Monster();
    
    std::string getName();
    int getHealth();
    std::vector<int> getReward();
    
private:
    std::string name;
    int health;
    std::vector<int> reward; //should hold Items
    int battle_screen; //should be of type Screen& or something
};

#endif /* MONSTER_H */