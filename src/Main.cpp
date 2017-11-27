#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "region/Hall.hpp"
#include "window/Ambience.hpp"
#include "region/Monster.hpp"
#include "player/Player.hpp"
#include "screen/Menu.hpp"
#include "window/Background.hpp"
#include "screen/FightScreen.hpp"
#include <SFML/Window.hpp>


int main() {
    std::cout << "\n\n=-=-= This is the start of Main =-=-=\n\n";
    
    std::string resources = "resources/";
    
    
    Player player;
    Hall h(&player);
    unsigned int numRooms = 4;
    for (unsigned i = 0; i < numRooms; i++) {
        h.addRoom();
    }
    
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Walkabout");
    

    /*texture thingys*/
    
    
    sf::Texture paperTexture;
    
    if (!paperTexture.loadFromFile(resources + "paper_texture_yellow.png"))
    {
        return -1;
    }
   
    sf::Sprite paper;
    
    
   
    
    //Ambience standard(resources);
    
    sf::Texture st;
    st.loadFromFile(resources + "sky.png");
    
    sf::Texture ht;
    ht.loadFromFile(resources + "horizon_background.png");
    
    sf::Texture it;
    it.loadFromFile(resources + "immidiate_background.png");
    
    sf::Texture gt;
    gt.loadFromFile(resources + "ground_outside.png");
    
    Ambience standard(st, ht, it, gt);
    
    
    //paper.setTexture(*standard.getHorizonBg());
    paper.setTexture(paperTexture);
    
    Background background( standard, window);
    
    
    //sf::Event event;
    

    sf::Texture monsterTexture;
    sf::Texture playerTexture;
    if (!monsterTexture.loadFromFile(resources + "monster.png"))
    {
        return -1;
    }
    if (!playerTexture.loadFromFile(resources + "player.png"))
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
    player.setPosition(0,window.getSize().x/4);
    
    //h.getActiveRoom()->create(window);
    
    
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
        window.clear(sf::Color::White);
        
        
        /*background*/
        window.draw(background);
        
        window.draw(*h.getActiveRoom()->getEncounter());
        
        window.draw(player);
        window.draw(paper);
        window.display();
    }
    

    return EXIT_SUCCESS;
}
