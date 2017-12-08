#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "../src/player/Player.hpp"
#include "../src/region/Hall.hpp"
#include "../src/screen/Menu.hpp"
#include "../src/window/Background.hpp"

#include "region/Monster.hpp"

int main() {
    Player player;
    Hall h(player);
    
    Encounterable* e = new Monster(dinosaur);
    h.addRoom(new Room(5, e));
    h.addRoom(new Room(2, e));
    h.addRoom(new Room(3, e));
    
    std::cout << "\n";
    h.printDistances();
    std::cout << "(0)    = " << h.getRoomPos(0) << "\n";
    std::cout << "(0, 0) = " << h.getRoomPos(0, 0) << "\n";
    std::cout << "(0, 1) = " << h.getRoomPos(0, 1) << "\n";
    std::cout << "(0, 2) = " << h.getRoomPos(0, 2) << "\n";
    std::cout << "(0, 3) = " << h.getRoomPos(0, 3) << "\n";
    std::cout << "(0, 4) = " << h.getRoomPos(0, 4) << "\n";
    std::cout << "(0, 5) = " << h.getRoomPos(0, 5) << "\n";
    std::cout << "(1)    = " << h.getRoomPos(1) << "\n";
    std::cout << "(1, 0) = " << h.getRoomPos(1, 0) << "\n";
    std::cout << "(1, 1) = " << h.getRoomPos(1, 1) << "\n";
    std::cout << "(1, 2) = " << h.getRoomPos(1, 2) << "\n";
    std::cout << "(2)    = " << h.getRoomPos(2) << "\n";
    std::cout << "(2, 0) = " << h.getRoomPos(2, 0) << "\n";
    std::cout << "(2, 1) = " << h.getRoomPos(2, 1) << "\n";
    std::cout << "(2, 2) = " << h.getRoomPos(2, 2) << "\n";
    std::cout << "(2, 3) = " << h.getRoomPos(2, 3) << "\n";
}