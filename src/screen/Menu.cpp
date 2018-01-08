#include <cstdlib>
#include <iostream>
#include "Menu.hpp"
#include <SFML/Graphics.hpp>

Menu::Menu(sf::Window& window) : ScreenMode(window) {
    
}

Menu::Menu(const Menu& orig) : ScreenMode(orig.window) {
   
}

Menu::~Menu() {
    
}

int Menu::get1() const {
    return 1;	
}
void Menu::runStuff(){
    std::cout << "This is a Menu";
}
