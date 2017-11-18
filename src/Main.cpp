#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "region/Hall.hpp"
#include "region/Monster.hpp"
#include "player/Player.hpp"
#include "screen/Menu.hpp"
#include "screen/FightScreen.hpp"
#include <SFML/Window.hpp>

int main() {
    
    
    
    std::cout << "\n\n=-=-= This is the start of Main =-=-=\n\n";
    
    Player player;
    Hall h(&player);
    int numRooms = 4;
    for (unsigned i = 0; i < numRooms; i++) {
        h.addRoom();
    }
    
    std::cout << h << "\n";
    
    //player.stepRight();
    //h.updateIndex(player);
    std::cout << h << "\n";
    
    std::cout << "Using Hall as vector subclass:\n";
    
    for (Room* r : h) {
        std::cout << *r << "\n";
    }
    //sf::Event event;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Walkabout");

    sf::Texture monsterTexture;
    sf::Texture playerTexture;
    if (!monsterTexture.loadFromFile("resources/monster.png"))
    {
        return -1;
    }
    if (!playerTexture.loadFromFile("resources/player.png"))
    {
        return -1;
    }
    monsterTexture.setSmooth(true);
    playerTexture.setSmooth(true);
    //sf::Sprite sprite;
    //sprite.setTexture(texture);
    h.getActiveRoom()->getEncounter()->setTexture(monsterTexture);
    player.setTexture(playerTexture);
    h.getActiveRoom()->getEncounter()->setPosition((window.getSize().x)/2, (window.getSize().y)/2);
    
    
    
        
    
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::string hi;
        window.clear(sf::Color::White);
        
        
        
        window.draw(*h.getActiveRoom()->getEncounter());
        window.draw(player);
        window.display();
    }
    

    return EXIT_SUCCESS;
}
