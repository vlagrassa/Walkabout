#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "region/Hall.hpp"
#include "region/Monster.hpp"
#include "player/Player.hpp"
#include "screen/Menu.hpp"
#include "screen/FightScreen.hpp"

int main() {
    
    std::cout << "\n\n=-=-= This is the start of Main =-=-=\n\n";
    
    //Encounterable* e = new Encounterable();
    Encounterable* p = new Monster();
    Monster* m = new Monster();
    
    //std::cout << "\nEncounterable type = " << e->getType() << "\n";
    std::cout << "\nPolymorphed Monster type = " << p->getType() << "\n";
    std::cout << "Monster type = " << m->getType() << "\n";
    
    //Room* re = new Room(5, e);
    Room* rp = new Room(5, p);
    Room* rm = new Room(5, m);
    
    //std::cout << "\nEncounterable Room type = " << e->getType() << "\n";
    std::cout << "\nPolymorphed Room type = " << p->getType() << "\n";
    std::cout << "Monster Room type = " << m->getType() << "\n";
    
    std::cout << "\n";
    
    Hall h;
    
    //h.addRoom(re);
    h.addRoom(rp);
    h.addRoom(rm);
    
    for (Room* r : h.getListOfRooms()) {
        switch (r->getType()) {
            case (monster): {
                std::cout << "This is a monster!\n";
                break;
            }
            case (unknown): {
                std::cout << "I don't know what you did, but you did it wrong.\n";
                std::cout << "    [This message displays when an Encounterable has been instantiated.]\n    [In the final program, this should be an abstract class.]\n";
                break;
            }
            default: {
                std::cout << "This is default.\n";
                break;
            }
        }
    }
    
    return EXIT_SUCCESS;
}