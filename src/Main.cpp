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
    
    Encounterable* e = new Encounterable();
    Encounterable* p = new Monster();
    Monster* m = new Monster();
    
    std::cout << "\nEncounterable type = " << e->getType() << "\n";
    std::cout << "Polymorphed Monster type = " << p->getType() << "\n";
    std::cout << "Monster type = " << m->getType() << "\n";
    
    Room* re = new Room(5, e);
    Room* rp = new Room(5, p);
    Room* rm = new Room(5, m);
    
    std::cout << "\nEncounterable Room type = " << e->getType() << "\n";
    std::cout << "Polymorphed Room type = " << p->getType() << "\n";
    std::cout << "Monster Room type = " << m->getType() << "\n";
    
    //Room* tempRoom = new Room(6, tempMon);
    //std::cout << "Testing overriding or whatever\n";
    //tempRoom->getEncounter()->encounter();
    
    /*
    std::cout << "\n\n";
    for (unsigned i = 0; i < h.getListOfRooms().size(); i++) {
    //for (Room* r : h.getListOfRooms()) {
        Room* r = h.getRoom(i);
        RoomType temp = r->getType();
        std::cout << temp << " ";
        switch (temp) {
            
            case (monster): {
                std::cout << i << ":\n";
                std::cout << "Getting Encounter:" << "\n";
                Encounterable* e = r->getEncounter();
                std::cout << "Default Encounter is " << e << "\n";
                Monster* tempEncounter = reinterpret_cast<Monster*>(e);
                //tempEncounter->initialize();
                std::cout << "\nMonster* TempEncounter is " << tempEncounter << "\n";
                std::cout << "Getting Screen:" << "\n";
                //FightScreen* tempScreen = tempEncounter->getEncounterScreen();
                //std::cout << tempScreen->testThing() << "\n";
                //FightScreen* tempScreen = dynamic_cast<FightScreen*>(r->getScreen());
                //std::cout << tempEncounter->getEncounterScreen()->testThing() << "\n";
                //tempEncounter->getEncounterScreen();
                //std::cout << tempEncounter->getName() << "\n";
                break;
            }
            
            case (monster): {
                std::cout << i << ":\n";
                std::cout << "Getting Encounter:" << "\n";
                Encounterable* e = r->getEncounter();
                std::cout << "Default Encounter is " << e << "\n";
                
                std::cout << "Getting Screen:" << "\n";
                //Monster* reinterpret = reinterpret_cast<Monster*>(e);
                //Monster* dynamic = dynamic_cast<Monster*>(e);
                //Monster* staticCast = static_cast<Monster*>(e);
                
                //std::cout << reinterpret << "\n";
                //std::cout << dynamic << "\n";
                //std::cout << staticCast << "\n";
                break;
            }
            
            default: {
                //std::cout << r->getEncounter()->getEncounterScreen()->testThing() << "\n";
                std::cout << "Encounter " << i << " is not viable.\n";
                break;
            }
        }
        std::cout << "\n";
    }
    */
    
    return EXIT_SUCCESS;
}