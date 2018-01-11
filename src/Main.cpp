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
    
    
    /* Create Ambience (like a texture pack) and Background */
    Ambience standard(resourceDir);
    Background background(standard, window);
    
    
    /* Initialize ScreenMode Stack */
    Stack<ScreenMode&> listOfScreens;
    GameScreen testGameScreen(window, player, background);
    listOfScreens.push(testGameScreen);
    
    
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
                    if (event.key.code == sf::Keyboard::Q) {
                        std::cout << "Quitting Screen...\n";
                        if (listOfScreens.top->hasNext()) listOfScreens.pop();
                        std::cout << "Finished quitting Screen.\n";
                    }
                    break;
                default:
                    break;
            }
            if (!listOfScreens.isEmpty()) {
                std::cout << "Updating Screen...\n";
                listOfScreens.top->data.update(event);
                std::cout << "Finished updating Screen.\n";
            }
        }
        
        std::string temp;
        temp += "\nPlayer Position: ";
        temp += std::to_string(player.getX());
        temp += "\n";
        temp += testGameScreen.hall.operator std::string();
        hallText.setString(temp);

        std::string hi;

        /* Clear the screen */
        window.clear(sf::Color::White);
        
        /* Figure out the active screen */
        if (!listOfScreens.isEmpty()) {
            std::cout << "Getting Screen...\n";
            ScreenMode* nextScreen = listOfScreens.top->data.run(event);
            std::cout << "Finished getting Screen.\n";
            if (nextScreen == 0) {
                listOfScreens.pop();
                std::cout << "Removed screen:\n" << listOfScreens << "\n";
            } else if (nextScreen != &listOfScreens.top->data) {
                listOfScreens.push(*nextScreen);
                std::cout << "Added screen:\n" << listOfScreens << "\n";
            }
            std::cout << "Drawing Screen...\n";
            window.draw(*nextScreen);
            std::cout << "Finished drawing Screen.\n";
        }

        /* Draw all the other things */
        window.draw(paper);
        window.draw(hallText);
        
        /* Display the screen */
        window.display();
    }
    
    return EXIT_SUCCESS;
}
