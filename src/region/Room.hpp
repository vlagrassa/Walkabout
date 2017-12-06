#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Encounterable.hpp"

class Room {
public:
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Constructor method.
     * @param size The size of the Room
     * @param enc The Encounterable held in the Room
     */
    Room(unsigned int size, Encounterable* enc);
    
    /* Constructor, generates random room from passed integer */
    Room(unsigned int seed);
    
    /* Default constructor */
    Room(const Room& orig);
    
    /* Default destructor */
    virtual ~Room();
    
    /* Getter methods */
    unsigned int getLength() const;
    int getDistance() const; //return distance between player and Encounterable
    Encounterable* getEncounter() const;
    RoomType getType() const;
    EncounterScreen* getScreen() const;
    int getPlayerX() const;
    
    /* Setter methods */
    void setPlayerX(int n);
    
    /* Check if the Room is active */
    bool isActive() const;
    void setActive(const bool& b, int n = 0);
    void activate();
    void deactivate();
    
private:
    /* Encounterable held by the Room */
    Encounterable* thing;
    
    /* Number of tics in the Room */
    const unsigned int length;
    
    /* Position (in tics) of player within Room - only used if Active */
    int playerX;
    
    /* Whether the Room is the current active room of its Hall */
    bool active;
    
    /* Whether the Room has been "defeated" or not */
    bool passed;
    
    /* Return Room for a stream */
    friend std::ostream& operator<<(std::ostream &strm, const Room&);
    
    static Encounterable* genRandomEncounterable(unsigned int seed);
};


#endif /* ROOM_H */
