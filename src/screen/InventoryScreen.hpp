#ifndef INVENTORYSCREEN_H
#define INVENTORYSCREEN_H

#include "InventoryScreen.hpp"
#include <SFML/Graphics.hpp>
#include "../player/Item.hpp"
#include "../player/Player.hpp"

class ItemBox{
public:
    sf::RectangleShape background;
    sf::RectangleShape item;
    sf::Text info;
    
    
};

class InventoryScreen{   
public:

    InventoryScreent(Item::Item item);
    
    InventoryScreen(const InventoryScreen& orig);

    ~InventoryScreen();

    ScreenMode* update(sf::Event event);

    ScreenMode* run(sf::Event event);

}


#endif