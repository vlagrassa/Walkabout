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
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Walkabout");
    
    std::cout << "\n\n=-=-= This is the start of Main =-=-=\n\n";
    
    Player player;
    Hall h(&player);
    int numRooms = 4;
    for (unsigned i = 0; i < numRooms; i++) {
        h.addRoom();
    }
    
    std::cout << h << "\n";
    
    player.stepRight();
    h.updateIndex(player);
    std::cout << h << "\n";
    
    std::cout << "Using Hall as vector subclass:\n";
    
    for (Room* r : h) {
        std::cout << *r << "\n";
    }
    //sf::Event event;

    sf::Texture texture;
    if (!texture.loadFromFile("resources/monster.png"))
    {
        return -1;
    }
    texture.setSmooth(true);

    sf::Sprite sprite;
    sprite.setTexture(texture);
    
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
        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }
    

    
    return EXIT_SUCCESS;
}
