#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "Menu.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../player/Player.hpp"
#include "../region/Hall.hpp"
#include "../window/Background.hpp"

class HealthBar : public sf::Drawable {
public:
    sf::RectangleShape outline;
    sf::RectangleShape health;
    unsigned int& source;
    
    HealthBar(sf::Vector2f pos, sf::Vector2f size, unsigned int& source) : outline(size), health(size), source(source) {
        outline.setPosition(pos);
        outline.setFillColor(sf::Color::Transparent);
        outline.setOutlineColor(sf::Color::Black);
        outline.setOutlineThickness(2);
        health.setPosition(pos);
        health.setFillColor(sf::Color::Green);
        health.setOutlineThickness(0);
    }
    
    HealthBar(const HealthBar& orig) : outline(orig.outline), health(orig.health), source(orig.source) {};
    
    void update() {
        health.setSize(sf::Vector2f(source*5, health.getSize().y));
    }
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(health);
        target.draw(outline);
    };
};

class GameScreen: public Menu {
public:
    GameScreen(Player& player, Background& background, sf::Window& window = DEFAULT_WINDOW);
    GameScreen(Player& player, Background& background, Hall& hall, sf::Window& window = DEFAULT_WINDOW);
    GameScreen(const GameScreen&);
    virtual ~GameScreen();
    
    virtual ScreenMode* run(sf::Event event);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    Player& player;
    Hall& hall;
    Background& background;
    
    HealthBar playerhealth;
};

#endif /* GAMESCREEN_H */