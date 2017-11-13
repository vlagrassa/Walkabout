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
    h.addRoom(new Room(6, &mon));
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
    
    std::cout << "\nRunning Encounterable.getEncounterScreen():\n";
    Encounterable e;
    e.getEncounterScreen();
    
    std::cout << "\nRunning Monster.getEncounterScreen:\n";
    mon.getEncounterScreen();
    
    std::cout << "\nStoring Monster.getEncounterScreen() to EncounterScreen* variable:\n";
    EncounterScreen* encounterscreen = mon.getEncounterScreen();
    std::cout << encounterscreen->testThing() << "\n";
    
    std::cout << "\nStoring Monster.getEncounterScreen() to FightScreen* variable:\n";
    FightScreen* fightscreen = mon.getEncounterScreen();
    std::cout << fightscreen->testThing() << "\n";
    
    std::cout << "\nCreating Room storing Monster class:\n";
    Monster tempMon;
    
    Room testRoom(6, &tempMon);
    
    std::cout << "\nPrinting encounter from Room:\n";
    Encounterable* testEncounter = testRoom.getEncounter();
    std::cout << testEncounter << "\n";
    testEncounter->encounter();
    
    std::cout << "\nPrinting encounter from Room as Monster\n";
    Monster* testMonster = (Monster*)(testRoom.getEncounter());
    std::cout << testMonster << "\n";
    testMonster->getName();
    
    std::cout << "\nStoring new Monster* as Encounterable*:\n";
    Encounterable* testThing = new Monster();
    testThing->encounter();
    
    std::cout << "\nStoring polymorphed Monster in a Room\n";
    Room* monsterRoom = new Room(5, testThing);
    Monster* testMonster2 = (Monster*) monsterRoom->getEncounter();
    std::cout << "Pointer to monster: " <<  testMonster2 << "\n";
    testMonster2->encounter();
    
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