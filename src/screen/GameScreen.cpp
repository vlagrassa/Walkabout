#include "GameScreen.hpp"
#include <SFML/Graphics.hpp>

GameScreen::GameScreen(Player& player, Background& background, Ambience& ambience, sf::Window& window ) : GameScreen(player, background, ambience, *new Hall(player, window, ambience), window) {};

GameScreen::GameScreen(Player& player, Background& background, Ambience& ambience, Hall& hall, sf::Window& window) : Menu(475, 10, 75, 20, window), player(player), hall(hall), background(background), icon(sf::RectangleShape(sf::Vector2f(141, 151))) {
    buttonline = ButtonLine(166, 438, 622, 86, 15);
    buttonline.horizontal = true;
    unsigned int numRooms = 3;
    for (unsigned i = 0; i < numRooms; i++) {
        hall.addRoom();
    }
    icon.setPosition(sf::Vector2f(10, 438));
    icon.setOutlineThickness(5);
    icon.setOutlineColor(sf::Color::Black);
    icon.setFillColor(sf::Color::Transparent);
    std::cout << "Monster standing texture Game screen @" << &ambience.monsterStanding << "\n";
};

GameScreen::GameScreen(const GameScreen& orig) : Menu(orig), player(orig.player), hall(orig.hall), background(orig.background), icon(orig.icon) {};

GameScreen::~GameScreen() {};

ScreenMode* GameScreen::run(sf::Event event) {
    hall.updateIndex();
    player.action(event);
    player.updateFrames(DEFAULT_GAMECLOCK, event);
    player.healthbar.update();
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
                    return hall.getActive();
                }
                break;
                
            default:
                break;
        }
        if (event.key.code == sf::Keyboard::Up && hall.canEncounter()) {
            return hall.getActive();
        }
    }
    if (hall.canEncounter() && !hall.getActiveRoom()->encounter->isSkippable()) {
        //return hall.getEncounterScreen();
        buttons.first->data.activate();
    } else {
        buttons.first->data.deactivate();
    }
    if (hall.mustEncounter()) {
        return hall.getActive();
    }
    return ScreenMode::checkButtons(event);
};

void GameScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(hall);
    target.draw(player);
    target.draw(player.healthbar);
    target.draw(icon);
    ScreenMode::draw(target, states);
};
