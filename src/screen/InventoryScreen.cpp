#include "InventoryScreen.hpp"
#include <SFML/Graphics.hpp>



InventoryScreen::InventoryScreen(const InventoryScreen& orig){
    
}

InventoryScreen::~InventoryScreen() {
    
}

ScreenMode* InventoryScreen::update(sf::Event event) {
    return ScreenMode::update(event);
}

ScreenMode* InventoryScreen::run(sf::Event event) {
    return ScreenMode::run(event);
};


