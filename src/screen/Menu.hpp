#ifndef MENU_H
#define MENU_H

#include "ScreenMode.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../utils/Defaults.hpp"

class Menu: public ScreenMode {
public:
    sf::IntRect buttonSpace;
    unsigned int gap;
    
    Menu(sf::Window& window, unsigned int topOffset, unsigned int leftOffset, unsigned int height, unsigned int gap = 0); //sf::Vector2i topLeft?
    Menu(const Menu&);
    virtual ~Menu();
    
    virtual void addButton(std::string title, ScreenMode* link, sf::Font& font = DEFAULT_FONT);
    virtual void addButton(std::string title, ScreenMode& link, sf::Font& font = DEFAULT_FONT);
    void fitButtonsToRect();
    void resizeButtonSpace(unsigned int topOffset, unsigned int leftOffset, unsigned int height);
    
    int get1() const;
private:
};

#endif /* MENU_H */
