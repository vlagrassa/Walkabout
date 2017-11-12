#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "region/Hall.hpp"
#include "region/Monster.hpp"
#include "player/Player.hpp"

int main() {
    std::cout << "\n\n";
    
    Hall h(5);
    h.addRoom();
    h.addRoom();
    h.addRoom();
    
    Player player;
    
    std::cout << player << "\n";
    
    player.goTo(4);
    h.updateIndex(player);
    std::cout << player << "\n" << h << "\n";;
    
    player.stepRight();
    h.updateIndex(player);
    std::cout << player << "\n" << h << "\n";
    
    player.stepRight();
    h.updateIndex(player);
    std::cout << player << "\n" << h << "\n";
    
    player.stepRight(3);
    h.updateIndex(player);
    std::cout << player << "\n" << h << "\n";
    
    player.goTo(h.goToRoom(1));
    h.updateIndex(player);
    std::cout << player << "\n" << h << "\n";
    
    player.goTo(h.stepRoom(1));
    h.updateIndex(player);
    std::cout << player << "\n" << h << "\n";
    
    player.goTo(h.stepRoom(-1,5));
    h.updateIndex(player);
    std::cout << player << "\n" << h << "\n";
    
    return EXIT_SUCCESS;
}