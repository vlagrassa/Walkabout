#include "InventoryScreen.hpp"
#include <SFML/Graphics.hpp>

ItemBox::ItemBox(Item anitem) : x(anitem) {
    background.setSize(sf::Vector2f(800,200));
    background.setPosition(sf::Vector2f(0,0));
    background.setFillColor(sf::Color::Red);
    
    item.setSize(sf::Vector2f(100,50));
}

ItemBox::~ItemBox() {
    
}

void ItemBox::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background);
}

InventoryScreen::InventoryScreen(Item anitem) : itembox(anitem){
    
}

InventoryScreen::InventoryScreen(const InventoryScreen& orig) : itembox(orig.itembox.x){
    
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
    target.draw(itembox);
}


