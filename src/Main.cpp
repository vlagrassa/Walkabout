#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "region/Region.hpp"
#include "region/Room.hpp"
#include "region/Hall.hpp"

int main() {
    Hall h;
    std::cout << "Player X = " << h.getPlayerX() << "\n";
    h.stepRight();
    std::cout << "Player X = " << h.getPlayerX() << "\n";
    h.stepRight(5);
    std::cout << "Player X = " << h.getPlayerX() << "\n";
    h.stepLeft();
    std::cout << "Player X = " << h.getPlayerX() << "\n";
    h.stepLeft(3);
    std::cout << "Player X = " << h.getPlayerX() << "\n";
    h.step(-10);
    std::cout << "Player X = " << h.getPlayerX() << "\n";
    h.step(8);
    std::cout << "Player X = " << h.getPlayerX() << "\n";
    
    Encounterable e;
    Room* r = new Room(5);
    std::cout << r->getSize() << "\n";
    
    h.addRoom(r);
    std::cout << "Size of active room = " << h.getActiveRoom()->getSize() << "\n";
    std::cout << "Size of active room = " << h.getRoom(0)->getSize() << "\n";
    
    Room* t = h.getActiveRoom();
    std::cout << t->getSize() << "\n";
    
    std::cout << *r << "\n";
    std::cout << *(h.getRoom(0)) << "\n";
    
    return EXIT_SUCCESS;
}