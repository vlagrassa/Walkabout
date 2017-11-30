#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "player/Player.hpp"
#include "region/Hall.hpp"
#include "screen/Menu.hpp"
#include "window/Background.hpp"


int main() {
    std::cout << "\n\n=-=-= This is the start of Main =-=-=\n\n";
    std::string resourceDir = "resources/";
    
    
    /* Instantiate Player and Hall */
    Player player;
    Hall h(&player);
    unsigned int numRooms = 4;
    for (unsigned i = 0; i < numRooms; i++) {
        h.addRoom();
    }
    
    
    /* Instantiate Menu */
    Menu menu;
    std::cout << menu.get1();
    
    
    /* Create Window */
    sf::RenderWindow window(sf::VideoMode(800, 600), "Walkabout");
    
    
    /* Instantiate the paper texture */
    sf::Texture paperTexture;
    if (!paperTexture.loadFromFile(resourceDir + "paper_texture_yellow.png"))
    {
        return -1;
    }
    sf::Sprite paper;
    paper.setTexture(paperTexture);
    
    
    /* Create Ambience (like a texture pack) and Background */
    Ambience standard(resourceDir);
    Background background(standard, window);
    
    
    /* Create other textures */
    sf::Texture monsterTexture;
    sf::Texture playerTexture;
    if (!monsterTexture.loadFromFile(resourceDir + "monster.png"))
    {
        return -1;
    }
    if (!playerTexture.loadFromFile(resourceDir + "player.png"))
    {
        return -1;
    }
    monsterTexture.setSmooth(true);
    playerTexture.setSmooth(true);
    
    player.setTexture(playerTexture);
    h.getActiveRoom()->getEncounter()->setPosition((window.getSize().x)/2, (window.getSize().y)/4);
    player.setPosition(0,window.getSize().x/4);
    
    
    /* All the window stuff */
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left)
                {
                    background.move(player.getStepSize());
                } 
                if (event.key.code == sf::Keyboard::Right)
                {
                    background.move(-player.getStepSize());
                } 
            }
        }
        
        std::string hi;
        
        /* Clear the screen */
        window.clear(sf::Color::White);
        
        /* Draw all the things */
        window.draw(background);
        window.draw(h);
        window.draw(player);
        window.draw(paper);
        
        /* Display the screen */
        window.display();
    }
    
    return EXIT_SUCCESS;
}
