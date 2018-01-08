#ifndef TREASURE_H
#define TREASURE_H

#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Encounterable.hpp"
#include "../screen/TreasureScreen.hpp"

class Treasure : public Encounterable {
public:
    /* Con/Destructors */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default constructor method.
     */
    Treasure(sf::Window& window);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default constructor method.
     * @param Original Treasure
     */
    Treasure(const Treasure& orig);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default destructor method. Deletes:
     *   -treasure_screen
     *   -treasure_texture (temporary)
     */
    virtual ~Treasure();
    
    
    /* Inherited Methods */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the EncounterScreen associated with the Encounterable.
     * Overwritten to return a TreasureScreen.
     * 
     * @return FightScreen representing fight with Monster
     */
    TreasureScreen* getEncounterScreen() const;
    
    
    /* Implemented Abstract Methods */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Tells whether the Encounterable can be passed without
     * interacting. For Treasure, this will always be true.
     * 
     * @return Whether Player must interact to pass (true)
     */
    bool isSkippable() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Gets name string associated with a subclass. This value 
     * will be the same for all instances of a given subclass.
     * For Treasure, this will always be "Treasure"
     * 
     * @return String name for given subclass ("Treasure")
     */
    std::string getTypeName() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Gets RoomType enumerator value associated with a subclass.
     * This value will be the same for all instances of a given
     * subclass. For Treasure, this will always be treasure
     * 
     * @return RoomType value for given subclass (treasure)
     */
    RoomType getType() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Interact with the Treasure - WIP
     */
    void encounter(Player& player);
    
    /* Original Methods */
    
    
private:
    /* The associated TreasureScreen */
    TreasureScreen* treasure_screen;
    
    /* Pointer to the Treasure texture */
    sf::Texture* treasure_texture;
};

#endif /* TREASURE_H */
