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
    
    std::cout << "\n\n" << h << "\n";
    h.setActiveRoom(0);
    std::cout << h << "\n";
    h.setActiveRoom(-1);
    std::cout << h << "\n";
    h.setActiveRoom(1);
    std::cout << h << "\n";
    
    h.printDistances();
    
    return EXIT_SUCCESS;
}