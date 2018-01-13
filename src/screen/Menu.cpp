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

void Menu::addMenuOption(std::string text, sf::Font& font, ScreenMode& link) {
    LinkedButton* temp = new LinkedButton(link, window);
    temp->setTitle(*new sf::Text(text, font));
    addButton(*temp);
}

int Menu::get1() const {
    return 1;	
}
