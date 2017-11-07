#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "region/Region.hpp"

int main() {
    Skippable test(10);
    
    int x = test.getTestValue();
    std::cout << x;
    //std::cout << test.getTestValue();
    
    return EXIT_SUCCESS;
}