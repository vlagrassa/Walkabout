#include <cstdlib>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "utils/Utils.hpp"
#include "utils/Defaults.hpp"
#include "player/Player.hpp"
#include "region/Hall.hpp"
#include "screen/Menu.hpp"
#include "screen/GameScreen.hpp"
#include "window/Background.hpp"
#include "TextFiling.hpp"

/* Declare the default font instantiated in utils/Defaults.hpp */
sf::Font DEFAULT_FONT;
sf::RectangleShape DEFAULT_RECT;
sf::RenderWindow DEFAULT_WINDOW(sf::VideoMode(800, 600), "Walkabout");

void quitGame(sf::Window& window = DEFAULT_WINDOW) {
    window.close();
}

 
int main() {
    std::cout << "\n\n=-=-= This is the start of Main =-=-=\n\n";
    
    /* Instantiate the default font and rectangle */
    DEFAULT_FONT.loadFromFile("resources/Courier.dfont");
    DEFAULT_RECT.setSize(sf::Vector2f(100, 50));
    DEFAULT_RECT.setFillColor(sf::Color::White);
    DEFAULT_RECT.setOutlineColor(sf::Color::Black);
    DEFAULT_RECT.setOutlineThickness(5);
    DEFAULT_RECT.setPosition(5, 5);
    
    /* Identify the resource directory */
    std::string resourceDir = "resources/";
    
    
    /* Create Window */
    //sf::RenderWindow window(sf::VideoMode(800, 600), "Walkabout");
    // See https://en.sfml-dev.org/forums/index.php?topic=20033.msg144271#msg144271 for explanation of following lines
    DEFAULT_WINDOW.setFramerateLimit(0);
    DEFAULT_WINDOW.setVerticalSyncEnabled(true);
    
    
    /* Instantiate Player */
    Player player;
    
    
    /* Create Ambience (like a texture pack) and Background */
    Ambience standard(resourceDir);
    Background background(standard, DEFAULT_WINDOW);
    
    
    /* Initialize ScreenMode Stack, Menu, and GameScreen */
    Stack<ScreenMode&> listOfScreens;
    Menu mainMenu(300, 250, 180, 20);
    GameScreen testGameScreen(player, background);
    Menu testMenu1(10, 10, 50);
    Menu testMenu2(85, 10, 50);
    Menu testMenu3(160, 10, 50);
    Menu testMenu4(235, 10, 50);
    
    mainMenu.addButton("Play", testGameScreen);
    mainMenu.addButton("Settings", testMenu1);
    mainMenu.addButton("Quit", 0);
    
    testGameScreen.addButton("Hiii", 0);
    testGameScreen.addButton("Main Menu", 0);
    
    testMenu1.addButton("In menu 1", testMenu2);
    testMenu2.addButton("In menu 2", testMenu3);
    testMenu3.addButton("In menu 3", testMenu4);
    testMenu4.addButton("Go back to main", mainMenu);
    
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
    player.setPosition(0,DEFAULT_WINDOW.getSize().x/4);
    
    
    /* Create the debugging text tracking the current hall */
    sf::Text hallText;
    hallText.setFont(DEFAULT_FONT);
    hallText.setCharacterSize(20);
    hallText.setFillColor(sf::Color::Black);
    hallText.setPosition(0, 400);
    
    Oscillator testOsc(sf::Vector2f(10,500), 80);
    
    sf::Clock gameclock;
    
    //int prevUpdateTime = gameclock.getElapsedTime().asMicroseconds();
    
    /* Main loop */
    while (DEFAULT_WINDOW.isOpen()) {
        //std::cout << "Time elapsed = " << (gameclock.getElapsedTime().asMilliseconds() - prevUpdateTime) << "\n";
        //prevUpdateTime = gameclock.getElapsedTime().asMilliseconds();
        
        sf::Event event;
        
        /* Event loop */
        while (DEFAULT_WINDOW.pollEvent(event)) {
            switch(event.type) {
                case (sf::Event::Closed):
                    quitGame();
                    break;
                case (sf::Event::KeyPressed):
                    if (event.key.code == sf::Keyboard::Q) {
                        //If the q key is pressed, go back to the previous screen (if possible)
                        if (listOfScreens.top->hasNext()) {
                            listOfScreens.pop();
                            std::cout << "Quit screen:\n" << listOfScreens << "\n";
                        }
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
        DEFAULT_WINDOW.clear(sf::Color::White);
        
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
                ScreenMode* backScreen = NULL;
                for (Node<ScreenMode&>* n = listOfScreens.top; n != 0; n = n->next) {
                    if (&n->data == nextScreen) {
                        backScreen = &n->data;
                        break;
                    }
                }
                
                if (backScreen == NULL) {
                    /* If the next screen is different from the current screen, push it onto the stack */
                    listOfScreens.push(*nextScreen);
                    std::cout << "Added screen:\n" << listOfScreens << "\n";
                } else {
                    while (&listOfScreens.top->data != backScreen) {
                        listOfScreens.pop();
                    }
                    std::cout << "Moved back to screen:\n" << listOfScreens << "\n";
                }
            }
            /* If neither of the above happened then the next screen is the same as the current screen - don't do anything */
            
            /* Draw the next screen - should this be changed to draw the top of the stack? does it matter? */
            if (nextScreen != NULL) {
                DEFAULT_WINDOW.draw(*nextScreen);
            }
        } else {
            quitGame();
        }
        
        testOsc.updateFrames(gameclock.getElapsedTime().asMilliseconds(), event);
        DEFAULT_WINDOW.draw(testOsc);
        
        /* Draw the paper texture (for aesthetics) and the debugging text (for help) */
        DEFAULT_WINDOW.draw(paper);
        //window.draw(hallText);
        
        /* Display the screen */
        DEFAULT_WINDOW.display();
    }
    
    return EXIT_SUCCESS;
}
