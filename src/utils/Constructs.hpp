#ifndef CONSTRUCTS_H
#define CONSTRUCTS_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Utils.hpp"
#include "../screen/ScreenMode.hpp"

class ButtonLine : sf::IntRect {
public:
    bool horizontal;
    unsigned int gap;
    
    ButtonLine(int left, int top, int width, int height, unsigned int gap = 0):
    sf::IntRect(left, top, width, height), gap(gap) {};
    
    ButtonLine(sf::IntRect rect, unsigned int gap = 0) :
    ButtonLine(rect.left, rect.top, rect.width, rect.height, gap) {};
    
    void fitButtonsToRect(LinkedList<LinkedButton&>& buttons);
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
    void updateFrames(time_t newUpdateTime, sf::Event event);
    
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
    
    Oscillator(sf::Vector2f pos, sf::Vector2f size, unsigned int frameRate) : FrameRate(frameRate), outline(size), line(sf::Vector2f(size.x,10)) {
        initShapes(pos);
    };
    
    Oscillator(const Oscillator& orig) : FrameRate(orig.frameRate) {};
    
    virtual ~Oscillator() {};
    
    void run(sf::Event event);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
private:
    
    void initShapes(sf::Vector2f pos);
};

#endif /* CONSTRUCTS_H */