#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "region/Hall.hpp"
#include "region/Monster.hpp"

int main() {
    std::cout << "\n\n";
    Hall h;
    Monster mon;
    
    h.addRoom(new Room(5, *(new Encounterable())));
    h.addRoom(new Room(9, mon));
    h.addRoom();
    
    std::cout << "\n\n" << h << "\n";
    h.setActiveRoom(0);
    std::cout << h << "\n";
    h.setActiveRoom(-1);
    std::cout << h << "\n";
    h.goToRoom(1, 3);
    std::cout << h << "\n";
    h.printDistances();
    h.goToRoom(0, 0);
    h.printDistances();
    
    std::cout << "\n\n";
    
    h.goTo(0);
    h.printDistances();
    for (unsigned i = 0; i < 6; i++) {
        h.stepRight(2);
        h.printDistances();
    }
    
    for (unsigned i = 0; i < 6; i++) {
        h.stepLeft(2);
        h.printDistances();
    }
    
    
    
    return EXIT_SUCCESS;
}