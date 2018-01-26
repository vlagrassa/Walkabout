#ifndef CONSTRUCTS_H
#define CONSTRUCTS_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Utils.hpp"
#include "../screen/ScreenMode.hpp"

class Oscillator;

class ButtonLine : sf::IntRect {
public:
    bool horizontal = 0;
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
    void updateFrames(sf::Clock clock, sf::Event event);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Define this in each subclass and it will run periodically
     * based on the given frame rate as long as updateFrames is
     * called.
     */
    virtual void run(sf::Event event) = 0;
};

class Slider : public sf::RectangleShape, public FrameRate {
public:
    unsigned int currentPos = 20;
    int dir = 2;
    Oscillator& base;
    Slider(sf::Vector2f size, int frameRate, Oscillator& base) : RectangleShape(size), FrameRate(frameRate), base(base) {};
    Slider(const Slider& orig) : RectangleShape(orig), FrameRate(orig), base(orig.base) {};
    
    void run(sf::Event event) {};
};

class Oscillator : public sf::Drawable, public FrameRate {
public:
    unsigned int targetPos;
    sf::RectangleShape outline;
    Slider attackSlider;
    
    Oscillator(sf::Vector2f pos, sf::Vector2f size, unsigned int frameRate) : FrameRate(frameRate), outline(size), attackSlider(sf::Vector2f(10,size.y), frameRate, *this) {
        initShapes(pos);
    };
    
    Oscillator(const Oscillator& orig) : FrameRate(orig.frameRate), attackSlider(orig.attackSlider) {};
    
    virtual ~Oscillator() {};
    
    void run(sf::Event event);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
private:
    
    void initShapes(sf::Vector2f pos);
};

#endif /* CONSTRUCTS_H */