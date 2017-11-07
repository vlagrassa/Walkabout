#ifndef HALL_H
#define HALL_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>


class Hall {
public:
    Hall();
    Hall(const Hall& orig);
    virtual ~Hall();
    
    /* Get player position */
    int getPlayerIndex();
    int getPlayerX();
    
    /* Add new room to the Hall */
    void addRoom(Room newRoom);
    void addRoom(int seed);
    
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
    
private:
    /* List of Rooms in the Hall */
    std::vector<Room> listOfThings;
    
    /* X coordinate of the player within the hall (in terms of tics) */
    int playerX;
    
    /* Index of the current active room */
    int playerIndex;
    
    /* The seed to generate new rooms */
    int seed;
};

#endif /* HALL_H */