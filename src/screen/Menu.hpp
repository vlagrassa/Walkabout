#ifndef MENU_H
#define MENU_H

#include "ScreenMode.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class Menu: public ScreenMode {
public:
    Menu();
    Menu(const Menu&);
    virtual ~Menu();
private:
    
};

#endif /* MENU_H */
