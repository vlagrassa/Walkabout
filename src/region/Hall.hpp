#ifndef HALL_H
#define HALL_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Room.hpp"


class Hall {
public:
    Hall();
    Hall(const Hall& orig);
    virtual ~Hall();
    
    /* Get player position */
    int getPlayerIndex();
    int getPlayerX();
    
    /* Add new room to the Hall */
    //void addRoom(Room newRoom);
    void addRoom(int n);
    void addRoom();
    
    /* Set the player's x position within the hall */
    void goTo(int n);
    
    /* Special applications of goTo */
    void step(int n);
    void stepLeft();
    void stepLeft(int n);
    void stepRight();
    void stepRight(int n);
    
    /* Implementations of goTo to move between rooms specifically */
    void goToRoom(int n);
    void stepRoom(int n);
    
    /* Set the active room */
    void changeActiveRoom(int n);
    
    int getActiveRoom();
    int getRoom(int index);
    
private:
    /* List of Rooms in the Hall */
    std::vector<int> testVector;
    //std::vector<Room> listOfRooms;
    
    /* X coordinate of the player within the hall (in terms of tics) */
    int playerX;
    
    /* Index of the current active room */
    int playerIndex;
    
    /* The seed to generate new rooms */
    int seed;
    
    /* Recalc values based on other conditions */
    void updateIndexAndRoom();
};

#endif /* HALL_H */