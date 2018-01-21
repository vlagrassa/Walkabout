#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "Menu.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../player/Player.hpp"
#include "../region/Hall.hpp"
#include "../window/Background.hpp"

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
};

#endif /* GAMESCREEN_H */