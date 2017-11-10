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
    
    Room* t = h.getRoom(0);
    Room* m = h.getRoom(1);
    
    std::cout << *t << "\n";
    t->activate();
    std::cout << *t << "\n";
    t->deactivate();
    std::cout << *t << "\n";
    std::cout << *m << "\n";
    m->setActive(true);
    std::cout << *m << "\n";
    m->setActive(false);
    std::cout << *m << "\n";
    
    std::cout << "\n\n" << h << "\n";
    
    return EXIT_SUCCESS;
}