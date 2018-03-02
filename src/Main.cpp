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

/* Declare the defaults instantiated in utils/Defaults.hpp */
sf::Font DEFAULT_FONT;
sf::RectangleShape DEFAULT_RECT;
sf::RenderWindow DEFAULT_WINDOW(sf::VideoMode(800, 600), "Walkabout");
sf::Clock DEFAULT_GAMECLOCK;


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * Function to quit the game. At the moment, just closes the
 * given window, but can be expanded to save the game.
 * 
 * Note that if no parameters are given, this will use the
 * DEFAULT_WINDOW.
 * 
 * @PARAM window The game window (defaults to DEFAULT_WINDOW)
 */
void quitGame(sf::Window& window = DEFAULT_WINDOW) {
    window.close();
}

 
int main() {
    std::cout << "\n\n=-=-= This is the start of Main =-=-=\n\n";
    sf::Clock AnimationClock;
    /* Instantiate the defaults */
    DEFAULT_FONT.loadFromFile("resources/Courier.dfont");
    
    DEFAULT_RECT.setSize(sf::Vector2f(100, 50));
    DEFAULT_RECT.setFillColor(sf::Color::White);
    DEFAULT_RECT.setOutlineColor(sf::Color::Black);
    DEFAULT_RECT.setOutlineThickness(5);
    DEFAULT_RECT.setPosition(5, 5);
    
    // See https://en.sfml-dev.org/forums/index.php?topic=20033.msg144271#msg144271 for explanation of following lines
    DEFAULT_WINDOW.setFramerateLimit(0);
    DEFAULT_WINDOW.setVerticalSyncEnabled(true);
    
    
    /* Identify the resource directory */
    std::string resourceDir = "resources/";
    
    
    /* Create other textures */
    sf::Texture monsterTexture;
    sf::Texture playerTexture;
    sf::Texture playerAttack;
    sf::Texture playerBlock;
    sf::Texture playerHit;
    sf::Texture playerWalk;
    sf::Texture playerStand;
    sf::Texture playerFightStance;
    sf::Texture playerWakeUp;
    sf::Texture playerDie;
    sf::Texture monsterAttack;
    sf::Texture monsterStanding;
    sf::Texture monsterHit;
    sf::Texture monsterDie;
    if (!monsterStanding.loadFromFile(resourceDir + "spritesheets/monster_standing.jpg"))
    {
        return -1;
    }
    if (!playerStand.loadFromFile(resourceDir + "spritesheets/stand.jpeg"))
    {
        return -1;
    }
    if (!playerWalk.loadFromFile(resourceDir + "spritesheets/walk.png"))
    {
        return -1;
    }
    if (!playerHit.loadFromFile(resourceDir + "spritesheets/hit.png"))
    {
        return -1;
    }
    if (!playerAttack.loadFromFile(resourceDir + "spritesheets/sword_attack.jpeg"))
    {
        return -1;
    }
    if (!playerFightStance.loadFromFile(resourceDir + "spritesheets/fight_stance.png"))
    {
        return -1;
    }
    if (!playerWakeUp.loadFromFile(resourceDir + "spritesheets/wake_up.png"))
    {
        return -1;
    }
    if (!playerDie.loadFromFile(resourceDir + "spritesheets/die.jpg"))
    {
        return -1;
    }
    if (!playerBlock.loadFromFile(resourceDir + "spritesheets/block.png"))
    {
        return -1;
    }
    if (!monsterAttack.loadFromFile(resourceDir + "spritesheets/monster_attack.png"))
    {
        return -1;
    }
    if (!monsterDie.loadFromFile(resourceDir + "spritesheets/monster_die.png"))
    {
        return -1;
    }
    if (!monsterHit.loadFromFile(resourceDir + "spritesheets/monster_hit.png"))
    {
        return -1;
    }
    
    monsterTexture.setSmooth(true);
    playerTexture.setSmooth(true);
    
    /* Instantiate Player */
    Player player;
    player.addAnimation(playerStand, 6,3);
    player.setAnimation();
    //h.getActiveRoom()->getEncounter()->setPosition((window.getSize().x)/2, (window.getSize().y)/4);
    player.setPosition(DEFAULT_WINDOW.getSize().x/20,DEFAULT_WINDOW.getSize().y/4);
    
    
    
    
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
    
    mainMenu.addButton("Play [P]", testGameScreen, sf::Keyboard::P);
    mainMenu.addButton("Settings [S]", testMenu1, sf::Keyboard::S);
    mainMenu.addButton("Quit [W]", 0, sf::Keyboard::W);
    
    testGameScreen.addButton("Hiii", 0);
    testGameScreen.addButton("Main Menu [M]", 0, sf::Keyboard::M);
    
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
    
    
    
    
    
    /* Create the debugging text tracking the current hall */
    sf::Text hallText;
    hallText.setFont(DEFAULT_FONT);
    hallText.setCharacterSize(20);
    hallText.setFillColor(sf::Color::Black);
    hallText.setPosition(0, 400);
    
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
                    if (event.key.code == sf::Keyboard::A) {
                        //testGameScreen.buttons.first->data.setTitle("On");
                        testGameScreen.buttons.first->data.activate();
                    }
                    if (event.key.code == sf::Keyboard::D) {
                        //testGameScreen.buttons.first->data.setTitle("Off");
                        testGameScreen.buttons.first->data.deactivate();
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
            
            /* Draw the top of the stack (and the previous screen if necessary) */
            if (!listOfScreens.isEmpty()) {
                if (listOfScreens.top->hasNext() && listOfScreens.top->data.showPrevious) {
                    DEFAULT_WINDOW.draw(listOfScreens.top->next->data);
                }
                DEFAULT_WINDOW.draw(listOfScreens.top->data);
            }
        } else {
            quitGame();
        }
        
        /* Draw the paper texture (for aesthetics) and the debugging text (for help) */
        DEFAULT_WINDOW.draw(paper);
        //window.draw(hallText);
        
        /* Display the screen */
        DEFAULT_WINDOW.display();
    }
    
    return EXIT_SUCCESS;
}
