#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>


class Room {
public:
    Room(int d, Encounterable t);
    Room();
    
    int getSize();
    int getDistance(); //return distance between player and Encounterable
    
private:
    Encounterable thing; //the actual encounterable
    int size;
    bool active;
    bool passed;
};


#endif /* ROOM_H */