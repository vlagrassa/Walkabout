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
#include "SaveData.hpp"
#include "screen/GameScreen.hpp"


int main() {
    std::cout << "\n\n=-=-= This is the start of Main =-=-=\n\n";
    std::string resourceDir = "resources/";
    
    /* Create Window */
    sf::RenderWindow window(sf::VideoMode(800, 600), "Walkabout");
    window.setFramerateLimit(0); // Fixes stuff, see https://en.sfml-dev.org/forums/index.php?topic=20033.msg144271#msg144271
    window.setVerticalSyncEnabled(true); // This line too
    
    /* Instantiate Items*/
        //Head
    Item boringHat(Head,"Boring Hat",{0,1,0});
    Item thinkingCap(Head,"Thinking Cap", {0,2,0});
    Item telepatheticHat(Head,"Telepathetic Hat",{0,3,0});
    Item cardboardBox(Head,"Cardboard Box",{0,1,1});
    Item bucketwithHoles(Head,"Bucket with Holes",{2,0,0});
    Item duck(Head,"Duck",{1,0,1});
    //Item a(a,"",{,,});
        //Staff
    Item stick(Staff,"Stick",{0,0,1});
    Item bigStick(Staff,"Big Stick",{0,0,2});
    Item stickyStick(Staff,"Sticky Stick",{0,0,3});
    Item dowsingStick(Staff,"Dowsing Stick",{0,0,4});
    Item boringStaff(Staff,"Boring Staff",{0,1,4});
        //Potions
    Item awesomeSauce(Potion,"Awesome Sauce",{0,0,2});
    Item coffee(Potion,"Coffee",{0,2,0});
    Item otherPeoplesBlood(Potion,"Other Peoples Blood",{0,0,0});
    Item secretSauce(Potion,"Secret Sauce",{1,0,3});
    Item strenghPotion(Potion,"Strength Potion",{4,0,0});
        //Chest
    Item lotsOfShirts(Chest,"Lots of Shirts",{1,0,0});
    Item dinnerPlate(Chest,"Dinner Plate",{2,0,0});
    Item tinFoil(Chest,"Tin Foil",{1,0,1});
    Item shoulderPads(Chest,"Shoulder Pads",{2,0,1});
    Item bathrobe(Chest,"Bathrobe",{0,0,4});
    //Item a(a,"",{,,});
    //Item a(a,"",{,,});
    //Item a(a,"",{,,});
    //Item a(a,"",{,,});
    //Item a(a,"",{,,});
    //Item a(a,"",{,,});
    
    
    
    Item testItem(Bow, "testBow", {1,1,1});
    
    /* Instantiate Player */
    Player player;
    
    
    /* Create Ambience (like a texture pack) and Background */
    Ambience standard(resourceDir);
    Background background(standard, window);
    
    
    /* Initialize ScreenMode Stack */
    Stack<ScreenMode&> listOfScreens;
    GameScreen testGameScreen(window, player, background);
    listOfScreens.push(testGameScreen);
    
    
    /* Instantiate TextFiling*/
    SaveData savefile;
    
    
    
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
                case (sf::Event::KeyPressed):
                    if (event.key.code == sf::Keyboard::Q) {
                        if (listOfScreens.top->hasNext()) listOfScreens.pop();
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
        temp += testGameScreen.hall.operator std::string();
        hallText.setString(temp);

        std::string hi;

        /* Clear the screen */
        window.clear(sf::Color::White);
        
        /* Figure out the active screen */
        if (!listOfScreens.isEmpty()) {
            ScreenMode* nextScreen = listOfScreens.top->data.run(event);
            if (nextScreen == 0) {
                listOfScreens.pop();
                std::cout << "Removed screen:\n" << listOfScreens << "\n";
            } else if (nextScreen != &listOfScreens.top->data) {
                listOfScreens.push(*nextScreen);
                std::cout << "Added screen:\n" << listOfScreens << "\n";
            }
            window.draw(*nextScreen);
        }

        /* Draw all the other things */
        window.draw(paper);
        window.draw(hallText);
        
        /* Display the screen */
        window.display();
    }
    
    return EXIT_SUCCESS;
}
