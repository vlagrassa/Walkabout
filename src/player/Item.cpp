#include <SFML/Graphics.hpp>
#include "Item.hpp"
#include "Player.hpp"
#include "../utils/Utils.hpp"
    

Item::Item(const Item& orig) {
    
}
Item::~Item() {
    
}
Item::Item(ItemType kind, std::string name, Stats stats): type(kind), name(name),
stats(stats), unsigned int(value);



