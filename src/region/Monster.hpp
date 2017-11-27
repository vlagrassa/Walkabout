#ifndef MONSTER_H
#define MONSTER_H

#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Encounterable.hpp"
#include "../screen/FightScreen.hpp"

enum MonsterSpecies {
    dinosaur
};

class Monster: public Encounterable {
public:
    Monster();
    Monster(const Monster& orig);
    virtual ~Monster();
    
    /* Inherited Methods */
    
    /* Returns the FightScreen associated with the Monster */
    FightScreen* getEncounterScreen() const;
    
    /* Implemented Abstract Methods */
    
    /* Returns whether Monster is a skippable Encounterable (false) */
    bool isSkippable() const;
    
    /* Returns the name of the Encounterable subclass ("Monster") */
    std::string getTypeName() const;
    
    /* Returns an enum RoomType value corresponding to the subclass (monster) */
    RoomType getType() const;
    
    /* Interact with the Encounterable */
    void encounter(Player& player);
    
    /* Original Methods */
    
    /* Returns the Monster's name (necessary?) */
    std::string getName() const;
    
    /* Returns the maximum health possible for the Monster */
    int getMaxHealth() const;
    
    /* Returns the Monster's current health */
    int getHealth() const;
    
    /* Returns an enum MonsterSpecies value representing the monster's species */
    MonsterSpecies getSpecies() const;
    
private:
    /* The monster's name */
    std::string name;
    
    /* The maximum health possible */
    int maxHealth;
    
    /* The current health*/
    int health;
    
    /* The associated FightScreen */
    FightScreen* battle_screen;
    
    /* Pointer to the monster texture */
    sf::Texture* monster_texture;
    
    /* Enum to hold what type of monster */
    MonsterSpecies species;
    
    /* Return Monster for a stream */
    friend std::ostream& operator<<(std::ostream &strm, const Monster&);
};

#endif /* MONSTER_H */
