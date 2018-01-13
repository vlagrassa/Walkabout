#ifndef SCREENMODE_H
#define SCREENMODE_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>

#include "../utils/Utils.hpp"

class LinkedButton;
class ScreenMode;

class LinkedButton : public sf::RectangleShape {
public:
    ScreenMode& link;
    sf::Window& window;
    sf::Text title;
    
    LinkedButton(ScreenMode& link, sf::Window& window) : link(link), window(window) {
        setSize(sf::Vector2f(100, 50));
        setOutlineColor(sf::Color::Red);
        setOutlineThickness(5);
        setPosition(10, 20);
    };
    
    LinkedButton(ScreenMode* link, sf::Window& window) : link(*link), window(window) {
        setSize(sf::Vector2f(100, 50));
        setOutlineColor(sf::Color::Cyan);
        setOutlineThickness(5);
        setPosition(350, 20);
    }
    
    LinkedButton(const LinkedButton& orig) : link(orig.link), window(orig.window), title(orig.title) {
        setSize(sf::Vector2f(100, 50));
        setOutlineColor(sf::Color::Green);
        setOutlineThickness(5);
        setPosition(10, 20);
    };
    
    virtual ~LinkedButton() {};
    
    void setTitle(sf::Text& text) {
        title = text;
        title.setPosition(getPosition());
        title.setFillColor(sf::Color::Black);
    }
    
    bool touchingMouse() {
        return getGlobalBounds().contains(sf::Mouse().getPosition(window).x, sf::Mouse().getPosition(window).y);
    }
    
    bool clicked() {
        return touchingMouse() && sf::Mouse().isButtonPressed(sf::Mouse().Left);
    }
    
private:
    friend std::ostream& operator<<(std::ostream &strm, const LinkedButton& l) {
        return strm << "\"" << std::string(l.title.getString()) << "\" linked to " << &l.link << " in window " << &l.window << "\n";
    }
};

class ScreenMode : public sf::Drawable {
public:
    Queue<LinkedButton&> buttons;
    sf::Window& window;
    
    ScreenMode(sf::Window& window) : window(window) {};
    ScreenMode(const ScreenMode& orig) : window(orig.window) {};
    virtual ~ScreenMode() {};
    
    virtual ScreenMode* run(sf::Event event) {
        return checkButtons();
    };
    
    ScreenMode* checkButtons() {
        for (Node<LinkedButton&>* n = buttons.head; n != 0; n = n->next) {
            if (n->data.clicked()) {
                return &n->data.link;
            }
        }
        return this;
    };
    
    LinkedButton& addButton(LinkedButton& b) {
        buttons.enqueue(b);
        std::cout << "Added from addButton:\n\"" << std::string(buttons.tail->data.title.getString()) << "\" linked to " << &buttons.tail->data.link << " in window " << &buttons.tail->data.window << "\n";
        return b;
    }
    
    void addText(sf::Text);
    
    bool isActive();
    void setActive();
    void activate();
    void deactivate();
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        for (Node<LinkedButton&>* n = buttons.head; n != 0; n = n->next) {
            target.draw(n->data);
            target.draw(n->data.title);
        }
    }
    
private:
    std::vector<sf::Text> displayText;
};

#endif /* SCREENMODE_H */
