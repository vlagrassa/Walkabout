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
    Hall h(5);
    Monster mon;
    
    //h.addRoom(new Room(5, *(new Encounterable())));
    //h.addRoom(new Room(9, mon));
    h.addRoom();
    h.addRoom();
    h.addRoom();
    srand(5);
    std::cout << std::to_string(rand()%15+2) << " " << std::to_string(rand()%15+2) << " " << std::to_string(rand()%15+2) << "\n";
    
    std::cout << "\n\n" << h << "\n";
    
    h.setActiveRoom(0);
    std::cout << h << "\n";
    
    h.setActiveRoom(-1);
    std::cout << h << "\n";
    
    h.goToRoom(1, 3);
    h.printDistances();
    std::cout << h << "\n";
    
    h.goToRoom(0, 0);
    h.printDistances();
    std::cout << h << "\n";
    
    std::cout << "\n\n";
    
    h.goTo(0);
    h.printDistances();
    for (unsigned i = 0; i < 6; i++) {
        h.stepRight(3);
        h.printDistances();
        std::cout << h << "\n";
    }
    
    for (unsigned i = 0; i < 6; i++) {
        h.stepLeft(3);
        h.printDistances();
        std::cout << h << "\n";
    }
    
    
    
    return EXIT_SUCCESS;
}