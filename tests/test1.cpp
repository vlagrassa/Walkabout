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
    
    std::cout << "\n\n";
    
    Monster mon;
    
    Hall h(5);
    h.addRoom();
    h.addRoom();
    h.addRoom(new Room(6, &mon));
    
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
    
}
