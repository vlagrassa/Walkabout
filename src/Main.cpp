#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "utils/Utils.hpp"
#include "player/Player.hpp"
#include "region/Hall.hpp"
#include "screen/Menu.hpp"
#include "window/Background.hpp"
#include "TextFiling.hpp"
#include "screen/GameScreen.hpp"


int main() {
    std::cout << "\n\n=-=-= This is the start of Main =-=-=\n\n";
    std::string resourceDir = "resources/";
    
    /* Create Window */
    sf::RenderWindow window(sf::VideoMode(800, 600), "Walkabout");
    window.setFramerateLimit(0); // Fixes stuff, see https://en.sfml-dev.org/forums/index.php?topic=20033.msg144271#msg144271
    window.setVerticalSyncEnabled(true); // This line too
    
    
    /* Instantiate Player and Hall */
    Player player;
    Hall h(player, window);
    unsigned int numRooms = 3;
    for (unsigned i = 0; i < numRooms; i++) {
        h.addRoom();
    }
    std::cout << h << "\n";
    
    
    /* Instantiate TextFiling*/
    TextFiling textfile;
    textfile.killCount();
    
    
    /* Instantiate Menu */
    Menu menu(window);
    std::cout << menu.get1();
    
    
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
    hallText.setCharacterSize(20);
    hallText.setFillColor(sf::Color::Black);
    hallText.setPosition(0, 400);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {
                case (sf::Event::Closed):
                    window.close();
                    break;
                case (sf::Event::KeyPressed):
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
                   break;
                default:
                    break;
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
