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
    GameScreen(sf::Window& window);
    GameScreen(const GameScreen&);
    virtual ~GameScreen();
    
    virtual std::string testThing();
    void drawStuff();
private:
    Player* player;
    Hall* hall;
    Background* background;
};

#endif /* GAMESCREEN_H */