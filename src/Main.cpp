#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "region/Region.hpp"
#include "region/Room.hpp"

int main() {
    Skippable test(10);
    
    int x = test.getTestValue();
    std::cout << x << "\n";
    std::cout << test.getTestValue() << "\n";
    
    Hall h;
    std::cout << "Player X = " << h.getPlayerX() << "\n";
    h.stepRight();
    std::cout << "Player X = " << h.getPlayerX() << "\n";
    h.stepRight(5);
    std::cout << "Player X = " << h.getPlayerX() << "\n";
    h.stepLeft();
    std::cout << "Player X = " << h.getPlayerX() << "\n";
    h.stepLeft(3);
    std::cout << "Player X = " << h.getPlayerX() << "\n";
    h.step(-10);
    std::cout << "Player X = " << h.getPlayerX() << "\n";
    h.step(8);
    std::cout << "Player X = " << h.getPlayerX() << "\n";
    
    h.addRoom(9);
    std::cout << h.getActiveRoom();
    
    //Room r;
    
    return EXIT_SUCCESS;
}