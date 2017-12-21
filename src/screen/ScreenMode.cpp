#include <cstdlib>
#include <iostream>
#include "ScreenMode.hpp"
#include <SFML/Graphics.hpp>

ScreenMode::ScreenMode() {
    
}
ScreenMode::ScreenMode(const ScreenMode& orig) {
    
}
ScreenMode::~ScreenMode() {
    
}
void ScreenMode::runStuff(){
   std::cout << "This is a Screen";
}
