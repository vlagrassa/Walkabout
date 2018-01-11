#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "ScreenMode.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../player/Player.hpp"
#include "../region/Hall.hpp"
#include "../window/Background.hpp"

class GameScreen: public ScreenMode {
public:
    GameScreen(sf::Window& window, Player& player, Background& background);
    GameScreen(const GameScreen&);
    virtual ~GameScreen();
    
    virtual ScreenMode* run(sf::Event event);
    virtual void update(sf::Event);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    virtual std::string testThing();
    
    Player& player;
    Hall& hall;
    Background& background;
};

#endif /* GAMESCREEN_H */