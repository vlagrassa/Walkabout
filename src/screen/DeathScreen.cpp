#include "DeathScreen.hpp"

DeathScreen::DeathScreen() :deathMessage("You Dead #Oof City", DEFAULT_FONT, 1){
    
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
    return this;
}
ScreenMode* DeathScreen::run(sf::Event event){
    deathMessage.setCharacterSize(deathMessage.getCharacterSize()+1);
    if (deathMessage.getCharacterSize() > 200) DEFAULT_WINDOW.close();
    return this;
}
