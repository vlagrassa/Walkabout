#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "../src/region/Room.hpp"
#include "../src/region/Hall.hpp"
#include "../src/region/Monster.hpp"
#include "../src/player/Player.hpp"
#include "../src/screen/Menu.hpp"
#include "../src/screen/FightScreen.hpp"
#include <cassert>

int main() {
    //Encounterable* e = new Encounterable();
    Encounterable* p = new Monster();
    Monster* m = new Monster();
    
    //std::cout << "\nEncounterable type = " << e->getType() << "\n";
    std::cout << "\nPolymorphed Monster type = " << p->getType() << "\n";
    std::cout << "Monster type = " << m->getType() << "\n";
    
    //Room* re = new Room(5, e);
    Room* rp = new Room(5, p);
    Room* rm = new Room(5, m);
    Room* rs = new Room(2742);
    
    Encounterable* e = rs->getEncounter();
    e->getType();
    
    //std::cout << "\nEncounterable Room type = " << e->getType() << "\n";
    std::cout << "\nPolymorphed Room type = " << rp->getType() << "\n";
    std::cout << "Monster Room type = " << rm->getType() << "\n";
    std::cout << "Generated Room type = " << rs->getType() << "\n";
    
    std::cout << "\n";
    
    Hall h;
    
    //h.addRoom(re);
    h.addRoom(rp);
    h.addRoom(rm);
    h.addRoom(rs);
    
    for (Room* r : h.getListOfRooms()) {
        r->getEncounter()->encounter(player);
    }
    
    Hall h1;
    Hall h2(1234567890);
    
    std::cout << "Hall 1 seed: Expecting pseudorandom number. Got " << h1.getSeed() << ".\n";
    std::cout << "Hall 2 seed: Expecting 1234567890.          Got " << h2.getSeed() << ".\n";
    
}