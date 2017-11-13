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
    e.encounter();
    
    mon.encounter();
    
    EncounterScreen encounterscreen = mon.encounter();
    std::cout << encounterscreen.testThing() << "\n";
    
    FightScreen fightscreen = mon.encounter();
    std::cout << fightscreen.testThing() << "\n";
    
    std::vector<EncounterScreen> screenList;
    screenList.push_back(mon.encounter());
    screenList.push_back(e.encounter());
    screenList.push_back(mon.encounter());
    screenList.push_back(e.encounter());
    
    std::cout << "\n\n";
    
    /*
    for (Room* r : h.getListOfRooms()) {
        RoomType temp = r->getType();
        switch (temp) {
            case (monster):
                Monster* tempEncounter = dynamic_cast<Monster*>(&(r->getEncounter()));
                std::cout << tempEncounter.encounter().testThing();
                break;
            default:
                std::cout << r->getEncounter().encounter().testThing() << "\n";
        }
    }
    */
    
    return EXIT_SUCCESS;
}