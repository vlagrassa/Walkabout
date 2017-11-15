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
    
    Player player;
    Hall h;
    
    for (unsigned i = 0; i < 3; i++) {
        h.addRoom();
    }
    
    std::cout << h << "\n";
    
    player.stepRight();
    h.updateIndex(player);
    std::cout << h << "\n";
    
    return EXIT_SUCCESS;
}
