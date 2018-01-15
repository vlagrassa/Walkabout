#include <cstdlib>
#include <iostream>
#include "Menu.hpp"
#include <SFML/Graphics.hpp>

Menu::Menu(sf::Window& window, unsigned int topOffset, unsigned int leftOffset, unsigned int height, unsigned int gap)
: ScreenMode(window), buttonSpace(sf::IntRect(leftOffset, topOffset, window.getSize().x - leftOffset*2, height)), gap(gap) {
    
}

Menu::Menu(const Menu& orig) : ScreenMode(orig.window), buttonSpace(orig.buttonSpace) {
   
}

Menu::~Menu() {
    
}

void Menu::addMenuOption(std::string text, sf::Font& font, ScreenMode& link) {
    addMenuOption(text, font, &link);
}

void Menu::addMenuOption(std::string text, sf::Font& font, ScreenMode* link) {
    LinkedButton* temp = new LinkedButton(link, window);
    temp->setTitle(*new sf::Text(text, font));
    temp->setOutlineColor(sf::Color::Black);
    addButton(*temp);
    fitButtonsToRect();
}

void Menu::fitButtonsToRect() {
    unsigned int len = buttons.size;
    unsigned int height = (buttonSpace.height - (gap * (len-1))) / len;
    for (unsigned int i = 0; i < len; i++) {
        LinkedButton& current = buttons.get(i);
        current.setPosition(buttonSpace.left, buttonSpace.top + i * (height + gap));
        current.setSize(sf::Vector2f(buttonSpace.width, height));
        
        float scaleX = current.title.getGlobalBounds().width / current.getSize().x / 2;
        float scaleY = current.title.getGlobalBounds().height / current.getSize().y;
        
        current.title.setPosition(current.getCenter().x - (scaleX*current.getSize().x), current.getCenter().y - (scaleY*current.getSize().y));
    }
}

void Menu::resizeButtonSpace(unsigned int topOffset, unsigned int leftOffset, unsigned int height) {
    buttonSpace = sf::IntRect(leftOffset, topOffset, window.getSize().x - leftOffset*2, height);
    fitButtonsToRect();
}

int Menu::get1() const {
    return 1;	
}
