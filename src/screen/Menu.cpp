#include <cstdlib>
#include <iostream>
#include "Menu.hpp"
#include <SFML/Graphics.hpp>

Menu::Menu(sf::Window& window) : ScreenMode(window) {
    
}

Menu::Menu(const Menu& orig) : ScreenMode(orig.window) {
   
}

Menu::~Menu() {
    
}

LinkedButton& Menu::addMenuOption(std::string text, sf::Font& font, ScreenMode& link) {
    std::cout << "Parameters of addMenuOption (not LinkedButton):\n\"" << text << "\" linked to " << &link << " in window " << &window << "\n";
    LinkedButton temp(link, window);
    temp.setTitle(*new sf::Text(text, font));
    std::cout << "Temp LinkedButton created in addMenuOption:\n" << temp;
    LinkedButton result = addButton(temp);
    std::cout << "Returned to addMenuOption from addButton:\n" << result;
    std::cout << "Above printed manually:\n\"" << std::string(result.title.getString()) << "\" linked to " << &result.link << " in window " << &result.window << "\n";
    return temp;
}

int Menu::get1() const {
    return 1;	
}
