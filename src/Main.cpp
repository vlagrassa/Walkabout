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
    std::cout << "\n\n=-=-= This is the start of Main =-=-=\n\n";
    
    std::string resourceDir = "resources/";
    
    
    Player player;
    Hall h(&player);
    unsigned int numRooms = 4;
    for (unsigned i = 0; i < numRooms; i++) {
        h.addRoom();
    }
    
    
    std::cout << h << "\n";
    
    //player.stepRight();
    //h.updateIndex(player);
    std::cout << h << "\n";
    
    std::cout << "Using Hall as vector subclass:\n";
    
    for (Room* r : h) {
        std::cout << *r << "\n";
    }
    
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Walkabout");
    
    std::vector<sf::Texture> backgroundTextures;
    
    /*Background thingys*/
    
    sf::Texture skyTexture;
    sf::Texture horizonBgTexture;
    sf::Texture imBgTexture;
    sf::Texture groundTexture;
    sf::Texture paperTexture;
    
    backgroundTextures.push_back(skyTexture);
    backgroundTextures.push_back(horizonBgTexture);
    backgroundTextures.push_back(imBgTexture);
    backgroundTextures.push_back(groundTexture);
    backgroundTextures.push_back(paperTexture);
    
    if (!skyTexture.loadFromFile(resourceDir + "sky.png"))
    {
        return -1;
    }
    if (!horizonBgTexture.loadFromFile(resourceDir + "horizon_background.png"))
    {
        return -1;
    }
    if (!imBgTexture.loadFromFile(resourceDir + "immidiate_background.png"))
    {
        return -1;
    }
    if (!groundTexture.loadFromFile(resourceDir + "ground_outside.png"))
    {
        return -1;
    }
    if (!paperTexture.loadFromFile(resourceDir + "paper_texture_yellow.png"))
    {
        return -1;
    }
    
    
    /*set textures to repeat*/
//    skyTexture.setRepeated(true);
//    horizonBgTexture.setRepeated(true);
//    imBgTexture.setRepeated(true);
//    groundTexture.setRepeated(true);
    
    for (sf::Texture t : backgroundTextures) {
        t.setRepeated(true);
    }
    
    sf::Sprite sky;
    sf::Sprite horizonBg;
    sf::Sprite imBg;
    sf::Sprite ground;
    sf::Sprite paper;
    
    
    
//    /*set sizes for background objects*/
    sky.scale(1, 1);
    horizonBg.scale(1,1);
    imBg.scale(1, .8);
    ground.setScale(1, .35);
//    
    
    //skyTexture.setRepeated(true);
    //horizonBgTexture.setRepeated(true);
    //imBgTexture.setRepeated(true);
    //groundTexture.setRepeated(true);
    
    /*put textures into background rect objects*/
    sky.setTexture(skyTexture);
    horizonBg.setTexture(horizonBgTexture);
    imBg.setTexture(imBgTexture);
    ground.setTexture(groundTexture);
    paper.setTexture(paperTexture);
    
    sky.setPosition(0,0);
    horizonBg.setPosition(0,window.getSize().y*3/16);
    imBg.setPosition(0,window.getSize().y*3/16+15);
    ground.setPosition(0,window.getSize().y*10/16+15);
    
    
    
    //sf::Event event;
    

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
    //sf::Sprite sprite;
    //sprite.setTexture(texture);
    h.getActiveRoom()->getEncounter()->setTexture(monsterTexture);
    player.setTexture(playerTexture);
    h.getActiveRoom()->getEncounter()->setPosition((window.getSize().x)/2, (window.getSize().y)/2);
    
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
                    horizonBg.move(player.stepSize/2,0);
                    imBg.move(player.stepSize,0);
                    ground.move(player.stepSize,0);
                } 
                if (event.key.code == sf::Keyboard::Right)
                {
                    horizonBg.move(-player.stepSize/2,0);
                    imBg.move(-player.stepSize,0);
                    ground.move(-player.stepSize,0);
                } 
            }
        }
        
        std::string hi;
        window.clear(sf::Color::White);
        
        
        /*background*/
        window.draw(sky);
        window.draw(horizonBg);
        window.draw(imBg);
        window.draw(ground);
        
        window.draw(*h.getActiveRoom()->getEncounter());
        
        window.draw(player);
        window.draw(paper);
        window.display();
    }
    

    return EXIT_SUCCESS;
}



//void moving(float step, sf::RectangleShape& horizonBg, sf::RectangleShape& imBg, sf::RectangleShape& ground ){
//    //sky.move(step,0);
    
