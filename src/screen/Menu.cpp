#include <cstdlib>
#include <iostream>
#include "Menu.hpp"
#include <SFML/Graphics.hpp>

Menu::Menu(sf::Window& window, unsigned int topOffset, unsigned int leftOffset, unsigned int height, unsigned int gap)
: ScreenMode(window), buttonSpace(sf::IntRect(leftOffset, topOffset, window.getSize().x - leftOffset*2, height), gap) {
    
}

Menu::Menu(const Menu& orig) : ScreenMode(orig.window), buttonSpace(orig.buttonSpace) {
   
}

Menu::~Menu() {
    
}

void Menu::addButton(std::string text, ScreenMode& link, sf::Font& font) {
    addButton(text, &link, font);
}

void Menu::addButton(std::string text, ScreenMode* link, sf::Font& font) {
    LinkedButton* temp = new LinkedButton(link, window);
    temp->setTitle(*new sf::Text(text, font));
    temp->setOutlineColor(sf::Color::Black);
    ScreenMode::addButton(*temp);
    buttonSpace.fitButtonsToRect(buttons);
}

int Menu::get1() const {
    return 1;	
}
