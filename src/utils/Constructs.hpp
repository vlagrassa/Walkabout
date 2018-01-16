#ifndef CONSTRUCTS_H
#define CONSTRUCTS_H

#include <SFML/Graphics.hpp>
#include "Utils.hpp"

class ButtonList : sf::IntRect {
public:
    bool vertical;
    unsigned int gap;
    
    ButtonList(int left, int top, int width, int height, unsigned int gap = 0):
    sf::IntRect(left, top, width, height), gap(gap) {};
    
    void fitButtonsToRect(LinkedList<LinkedButton&>& buttons) {
        
        unsigned int length = (height - (gap * (buttons.size-1))) / buttons.size;
        
        for (unsigned int i = 0; i < buttons.size; i++) {
            LinkedButton& current = buttons.get(i);
            
            if (vertical) {
                current.setPosition(left + i * (length + gap), top);
                current.setSize(sf::Vector2f(length, height));
            } else {
                current.setPosition(left, top + i * (length + gap));
                current.setSize(sf::Vector2f(width, length));
            }

            float scaleX = current.title.getGlobalBounds().width / current.getSize().x / 2;
            float scaleY = current.title.getGlobalBounds().height / current.getSize().y;

            current.title.setPosition(current.getCenter().x - (scaleX*current.getSize().x), current.getCenter().y - (scaleY*current.getSize().y));
        }
    }
};

#endif /* CONSTRUCTS_H */