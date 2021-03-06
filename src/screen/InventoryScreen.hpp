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
    sf::Text name;
    
    ItemBox(Item anitem,int h, Player& player);
    ItemBox(const ItemBox& orig) : ItemBox(orig.x,1,orig.player) {};
    ~ItemBox();
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    Item x;
    
    Player& player;

    
};

class InventoryScreen : public ScreenMode{   
public:

    InventoryScreen(Player& player);
    
    InventoryScreen(const InventoryScreen& orig);

    ~InventoryScreen();

    virtual ScreenMode* update(sf::Event event);

    virtual ScreenMode* run(sf::Event event);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    void updateItem();
    
    ItemBox itembox1;
    
    ItemBox itembox2;
    
    ItemBox itembox3;
    
    Player& player;
};



#endif