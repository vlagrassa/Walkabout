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
    
    int get1() const;
private:
    void runStuff();
};

#endif /* MENU_H */
