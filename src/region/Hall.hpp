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
    int getPlayerIndex();
    int getPlayerX();
    int getSeed();
    
    /* Add a room to the Hall */
    void addRoom(Room* r);
    
    /* Generate a random Room from the seed */
    void addRoom();
    
    /* Set the player's x position within the Hall */
    void goTo(int n);
    
    /* Set the player's x position relative to current position */
    void step(int n);
    
    /* Special applications of step() */
    void stepLeft();
    void stepLeft(int n);
    void stepRight();
    void stepRight(int n);
     
    /* Set index of the active Room and update list */
    void setActiveRoom(int n);
    
    /* Return the current active Room */
    Room* getActiveRoom();
    
    /* Return the Room at the given index */
    Room* getRoom(int index);
    
    /* Return the list of Rooms */
    std::vector<Room*> getListOfRooms() const;
    
    /* Send player to position steps within Room at index */
    void Hall::goToRoom(int index, int steps);
    
    /* Send player to beginning of Room at given index */
    void Hall::goToRoom(int index);

    /* Send player to position steps in a given Room relative to current Room */
    void Hall::stepRoom(int index, int steps);

    /* Send player to given Room relative to current Room */
    void Hall::stepRoom(int n);
    
private:
    /* List of Rooms in the Hall */
    std::vector< Room* > listOfRooms;
    
    /* X coordinate of the player within the hall (in terms of tics) */
    int playerX;
    
    /* Index of the current active room */
    int playerIndex;
    
    /* The seed to generate new rooms */
    int seed;
    
    /* Initialize values common to all constructors */
    void initialize();
    
    /* Recalc values based on other conditions */
    void updateIndexAndRoom();
    
    /* Generate seed based on the current time */
    int genRandomSeed();
    
    /* Return Hall for a stream */
    friend std::ostream& operator<<(std::ostream &strm, const Hall&);
};

#endif /* HALL_H */