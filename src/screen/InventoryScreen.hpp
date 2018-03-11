#ifndef INVENTORYSCREEN_H
#define INVENTORYSCREEN_H

#include "ScreenMode.hpp"
#include <SFML/Graphics.hpp>
#include "../player/Item.hpp"
#include "../player/Player.hpp"
#include "../utils/Defaults.hpp"


class ItemBox : public sf::Drawable{
public:
    sf::RectangleShape background;
    sf::RectangleShape item;
    sf::Text info;
    
    ItemBox(Item anitem, int h);
    ItemBox(const ItemBox& orig) : ItemBox(orig.x,1) {};
    ~ItemBox();
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    Item x;

    
};

class InventoryScreen : public ScreenMode{   
public:

    InventoryScreen(Item item);
    
    InventoryScreen(const InventoryScreen& orig);

    ~InventoryScreen();

    virtual ScreenMode* update(sf::Event event);

    virtual ScreenMode* run(sf::Event event);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    ItemBox itembox1;
    
    ItemBox itembox2;
    
    ItemBox itembox3;
};



#endif