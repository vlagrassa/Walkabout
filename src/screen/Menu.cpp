#include <cstdlib>
#include <iostream>
#include "Menu.hpp"
#include <SFML/Graphics.hpp>

Menu::Menu(sf::Window& window, unsigned int topOffset, unsigned int leftOffset, unsigned int height)
: ScreenMode(window), buttonSpace(sf::IntRect(leftOffset, topOffset, window.getSize().x - leftOffset*2, height)) {
    
}

Menu::Menu(const Menu& orig) : ScreenMode(orig.window) {
   
}

Menu::~Menu() {
    
}

void Menu::addMenuOption(std::string text, sf::Font& font, ScreenMode& link) {
    LinkedButton* temp = new LinkedButton(link, window);
    temp->setPosition(buttonSpace.left, buttonSpace.top);
    temp->setSize(sf::Vector2f(buttonSpace.width, buttonSpace.height));
    temp->setTitle(*new sf::Text(text, font));
    addButton(*temp);
    fitButtonsToRect(20);
}

void Menu::fitButtonsToRect(unsigned int gap) {
    unsigned int len = buttons.size;
    unsigned int height = (buttonSpace.height - (gap * (len-1))) / len;
    std::cout << "Height is now " << height << "\n";
    for (unsigned int i = 0; i < len; i++) {
        buttons.get(i).setPosition(buttonSpace.left, buttonSpace.top + i * (height + gap));
        buttons.get(i).setSize(sf::Vector2f(buttonSpace.width, height));
        buttons.get(i).title.setPosition(buttons.get(i).getPosition());
    }
}

int Menu::get1() const {
    return 1;	
}
