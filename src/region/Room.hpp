#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>


class Room {
public:
    Room(int d, Encounterable t);
    Room();
private:
    Encounterable thing;
    int distance;
    boolean active;
    boolean passed;
};


#endif /* ROOM_H */