#include "GameScreen.hpp"
#include <SFML/Graphics.hpp>

GameScreen::GameScreen(sf::Window& window, Player& player, Background& background) : GameScreen(window, player, background, *new Hall(player, window)) {};

GameScreen::GameScreen(sf::Window& window, Player& player, Background& background, Hall& hall) : ScreenMode(window), player(player), hall(hall), background(background) {
    std::cout << "Hall is " << &hall << ", Player is " << &player << "\n";
    unsigned int numRooms = 3;
    for (unsigned i = 0; i < numRooms; i++) {
        hall.addRoom();
    }
    std::cout << hall << "\n";
};

GameScreen::GameScreen(const GameScreen& orig) : ScreenMode(window), player(orig.player), hall(orig.hall), background(orig.background) {};

GameScreen::~GameScreen() {};

ScreenMode* GameScreen::run(sf::Event event) {
    hall.updateIndex();
    return ScreenMode::checkButtons();
};

void GameScreen::update(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left && player.getX() > 0) {
            player.stepLeft();
            background.move(player.getStepSize());
            hall.updateRoomPositions();
        } 
        if (event.key.code == sf::Keyboard::Right) {
            player.stepRight();
            background.move(-player.getStepSize());
            hall.updateRoomPositions();
        }
    }
};

void GameScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(hall);
    target.draw(player);
    ScreenMode::draw(target, states);
};

std::string GameScreen::testThing() {
    return "This is a default game!";
}
