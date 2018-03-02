#include <SFML/Graphics.hpp>
#include "Item.hpp"
#include "Player.hpp"
#include "../utils/Utils.hpp"
    

Item::Item(const Item& orig): type(orig.type), name(orig.name),
stats(orig.stats){
    
}
Item::~Item() {
    
}
Item::Item(ItemType kind, std::string name, Stats stats): type(kind), name(name),
stats(stats){};

bool Item::operator==(const Item &other) const{
    return(other.name == name);
}
Item& Item::operator =(const Item& other){
    return *this;
}

