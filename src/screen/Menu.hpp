#ifndef MENU_H
#define MENU_H

#include "ScreenMode.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class Menu: public ScreenMode {
public:
    Menu(sf::Window& window);
    Menu(const Menu&);
    virtual ~Menu();
    
    LinkedButton& addMenuOption(std::string text, sf::Font& font, ScreenMode& link);
    
    int get1() const;
private:
};

#endif /* MENU_H */
