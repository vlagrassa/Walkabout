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
    Hall h(player);
    unsigned int numRooms = 3;
    for (unsigned i = 0; i < numRooms; i++) {
        h.addRoom();
    }
    std::cout << h << "\n";
    
    
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
    //h.getActiveRoom()->getEncounter()->setPosition((window.getSize().x)/2, (window.getSize().y)/4);
    player.setPosition(0,window.getSize().x/4);
    
    sf::Font font;
    if (!font.loadFromFile("resources/Courier.dfont")) {
        return -1;
    }
    sf::Text hallText;
    hallText.setFont(font);
    hallText.setCharacterSize(24);
    hallText.setFillColor(sf::Color::Black);
    hallText.setPosition(0, 400);
    
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
                if (event.key.code == sf::Keyboard::Left && player.getX() > 0)
                {
                    player.stepLeft(); //Everything else needs to set an absolute position based on this - will prevent going negative, too
                    background.move(player.getStepSize());
                    h.updateRoomPositions();
                } 
                if (event.key.code == sf::Keyboard::Right)
                {
                    player.stepRight();
                    background.move(-player.getStepSize());
                    h.updateRoomPositions();
                } 
            }
        }
        std::string temp;
        temp += "\nPlayer Position: ";
        temp += std::to_string(player.getX());
        temp += "\n";
        temp += h.operator std::string();
        hallText.setString(temp);
        
        std::string hi;
        
        //Hall needs to be updated
        h.updateIndex();
        
        /* Clear the screen */
        window.clear(sf::Color::White);
        
        /* Draw all the things */
        window.draw(background);
        window.draw(h);
        window.draw(player);
        window.draw(paper);
        window.draw(hallText);
        
        /* Display the screen */
        window.display();
    }
    
    return EXIT_SUCCESS;
}
