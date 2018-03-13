#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include "../utils/Utils.hpp"

typedef int st;
struct Stats{
        st body;
        st mind;
        st soul;     
};

enum ItemType{
    Head,
    Chest,
    Legs,
    Sword,
    Bow,
    Staff,
    Potion,
    Book,    
};


        
class Item {
public:
    Item(const Item& orig);
    virtual ~Item();
    
    const enum ItemType type;
    const std::string name;
    /*Stats*/
    const Stats stats;
    Item(ItemType kind, std::string name, Stats stats);
    bool operator==(const Item &other) const;
    Item& operator=(const Item &other);
};


#endif