#ifndef SCREENMODE_H
#define SCREENMODE_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>

#include "../utils/Utils.hpp"
#include "../utils/Defaults.hpp"

class LinkedButton;
class ScreenMode;
class TransitionScreen;

class LinkedButton : public sf::Drawable {
public:
    ScreenMode& link;
    sf::Window& window;
    sf::RectangleShape outline;
    sf::Text title;
    std::string onText = "";
    std::string offText = "";
    sf::Keyboard::Key key = sf::Keyboard::Unknown;
    
    LinkedButton(ScreenMode& link, sf::RectangleShape rect = DEFAULT_RECT, sf::Window& window = DEFAULT_WINDOW);
    LinkedButton(ScreenMode* link, sf::RectangleShape rect = DEFAULT_RECT, sf::Window& window = DEFAULT_WINDOW);
    LinkedButton(const LinkedButton& orig);
    virtual ~LinkedButton();
    
    void setKey(sf::Keyboard::Key k);
    void setTitle(std::string text);
    void setTitles(std::string text1, std::string text2);
    
    sf::Vector2f getCenter();
    
    bool touchingMouse();
    bool clicked();
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    bool isActive();
    void setActive(bool b);
    void activate();
    void deactivate();
    
private:
    bool active = true;
    
    friend std::ostream& operator<<(std::ostream &strm, const LinkedButton& l) {
        return strm << "\"" << std::string(l.title.getString()) << "\" linked to " << &l.link << " in window " << &l.window << "\n";
    }
};

class ScreenMode : public sf::Drawable {
public:
    LinkedList<LinkedButton&> buttons;
    sf::Window& window;
    bool showPrevious = false;
    
    ScreenMode(sf::Window& window = DEFAULT_WINDOW);
    ScreenMode(const ScreenMode& orig);
    virtual ~ScreenMode();
    
    virtual ScreenMode* update(sf::Event event);
    virtual ScreenMode* run(sf::Event event);
    ScreenMode* checkButtons(sf::Event event);
    
    void addButton(LinkedButton& b);
    virtual void addButton(std::string title, ScreenMode& link, sf::Keyboard::Key key = sf::Keyboard::Unknown, sf::Font& font = DEFAULT_FONT);
    virtual void addButton(std::string title, ScreenMode* link, sf::Keyboard::Key key = sf::Keyboard::Unknown, sf::Font& font = DEFAULT_FONT);
    
    void addText(sf::Text);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
private:
    std::vector<sf::Text> displayText;
};

class TransitionScreen : public ScreenMode {
public:
    ScreenMode* link;
    bool forward = true;
    
    TransitionScreen(ScreenMode* link, sf::Window& window = DEFAULT_WINDOW);
    TransitionScreen(const TransitionScreen& orig);
    virtual ~TransitionScreen();
    
    virtual ScreenMode* run(sf::Event event);
    virtual ScreenMode* runForward();
    virtual ScreenMode* runBackward();
};

#endif /* SCREENMODE_H */
