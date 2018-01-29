#include "GameScreen.hpp"
#include <SFML/Graphics.hpp>

GameScreen::GameScreen(Player& player, Background& background, sf::Window& window) : GameScreen(player, background, *new Hall(player, window), window) {};

GameScreen::GameScreen(Player& player, Background& background, Hall& hall, sf::Window& window) : Menu(475, 10, 75, 20, window), player(player), hall(hall), background(background), playerhealth(sf::Vector2f(164, 536), sf::Vector2f(626, 25), player.health) {
    buttonline = ButtonLine(166, 438, 622, 86, 20);
    buttonline.horizontal = true;
    std::cout << "Hall is " << &hall << ", Player is " << &player << "\n";
    unsigned int numRooms = 3;
    for (unsigned i = 0; i < numRooms; i++) {
        hall.addRoom();
    }
    std::cout << hall << "\n";
};

GameScreen::GameScreen(const GameScreen& orig) : Menu(orig), player(orig.player), hall(orig.hall), background(orig.background), playerhealth(playerhealth) {};

GameScreen::~GameScreen() {};

ScreenMode* GameScreen::run(sf::Event event) {
    hall.updateIndex();
    player.updateFrames(DEFAULT_GAMECLOCK, event);
    playerhealth.update();
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case (sf::Keyboard::Left):
                if (player.getX() > 0) {
                    player.stepLeft();
                    background.move(player.getStepSize());
                    hall.updateRoomPositions();
                }
                break;
                
            case (sf::Keyboard::Right):
                player.stepRight();
                background.move(-player.getStepSize());
                hall.updateRoomPositions();
                break;
                
            case (sf::Keyboard::Up):
                if (hall.canEncounter()) {
                    return hall.getEncounterScreen();
                }
                break;
                
            default:
                break;
        }
        if (event.key.code == sf::Keyboard::Up && hall.canEncounter()) {
            return hall.getEncounterScreen();
        }
    }
    if (hall.canEncounter() && !hall.getActiveRoom()->encounter->isSkippable()) {
        return hall.getEncounterScreen();
    }
    if (hall.canEncounter() && !hall.getActiveRoom()->encounter->isSkippable()) {
        return hall.getEncounterScreen();
    }
    return ScreenMode::checkButtons(event);
};

void GameScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(hall);
    target.draw(player);
    target.draw(playerhealth);
    ScreenMode::draw(target, states);
};
