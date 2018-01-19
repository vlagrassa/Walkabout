#ifndef CONSTRUCTS_H
#define CONSTRUCTS_H

#include <SFML/Graphics.hpp>
#include "Utils.hpp"

class ButtonLine : sf::IntRect {
public:
    bool horizontal;
    unsigned int gap;
    
    ButtonLine(int left, int top, int width, int height, unsigned int gap = 0):
    sf::IntRect(left, top, width, height), gap(gap) {};
    
    ButtonLine(sf::IntRect rect, unsigned int gap = 0) :
    ButtonLine(rect.left, rect.top, rect.width, rect.height, gap) {};
    
    void fitButtonsToRect(LinkedList<LinkedButton&>& buttons) {
        
        unsigned int length = ((horizontal?width:height) - (gap * (buttons.size-1))) / buttons.size;
        
        for (unsigned int i = 0; i < buttons.size; i++) {
            LinkedButton& current = buttons.get(i);
            
            if (horizontal) {
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

class FrameRate {
public:
    unsigned int frameRate;
    time_t prevUpdateTime;
    
    void updateFrames(time_t newUpdateTime) {
        if (prevUpdateTime + frameRate <= newUpdateTime) {
            prevUpdateTime = newUpdateTime;
            run();
        }
    };
    
    virtual void run() = 0;
};

class Oscillator : public sf::RectangleShape, public FrameRate {
public:
    unsigned int currentPos;
    unsigned int targetPos;
    int dir = 2;
    
    Oscillator(sf::Vector2f vec, unsigned int frameRate) : sf::RectangleShape(vec), frameRate(frameRate) {};
    Oscillator(const Oscillator& orig) {};
    virtual ~Oscillator() {};
    
    void run() {
        currentPos += dir;
        if (currentPos >= 500 || currentPos <= 0) dir *= -1;
        setSize(sf::Vector2f(getPosition().x, currentPos));
    }
};

#endif /* CONSTRUCTS_H */