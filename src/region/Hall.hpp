#ifndef HALL_H
#define HALL_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Room.hpp"
#include "../player/Player.hpp"


class Hall {
public:
    /* Constructor */
    Hall(int s = genRandomSeed());
    
    /* Default constructor */
    Hall(const Hall& orig);
    
    /* Default destructor */
    virtual ~Hall();
    
    /* Getter methods */
    int getPlayerIndex() const;
    int getPlayerT() const;
    int getSeed() const;
    std::vector<Room*> getListOfRooms() const;
    Room* getRoom(int index);
    Room* getActiveRoom();
    
    /* Update playerIndex and corresponding Rooms */
    void setActiveRoom(int index);
    void setActiveRoom();
    
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
    
private:
    /* List of Rooms in the Hall */
    std::vector< Room* > listOfRooms;
    
    /* X coordinate of the player within the current Room */
    int playerT;
    
    /* Index of the current active Room */
    int playerIndex;
    
    /* The seed to generate new Rooms */
    const int seed;
    
    /* The sum of all the room lengths */
    int totalLength;
    
    /* Generate seed based on the current time */
    static int genRandomSeed();
    
    /* Return Hall for a stream */
    friend std::ostream& operator<<(std::ostream &strm, const Hall&);
};

#endif /* HALL_H */
