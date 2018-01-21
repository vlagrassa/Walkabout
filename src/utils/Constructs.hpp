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
                current.outline.setPosition(left + i * (length + gap), top);
                current.outline.setSize(sf::Vector2f(length, height));
            } else {
                current.outline.setPosition(left, top + i * (length + gap));
                current.outline.setSize(sf::Vector2f(width, length));
            }

            float scaleX = current.title.getGlobalBounds().width / current.outline.getSize().x / 2;
            float scaleY = current.title.getGlobalBounds().height / current.outline.getSize().y;

            current.title.setPosition(current.getCenter().x - (scaleX*current.outline.getSize().x), current.getCenter().y - (scaleY*current.outline.getSize().y));
        }
    }
};

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Abstract class with functionality to run the run() method
 * periodically based on a given frame rate.
 */
class FrameRate {
public:
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * The number of frames that should elapse between each run.
     */
    unsigned int frameRate;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * The previous time the object was updated.
     */
    time_t prevUpdateTime = 0;
    
    FrameRate(unsigned int frameRate) : frameRate(frameRate) {};
    FrameRate(const FrameRate& orig) : frameRate(orig.frameRate), prevUpdateTime(orig.prevUpdateTime) {};
    virtual ~FrameRate() {};
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Run in the main loop to update periodically.
     */
    void updateFrames(time_t newUpdateTime, sf::Event event) {
        if (prevUpdateTime + frameRate <= newUpdateTime) {
            //std::cout << "Previous: " << prevUpdateTime << "\t\tNew: " << newUpdateTime << "\n";
            prevUpdateTime = newUpdateTime;
            run(event);
        }
    };
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Define this in each subclass and it will run periodically
     * based on the given frame rate as long as updateFrames is
     * called.
     */
    virtual void run(sf::Event event) = 0;
};

class Oscillator : public sf::Drawable, public FrameRate {
public:
    unsigned int currentPos = 20;
    unsigned int targetPos;
    int dir = 2;
    sf::RectangleShape outline;
    sf::RectangleShape line;
    
    Oscillator(sf::Vector2f vec, unsigned int frameRate) : FrameRate(frameRate), outline(vec), line(sf::Vector2f(10,10)) {
        line.setFillColor(sf::Color::Cyan);
        line.setOutlineColor(sf::Color::Black);
        line.setOutlineThickness(3);
        line.setPosition(10, 10);
        outline.setFillColor(sf::Color::Black);
        outline.setOutlineColor(sf::Color::Black);
        outline.setOutlineThickness(3);
        outline.setPosition(10, 10);
    };
    Oscillator(const Oscillator& orig) : FrameRate(orig.frameRate) {};
    virtual ~Oscillator() {};
    
    void run(sf::Event event) {
        currentPos += dir;
        if (currentPos >= 500 || currentPos <= 0) dir *= -1;
        line.setSize(sf::Vector2f(line.getPosition().x, currentPos));
    }
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(outline);
        target.draw(line);
    }
};

#endif /* CONSTRUCTS_H */