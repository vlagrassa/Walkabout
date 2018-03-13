#include "InventoryScreen.hpp"
#include <SFML/Graphics.hpp>
#include "../utils/Defaults.hpp"

ItemBox::ItemBox(Item anitem, int h, Player& player) : x(anitem), player(player){
    background.setSize(sf::Vector2f(800,200));
    background.setPosition(sf::Vector2f(0,h));
    background.setFillColor(sf::Color(222,184,135));
    
    item.setSize(sf::Vector2f(200,200));
    item.setPosition(sf::Vector2f(0,h));
    item.setFillColor(sf::Color(205,133,63));
    
    info.setFont(DEFAULT_FONT);
    info.setFillColor(sf::Color::Black);
    info.setPosition(220,h + 45);
    std::string s = "Mind: ";
    s += std::to_string(anitem.stats.mind) + "\n";
    s += "Body: ";
    s += std::to_string(anitem.stats.body) + "\n";
    s += "Soul: ";
    s += std::to_string(anitem.stats.soul) + "\n";
    info.setString(s);
    
    name.setFont(DEFAULT_FONT);
    name.setFillColor(sf::Color::Black);
    name.setPosition(0,h + 45);
    std::string n;
    n += anitem.name;
    name.setString(n);
}

ItemBox::~ItemBox() {
    
}

void ItemBox::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(item);
    target.draw(info);
    target.draw(name);
}

InventoryScreen::InventoryScreen(Player& player) : 
        itembox1(*player.equipment.head, 0, player), 
        itembox2(*player.equipment.chest, 200, player),
        itembox3(*player.equipment.hand, 400, player), player(player)
{}

InventoryScreen::InventoryScreen(const InventoryScreen& orig) : itembox1(orig.itembox1.x, 0, orig.player),
        itembox2(orig.itembox2.x, 200, orig.player), itembox3(orig.itembox3.x, 400, orig.player), player(orig.player){
    
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
    target.draw(itembox1);
    target.draw(itembox2);
    target.draw(itembox3);
}

void InventoryScreen::updateItem(){
    itembox1.x = *player.equipment.head;
    std::cout << player << player.equipment.head;
    itembox2.x = *player.equipment.head;
    itembox3.x = *player.equipment.head;
}


