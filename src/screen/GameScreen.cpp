#include "GameScreen.hpp"
#include <SFML/Graphics.hpp>

GameScreen::GameScreen(sf::Window& window) : ScreenMode(window) {
    
}
GameScreen::GameScreen(const GameScreen& orig) : ScreenMode(window) {
    
}
GameScreen::~GameScreen() {
    
}
void GameScreen::drawStuff() {
    
}

std::string GameScreen::testThing() {
    return "This is a default game!";
}