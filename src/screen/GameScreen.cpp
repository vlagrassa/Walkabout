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
    hall->updateIndex();
    return ScreenMode::checkButtons();
};

void GameScreen::update(sf::Event event) {
    std::cout << "Starting update\n";
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left && player->getX() > 0) {
            player->stepLeft(); //Everything else needs to set an absolute position based on this - will prevent going negative, too
            background->move(player->getStepSize());
            hall->updateRoomPositions();
        } 
        if (event.key.code == sf::Keyboard::Right) {
            player->stepRight();
            background->move(-player->getStepSize());
            hall->updateRoomPositions();
        }
    }
    std::cout << "Finished update\n";
};

void GameScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*background);
    target.draw(*hall);
    target.draw(*player);
    ScreenMode::draw(target, states);
};

std::string GameScreen::testThing() {
    return "This is a default game!";
}
