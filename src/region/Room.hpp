#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Encounterable.hpp"


enum RoomType {
    unknown,
    monster,
    treasure,
    puzzle
};

class Room {
public:
    /* Constructor, takes length and Encounterable */
    Room(int d, Encounterable* t);
    
    /* Constructor, generates random room from passed integer */
    Room(int seed);
    
    /* Default constructor */
    Room(const Room& orig);
    
    /* Default destructor */
    virtual ~Room();
    
    /* Getter methods */
    int getLength() const;
    int getDistance() const; //return distance between player and Encounterable
    Encounterable* getEncounter() const;
    RoomType getType() const;
    EncounterScreen* getScreen() const;
    
    /* Setter methods */
    void setLength(const int& n);
    //void setEncounter(const Encounterable& e);
    void setType(RoomType t);
    
    /* Check if the Room is active */
    bool isActive() const;
    void setActive(const bool& b);
    void activate();
    void deactivate();
    
private:
    /* Encounterable held by the Room */
    Encounterable* thing;
    
    /* The type of Encounterable held in the Room */
    RoomType type;
    
    /* Number of tics in the Room */
    int length;
    
    /* Whether the Room is the current active room of its Hall */
    bool active;
    
    /* Whether the Room has been "defeated" or not */
    bool passed;
    
    /* Return Room for a stream */
    friend std::ostream& operator<<(std::ostream &strm, const Room&);
};


#endif /* ROOM_H */