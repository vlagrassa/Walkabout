#ifndef ENCOUNTERABLE_H
#define ENCOUNTERABLE_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../player/Player.hpp"

enum RoomType {
    monster,
    treasure,
    trade
};

class Encounterable : public sf::Sprite {
public:
    /* Con/Destructors */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default constructor method - can't be used anyways, this
     * is an abstract class.
     */
    Encounterable();
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default constructor method.
     */
    Encounterable(const Encounterable& orig);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default destructor method. Deletes:
     *   -EncounterScreen screen
     */
    virtual ~Encounterable();
    
    
    /* Inherited */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the list of Items held by the Encounterable - as far
     * as I can tell, all Encounterable subclasses will have one
     * @return vector of Items held by the Encounterable
     */
    virtual std::vector<int> getReward() const;
    
    
    /* Abstract Methods */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Tells whether the Encounterable can be passed. This value
     * will be the same for all instances of a given subclass - 
     * eg, Monster.isSkippable will always be false
     * @return Whether Player must interact to pass
     */
    virtual bool isSkippable() const = 0;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Gets name string associated with a subclass. This value 
     * will be the same for all instances of a given subclass - 
     * eg, Monster.getTypeName will always return "Monster"
     * @return String name for given subclass
     */
    virtual std::string getTypeName() const = 0;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Gets RoomType enumerator value associated with a subclass.
     * This value will be the same for all instances of a given
     * subclass - eg, Monster.getType will always return monster
     * @return RoomType value for given subclass
     */
    virtual RoomType getType() const = 0;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Interact with the Encounterable object - will be specific
     * to each subclass.
     */
    virtual void encounter(Player& player) = 0;
    
private:
    
    /* The list of Items associated with the given Encounterable */
    std::vector<int> reward;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Friend method to return Encounterable for a stream. This
     * has been generalized such that subclasses don't currently
     * overwrite it. Mostly used for printing.
     * 
     * @return Encounterable for a stream
     */
    friend std::ostream& operator<<(std::ostream &strm, const Encounterable&);
    
    friend bool operator==(const Encounterable& left, const Encounterable& right);
};

#endif /* ENCOUNTERABLE_H */
