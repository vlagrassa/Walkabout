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
    
    Hall h(5);
    h.addRoom();
    h.addRoom();
    h.addRoom();
    
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
    
    Monster mon;
    mon.encounter();
    
    EncounterScreen encounterscreen = mon.encounter();
    std::cout << encounterscreen.testThing() << "\n";
    
    FightScreen fightscreen = mon.encounter();
    std::cout << fightscreen.testThing() << "\n";
    
    return EXIT_SUCCESS;
}