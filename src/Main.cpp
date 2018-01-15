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
    
    
    /* Identify the resource directory */
    std::string resourceDir = "resources/";
    
    
    /* Create Window */
    sf::RenderWindow window(sf::VideoMode(800, 600), "Walkabout");
    // See https://en.sfml-dev.org/forums/index.php?topic=20033.msg144271#msg144271 for explanation of following lines
    window.setFramerateLimit(0);
    window.setVerticalSyncEnabled(true);
    
    
    /* Instantiate the default font (Courier) */
    sf::Font font;
    if (!font.loadFromFile("resources/Courier.dfont")) {
        return -1;
    }
    
    
    /* Instantiate Player */
    Player player;
    
    
    /* Create Ambience (like a texture pack) and Background */
    Ambience standard(resourceDir);
    Background background(standard, window);
    
    
    /* Initialize ScreenMode Stack, Menu, and GameScreen */
    Stack<ScreenMode&> listOfScreens;
    Menu mainMenu(window, 300, 250, 180, 20);
    GameScreen testGameScreen(window, player, background);
    
    mainMenu.addButton("Play", font, testGameScreen);
    mainMenu.addButton("Settings", font, &testGameScreen);
    mainMenu.addButton("Quit", font, 0);
    
    testGameScreen.addButton("Quit", font, 0);
    
    listOfScreens.push(mainMenu);
    
    
    /* Instantiate TextFiling */
    TextFiling textfile;
    textfile.killCount();
    
    
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
    
    
    /* Create the debugging text tracking the current hall */
    sf::Text hallText;
    hallText.setFont(font);
    hallText.setCharacterSize(20);
    hallText.setFillColor(sf::Color::Black);
    hallText.setPosition(0, 400);
    
    
    /* Main loop */
    while (window.isOpen()) {
        sf::Event event;
        
        /* Event loop */
        while (window.pollEvent(event)) {
            switch(event.type) {
                case (sf::Event::Closed):
                    window.close();
                    break;
                case (sf::Event::KeyPressed):
                    if (event.key.code == sf::Keyboard::Q) {
                        //If the q key is pressed, go back to the previous screen (if possible)
                        if (listOfScreens.top->hasNext()) listOfScreens.pop();
                    }
                    break;
                default:
                    break;
            }
        }
        
        /* Update the debugging text */
        std::string temp;
        temp += "\nPlayer Position: ";
        temp += std::to_string(player.getX());
        temp += "\n";
        temp += testGameScreen.hall.operator std::string();
        hallText.setString(temp);
        
        /* Clear the screen */
        window.clear(sf::Color::White);
        
        /* Figure out the active screen */
        if (!listOfScreens.isEmpty()) {
            
            /* Get the next screen */
            ScreenMode* nextScreen = listOfScreens.top->data.run(event);
            
            if (nextScreen == 0) {
                /* If next screen is 0x0 (NULL), pop the current screen (go back) */
                listOfScreens.pop();
                std::cout << "Removed screen:\n" << listOfScreens << "\n";
            }
            else if (nextScreen != &listOfScreens.top->data) {
                /* If the next screen is different from the current screen, push it onto the stack */
                listOfScreens.push(*nextScreen);
                std::cout << "Added screen:\n" << listOfScreens << "\n";
            }
            /* If neither of the above happened then the next screen is the same as the current screen - don't do anything */
            
            /* Draw the next screen - should this be changed to draw the top of the stack? does it matter? */
            if (nextScreen != NULL) {
                window.draw(*nextScreen);
            }
        }
        
        /* Draw the paper texture (for aesthetics) and the debugging text (for help) */
        window.draw(paper);
        //window.draw(hallText);
        
        /* Display the screen */
        window.display();
    }
    
    return EXIT_SUCCESS;
}
