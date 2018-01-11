#include "GameScreen.hpp"
#include <SFML/Graphics.hpp>

GameScreen::GameScreen(sf::Window& window) : ScreenMode(window) {
    player = new Player();
    hall = new Hall(*player, window);
    unsigned int numRooms = 3;
    for (unsigned i = 0; i < numRooms; i++) {
        hall.addRoom();
    }
};

GameScreen::GameScreen(const GameScreen& orig) : ScreenMode(window) {};

GameScreen::~GameScreen() {};

virtual ScreenMode* run(sf::Event event) {};

virtual void update(sf::Event) {};

virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const

std::string GameScreen::testThing() {
    return "This is a default game!";
}
