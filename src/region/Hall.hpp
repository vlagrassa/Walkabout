#ifndef HALL_H
#define HALL_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Room.hpp"
#include "../player/Player.hpp"


class Hall : private std::vector<Room*> {
public:
    /* Constructor */
    Hall(Player* p, int s = genRandomSeed());
    
    /* Default constructor */
    Hall(const Hall& orig);
    
    /* Default destructor */
    virtual ~Hall();
    
    /* Getter methods */
    int getPlayerIndex() const;
    int getSeed() const;
    Room* getRoom(int index) const;
    Room* getActiveRoom() const;
    const Player* getPlayer() const;
    
    /* Update playerIndex and corresponding Rooms */
    void setActiveRoom(int index);
    void setActiveRoom();
    
    void setPlayerT(int n);
    
    /* Add a room to the Hall */
    void addRoom(Room* r);
    void addRoom();
    
    /* Get x position for number of steps into given Room (absolute) */
    int goToRoom(int index, int steps);
    int goToRoom(int index);

    /* Get x position for number of steps into given Room (relative) */
    int stepRoom(int index, int steps);
    int stepRoom(int index);
    
    void recalcLength();
    void printDistances() const;
    
    /* Recalculate values based on other conditions */
    void updateIndex(Player& p);
    
    using vector<Room*>::begin;
    using vector<Room*>::end;
    
private:
    /* Index of the current active Room */
    int playerIndex;
    
    /* The seed to generate new Rooms */
    const int seed;
    
    /* The sum of all the room lengths */
    int totalLength;
    
    /* Pointer to the Player object */
    const Player* player;
    
    /* Generate seed based on the current time */
    static int genRandomSeed();
    
    /* Return Hall for a stream */
    friend std::ostream& operator<<(std::ostream &strm, const Hall&);
};

#endif /* HALL_H */
