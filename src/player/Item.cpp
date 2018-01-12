#include <SFML/Graphics.hpp>
#include "Item.hpp"
#include "utils/Utils.hpp"
#include "Player.hpp"
    

Item::Item(const Item& orig) {
    
}
Item::~Item() {
    
}
Item::Item(ItemType kind, std::string name, Stats stats): type(kind), name(name),
stats(stats);



