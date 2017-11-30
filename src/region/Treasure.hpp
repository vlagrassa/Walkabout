#ifndef TREASURE_H
#define TREASURE_H

#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Encounterable.hpp"
#include "../screen/TreasureScreen.hpp"

class Treasure : public Encounterable {
public:
    Treasure();
    Treasure(const Treasure& orig);
    virtual ~Treasure();
    
    /* Inherited Methods */
    
    /* Returns the TreasureScreen associated with the Treasure */
    TreasureScreen* getEncounterScreen() const;
    
    /* Implemented Abstract Methods */
    
    /* Returns whether Treasure is a skippable Encounterable (true) */
    bool isSkippable() const;
    
    /* Returns the name of the Encounterable subclass ("Treasure") */
    std::string getTypeName() const;
    
    /* Returns an enum RoomType value corresponding to the subclass (treasure) */
    RoomType getType() const;
    
    /* Interact with the Encounterable */
    void encounter(Player& player);
    
    /* Original Methods */
    
    
private:
    /* The associated FightScreen */
    TreasureScreen* treasure_screen;
    
    /* Pointer to the Treasure texture */
    sf::Texture* treasure_texture;
    
    /* Return Treasure for a stream */
    friend std::ostream& operator<<(std::ostream &strm, const Treasure&);
};

#endif /* TREASURE_H */
