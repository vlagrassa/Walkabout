#include "InventoryScreen.hpp"
#include <SFML/Graphics.hpp>
#include "../utils/Defaults.hpp"

ItemBox::ItemBox(Item anitem) : x(anitem) {
    background.setSize(sf::Vector2f(800,200));
    background.setPosition(sf::Vector2f(0,0));
    background.setFillColor(sf::Color(222,184,135));
    
    item.setSize(sf::Vector2f(200,200));
    item.setPosition(sf::Vector2f(0,0));
    item.setFillColor(sf::Color(205,133,63));
    
    info.setFont(DEFAULT_FONT);
    info.setFillColor(sf::Color::Black);
    info.setPosition(200,50);
    info.setString("blabla");
}

ItemBox::~ItemBox() {
    
}

void ItemBox::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(item);
    target.draw(info);
}

InventoryScreen::InventoryScreen(Item anitem) : itembox1(anitem),itembox2(anitem){
    
}

InventoryScreen::InventoryScreen(const InventoryScreen& orig) : itembox1(orig.itembox1.x), itembox2(orig.itembox2.x){
    
}

InventoryScreen::~InventoryScreen() {
    
}

ScreenMode* InventoryScreen::update(sf::Event event) {
    return ScreenMode::update(event);
}

ScreenMode* InventoryScreen::run(sf::Event event) {
    return ScreenMode::run(event);
};

void InventoryScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(itembox1);
    target.draw(itembox2);
}


