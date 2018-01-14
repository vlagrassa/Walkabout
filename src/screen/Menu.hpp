#ifndef MENU_H
#define MENU_H

#include "ScreenMode.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class Menu: public ScreenMode {
public:
    sf::IntRect buttonSpace;
    
    Menu(sf::Window& window, unsigned int topOffset, unsigned int leftOffset, unsigned int height); //sf::Vector2i topLeft?
    Menu(const Menu&);
    virtual ~Menu();
    
    void addMenuOption(std::string text, sf::Font& font, ScreenMode& link);
    void fitButtonsToRect(unsigned int gap);
    void resizeButtonSpace(unsigned int topOffset, unsigned int leftOffset, unsigned int height);
    
    int get1() const;
private:
};

#endif /* MENU_H */
