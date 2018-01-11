#include "GameScreen.hpp"
#include <SFML/Graphics.hpp>

GameScreen::GameScreen(sf::Window& window) : ScreenMode(window) {
    player = new Player();
    hall = new Hall(*player, window);
    unsigned int numRooms = 3;
    for (unsigned i = 0; i < numRooms; i++) {
        hall->addRoom();
    }
};

GameScreen::GameScreen(const GameScreen& orig) : ScreenMode(window) {};

GameScreen::~GameScreen() {};

ScreenMode* GameScreen::run(sf::Event event) {
    
    return ScreenMode::checkButtons();
};

void GameScreen::update(sf::Event) {};

void GameScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {};

std::string GameScreen::testThing() {
    return "This is a default game!";
}
