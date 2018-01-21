#ifndef MENU_H
#define MENU_H

#include "ScreenMode.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../utils/Defaults.hpp"
#include "../utils/Constructs.hpp"

class Menu: public ScreenMode {
public:
    ButtonLine buttonline;
    
    Menu(unsigned int topOffset, unsigned int leftOffset, unsigned int height, unsigned int gap = 0, sf::Window& window = DEFAULT_WINDOW); //sf::Vector2i topLeft?
    Menu(const Menu&);
    virtual ~Menu();
    
    virtual void addButton(std::string title, ScreenMode* link, sf::Font& font = DEFAULT_FONT);
    virtual void addButton(std::string title, ScreenMode& link, sf::Font& font = DEFAULT_FONT);
private:
};

#endif /* MENU_H */
