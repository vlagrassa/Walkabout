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
    
    std::cout << "\n\n";
    
    Monster mon;
    
    Hall h(5);
    h.addRoom();
    h.addRoom();
    h.addRoom(new Room(6, mon));
    h.getRoom(2)->setType(monster);
    
    Player player;
    //Menu pauseScreen;
    
    std::cout << player << "\n";
    
    player.goTo(4);
    h.updateIndex(player);
    std::cout << player << "\n" << h << "\n";;
    
    player.stepRight();
    h.updateIndex(player);
    std::cout << player << "\n" << h << "\n";
    
    Encounterable e;
    e.getEncounterScreen();
    
    mon.getEncounterScreen();
    
    EncounterScreen* encounterscreen = mon.getEncounterScreen();
    std::cout << encounterscreen->testThing() << "\n";
    
    FightScreen* fightscreen = mon.getEncounterScreen();
    std::cout << fightscreen->testThing() << "\n";
    
    std::vector<EncounterScreen*> screenList;
    screenList.push_back(mon.getEncounterScreen());
    screenList.push_back(e.getEncounterScreen());
    screenList.push_back(mon.getEncounterScreen());
    screenList.push_back(e.getEncounterScreen());
    
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
                Monster* tempEncounter = static_cast<Monster*>(e);
                //tempEncounter->initialize();
                std::cout << "Monster* TempEncounter is " << tempEncounter << "\n";
                std::cout << "Getting Screen:" << "\n";
                FightScreen* tempScreen = tempEncounter->getEncounterScreen();
                //FightScreen* tempScreen = dynamic_cast<FightScreen*>(r->getScreen());
                //std::cout << tempEncounter->getEncounterScreen()->testThing() << "\n";
                //tempEncounter->getEncounterScreen();
                //std::cout << tempEncounter->getName() << "\n";
                break;
            }
            default: {
                std::cout << r->getEncounter()->getEncounterScreen()->testThing() << "\n";
                break;
            }
        }
        std::cout << "\n";
    }
    
    return EXIT_SUCCESS;
}