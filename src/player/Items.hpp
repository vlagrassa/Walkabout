#ifndef ITEMS_H
#define ITEMS_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>

enum ItemsType{
    Head,
    Chest,
    Legs,
    Sword,
    Bow,
    Staff,
    Potion,
    Book,
       
};


        
class Items {
public:
    Items() : type(Sword), mind(0), body(0), mana(0) {};
    Items(const Items&);
    virtual ~Items();
    
    bool isEquipable();
    
    ItemsType type;
    std::string name = "";
    /*Stats*/
    int mind;
    int body;
    int mana;
};
#endif