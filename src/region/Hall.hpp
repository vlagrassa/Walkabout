#ifndef HALL_H
#define HALL_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Room.hpp"
#include "../player/Player.hpp"


class Hall {
public:
    /* Constructor generating a random seed */
    Hall();
    
    /* Constructor using a provided seed */
    Hall(int s);
    
    /* Default constructor */
    Hall(const Hall& orig);
    
    /* Default destructor */
    virtual ~Hall();
    
    /* Getter methods */
    int getPlayerIndex() const;
    int getPlayerX() const;
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

    /* Send player to position steps in given Room (relative) */
    void stepRoom(int index, int steps);
    void stepRoom(int index);
    
    void calcDistances();
    void printDistances() const;
    
    /* Recalculate values based on other conditions */
    void updateIndex(Player& p);
    
    int testThing(Player& p);
    bool testThing(Player& p, int pX);
    
private:
    /* List of Rooms in the Hall */
    std::vector< Room* > listOfRooms;
    
    /* X coordinate of the player within the hall (in terms of tics) */
    int playerX;
    
    /* X coordinate of the player within the current Room */
    int playerT;
    
    /* Index of the current active Room */
    int playerIndex;
    
    /* The seed to generate new Rooms */
    int seed;
    
    /* List of lengths of given rooms, for use in positioning player */
    std::vector<int> distances;
    
    /* The sum of all the room lengths */
    int totalLength;
    
    /* Initialize values common to all constructors */
    void initialize();
    
    /* Generate seed based on the current time */
    int genRandomSeed();
    
    /* Return Hall for a stream */
    friend std::ostream& operator<<(std::ostream &strm, const Hall&);
};

#endif /* HALL_H */