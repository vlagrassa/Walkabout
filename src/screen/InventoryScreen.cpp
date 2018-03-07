#include "InventoryScreen.hpp"
#include <SFML/Graphics.hpp>

ItemBox::ItemBox(Item anitem) : x(anitem) {
    
}

ItemBox::~ItemBox() {
    
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


