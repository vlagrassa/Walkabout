#include "DeathScreen.hpp"

DeathScreen::DeathScreen() :deathMessage("You Dead #Oof City", DEFAULT_FONT){
    
    deathMessage.setPosition(200,200);
//    deathMessage.setSize();
//    deathMessage.setFont(DEFAULT_FONT);
    deathMessage.setFillColor(sf::Color::White);
}
DeathScreen::DeathScreen(const DeathScreen& orig){
    
}
DeathScreen::~DeathScreen(){
    
}

void DeathScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.clear(sf::Color::Black);
    target.draw(deathMessage);
}
ScreenMode* DeathScreen::update(sf::Event event){
    
}
ScreenMode* DeathScreen::run(sf::Event event){
    
}
