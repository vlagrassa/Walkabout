#ifndef HALL_H
#define HALL_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Room.hpp"


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
    int getSeed() const;
    std::vector<Room*> getListOfRooms() const;
    Room* getRoom(int index);
    Room* getActiveRoom();
    
    /* Set index of the active Room and update list */
    void setActiveRoom(int n);
    
    /* Add a room to the Hall */
    void addRoom(Room* r);
    void addRoom();
    
    /* Set player's x position within the Hall (absolute) */
    void goTo(int n);
    
    /* Set player's x position within the Hall (relative) */
    void step(int n);
    void stepLeft();
    void stepLeft(int n);
    void stepRight();
    void stepRight(int n);
     
    /* Send player to position steps in given Room (absolute) */
    void goToRoom(int index, int steps);
    void goToRoom(int index);

    /* Send player to position steps in given Room (relative) */
    void stepRoom(int index, int steps);
    void stepRoom(int index);
    
private:
    /* List of Rooms in the Hall */
    std::vector< Room* > listOfRooms;
    
    /* X coordinate of the player within the hall (in terms of tics) */
    int playerX;
    
    /* Index of the current active Room */
    int playerIndex;
    
    /* The seed to generate new Rooms */
    int seed;
    
    /* Initialize values common to all constructors */
    void initialize();
    
    /* Recalculate values based on other conditions */
    void updateIndexAndRoom();
    
    /* Generate seed based on the current time */
    int genRandomSeed();
    
    /* Return Hall for a stream */
    friend std::ostream& operator<<(std::ostream &strm, const Hall&);
};

#endif /* HALL_H */