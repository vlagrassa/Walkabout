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
    
    
    std::cout << h << "\n";
    h.goToRoom(1, 3);
    std::cout << h << "\n";
    h.goToRoom(0, 0);
    std::cout << h << "\n";
    
    return EXIT_SUCCESS;
}