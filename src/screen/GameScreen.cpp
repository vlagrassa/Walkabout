#include "GameScreen.hpp"
#include <SFML/Graphics.hpp>

HealthBar::HealthBar(sf::Vector2f pos, sf::Vector2f size, unsigned int& source) : outline(size), health(size), source(source) {
    outline.setPosition(pos);
    outline.setFillColor(sf::Color::Transparent);
    outline.setOutlineColor(sf::Color::Black);
    outline.setOutlineThickness(2);
    health.setPosition(pos);
    health.setFillColor(sf::Color::Green);
    health.setOutlineThickness(0);
}

HealthBar::HealthBar(const HealthBar& orig) : outline(orig.outline), health(orig.health), source(orig.source) {};

void HealthBar::update() {
    health.setSize(sf::Vector2f(source*5, health.getSize().y));
}

void HealthBar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(health);
    target.draw(outline);
};



GameScreen::GameScreen(Player& player, Background& background, sf::Window& window) : GameScreen(player, background, *new Hall(player, window), window) {};

GameScreen::GameScreen(Player& player, Background& background, Hall& hall, sf::Window& window) : Menu(475, 10, 75, 20, window), player(player), hall(hall), background(background), playerhealth(sf::Vector2f(164, 550), sf::Vector2f(626, 25), player.health) {
    buttonline = ButtonLine(164, 436, 626, 104, 20);
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
    if (hall.canEncounter() && !hall.getActiveRoom()->getEncounter()->isSkippable()) {
        return hall.getEncounterScreen();
    }
    if (hall.canEncounter() && !hall.getActiveRoom()->getEncounter()->isSkippable()) {
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
