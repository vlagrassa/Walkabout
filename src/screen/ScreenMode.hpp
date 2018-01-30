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
    
    LinkedButton(ScreenMode& link, sf::RectangleShape rect = DEFAULT_RECT, sf::Window& window = DEFAULT_WINDOW) : link(link), window(window), outline(rect) {
        activate();
        title.setFillColor(sf::Color::Black);
        title.setFont(DEFAULT_FONT);
    };
    
    LinkedButton(ScreenMode* link, sf::RectangleShape rect = DEFAULT_RECT, sf::Window& window = DEFAULT_WINDOW) : LinkedButton(*link, rect, window) {};
    
    LinkedButton(const LinkedButton& orig) : LinkedButton(orig.link, orig.outline, orig.window) {
        key = orig.key;
        onText = orig.onText;
        offText = orig.offText;
    };
    
    virtual ~LinkedButton() {};
    
    void setKey(sf::Keyboard::Key k) {
        key = k;
    }
    
    void setTitle(std::string text) {
        title.setString(text);
        title.setPosition(
                outline.getPosition().x + outline.getSize().x/2 - title.getGlobalBounds().width/2,
                outline.getPosition().y + outline.getSize().y/2 - title.getGlobalBounds().height*3/4
        );
    }
    
    void setTitles(std::string text1, std::string text2) {
        onText = text1;
        offText = text2;
        if (active) {
            setTitle(onText);
        } else {
            setTitle(offText);
        }
    }
    
    sf::Vector2f getCenter() {
        return sf::Vector2f(outline.getPosition().x + outline.getSize().x/2, outline.getPosition().y + outline.getSize().y/2);
    }
    
    bool touchingMouse() {
        return outline.getGlobalBounds().contains(sf::Mouse().getPosition(window).x, sf::Mouse().getPosition(window).y);
    }
    
    bool clicked() {
        return touchingMouse() && sf::Mouse().isButtonPressed(sf::Mouse().Left) && active;
    }
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(outline);
        target.draw(title);
    }
    
    bool isActive() {
        return active;
    }
    
    void setActive(bool b) {
        active = b;
    }
    
    void activate() {
        setActive(true);
        setTitle(onText);
    }
    
    void deactivate() {
        setActive(false);
        setTitle(offText);
    }
    
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
    
    ScreenMode(sf::Window& window = DEFAULT_WINDOW) : window(window) {};
    ScreenMode(const ScreenMode& orig) : window(orig.window) {};
    virtual ~ScreenMode() {};
    
    virtual ScreenMode* run(sf::Event event) {
        return checkButtons(event);
    };
    
    ScreenMode* checkButtons(sf::Event event) {
        for (Node<LinkedButton&>* n = buttons.first; n != 0; n = n->next) {
            if (n->data.clicked() || (event.key.code == n->data.key)) {
                return &n->data.link;
            }
        }
        return this;
    };
    
    void addButton(LinkedButton& b) {
        buttons.add(b);
    }
    
    virtual void addButton(std::string title, ScreenMode& link, sf::Keyboard::Key key = sf::Keyboard::Unknown, sf::Font& font = DEFAULT_FONT) {
        addButton(title, &link, key, font);
    }
    
    virtual void addButton(std::string title, ScreenMode* link, sf::Keyboard::Key key = sf::Keyboard::Unknown, sf::Font& font = DEFAULT_FONT) {
        LinkedButton* temp = new LinkedButton(link, DEFAULT_RECT, window);
        temp->setKey(key);
        temp->setTitles(title, "Unavailable");
        addButton(*temp);
    }
    
    void addText(sf::Text);
    
    bool isActive();
    void setActive();
    void activate();
    void deactivate();
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        for (Node<LinkedButton&>* n = buttons.first; n != 0; n = n->next) {
            //if (n->data.isActive()) {
                target.draw(n->data);
            //}
        }
    }
    
private:
    std::vector<sf::Text> displayText;
};

class TransitionScreen : public ScreenMode {
public:
    ScreenMode* link;
    bool forward = true;
    
    TransitionScreen(ScreenMode* link, sf::Window& window = DEFAULT_WINDOW) : ScreenMode(window), link(link) {
        showPrevious = true;
    };
    
    TransitionScreen(const TransitionScreen& orig) : TransitionScreen(orig.link, orig.window) {};
    
    virtual ~TransitionScreen() {};
    
    virtual ScreenMode* run(sf::Event event) {
        if (forward) {
            return runForward();
        } else {
            return runBackward();
        }
    }
    
    virtual ScreenMode* runForward() {
        std::cout << "Transitioning forward...\n";
        forward = false;
        return link;
    };
    
    virtual ScreenMode* runBackward() {
        forward = true;
        std::cout << "Transitioning backward...\n";
        return NULL;
    };
};

#endif /* SCREENMODE_H */
