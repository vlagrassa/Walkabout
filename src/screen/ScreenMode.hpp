#ifndef SCREENMODE_H
#define SCREENMODE_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>

class ScreenMode {
public:
    ScreenMode();
    ScreenMode(const ScreenMode& orig);
    virtual ~ScreenMode();
    
    void addText(sf::Text);
    
    bool isActive();
    void setActive();
    void activate();
    void deactivate();
private:
    std::vector<sf::Text> displayText;
    bool active;
};

#endif /* SCREENMODE_H */