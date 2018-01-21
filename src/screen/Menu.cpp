#include <cstdlib>
#include <iostream>
#include "Menu.hpp"
#include <SFML/Graphics.hpp>

Menu::Menu(unsigned int topOffset, unsigned int leftOffset, unsigned int height, unsigned int gap, sf::Window& window)
: ScreenMode(window), buttonline(sf::IntRect(leftOffset, topOffset, window.getSize().x - leftOffset*2, height), gap) {
    
}

Menu::Menu(const Menu& orig) : ScreenMode(orig), buttonline(orig.buttonline) {
   
}

Menu::~Menu() {
    
}

void Menu::addButton(std::string text, ScreenMode& link, sf::Font& font) {
    addButton(text, &link, font);
}

void Menu::addButton(std::string text, ScreenMode* link, sf::Font& font) {
    LinkedButton* temp = new LinkedButton(link, DEFAULT_RECT, window);
    temp->setTitle(*new sf::Text(text, font));
    ScreenMode::addButton(*temp);
    buttonline.fitButtonsToRect(buttons);
}
