#ifndef ENCOUNTERSCREEN_H
#define ENCOUNTERSCREEN_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../region/Room.hpp"
#include "../region/Monster.hpp"

class Slider;
class Oscillator;
class FightScreen;
class TreasureScreen;

class Slider : public sf::RectangleShape, public FrameRate {
public:
    unsigned int currentPos = 20;
    int dir;
    Slider(sf::Vector2f size, int frameRate, unsigned int speed = 5) : RectangleShape(size), FrameRate(frameRate), dir(speed) {};
    Slider(const Slider& orig) : RectangleShape(orig), FrameRate(orig), dir(orig.dir) {};
    
    void run(sf::Event event) {};
};

struct TargetArea {
    int center;
    int width;
    sf::Color color;
};

class Oscillator : public sf::Drawable, public FrameRate {
public:
    TargetArea attackArea;
//    TargetArea defendArea;
    sf::RectangleShape outline;
    sf::Vertex areas[10];
    Slider attackSlider;
    enum {
        empty,
        attack,
//        defend,
        damage,
        critical
    } area;
    sf::Color backgroundColor;
    
    Oscillator(sf::Vector2f pos, sf::Vector2f size, unsigned int frameRate) : FrameRate(frameRate), outline(size), attackSlider(sf::Vector2f(10,size.y), frameRate, 5) {
        initShapes(pos);
        scramble();
    };
    
    Oscillator(const Oscillator& orig) : FrameRate(orig.frameRate), attackSlider(orig.attackSlider) {};
    
    virtual ~Oscillator() {};
    
    void run(sf::Event event);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    float getStrength();
    
    void scramble(); //Should be called after a hit
    
private:
    
    void initShapes(sf::Vector2f pos);
    
    void updateArea(); //Should be called in run())
};


class FightScreen: public Room {
public:
    FightScreen(Player& player, int seed, sf::Window &window = DEFAULT_WINDOW);
    FightScreen(const FightScreen&);
    virtual ~FightScreen();
    
    Oscillator attackBar;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    virtual ScreenMode* update(sf::Event event);
    virtual ScreenMode* run(sf::Event event);
    
    virtual Encounterable& genRandomEncounterable(unsigned int seed, sf::Window& window);
    
    std::string testThing();
    
    Monster* monster;
private:
    
};


class TreasureScreen: public Room {
public:
    TreasureScreen(Player& player, int seed, sf::Window& window = DEFAULT_WINDOW);
    TreasureScreen(const TreasureScreen&);
    virtual ~TreasureScreen();
    
    virtual Encounterable& genRandomEncounterable(unsigned int seed, sf::Window& window);
    
    std::string testThing();
private:
    
};

#endif /* ENCOUNTERSCREEN_H */
