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
    
    
    Player player;
    Hall h(&player);
    int numRooms = 4;
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
    
    
    /*Background thingys*/
    
    sf::Texture skyTexture;
    sf::Texture horizonBgTexture;
    sf::Texture imBgTexture;
    sf::Texture groundTexture;
    sf::Texture paperTexture;
    
    /*Load texture files*/
//    skyTexture.loadFromFile("resources/sky.png");
//    horizonBgTexture.loadFromFile("resources/horizon_background.png");
//    imBgTexture.loadFromFile("resources/immidiate_background.png");
//    groundTexture.loadFromFile("resources/ground_outside.png");
    
    if (!skyTexture.loadFromFile("resources/sky.png"))
    {
        return -1;
    }
    if (!horizonBgTexture.loadFromFile("resources/horizon_background.png"))
    {
        return -1;
    }
    if (!imBgTexture.loadFromFile("resources/immidiate_background.png"))
    {
        return -1;
    }
    if (!groundTexture.loadFromFile("resources/ground_outside.png"))
    {
        return -1;
    }
    if (!paperTexture.loadFromFile("resources/paper_texture_yellow.png"))
    {
        return -1;
    }
    
    
    /*set textures to repeat*/
    skyTexture.setRepeated(true);
    horizonBgTexture.setRepeated(true);
    imBgTexture.setRepeated(true);
    groundTexture.setRepeated(true);
    
    sf::Sprite sky;
    sf::Sprite horizonBg;
    sf::Sprite imBg;
    sf::Sprite ground;
    sf::Sprite paper;
    
    
//    /*set sizes for background objects*/
    sky.scale(1, 1);
    horizonBg.scale(1,.9);
    imBg.scale(1, .8);
    ground.setScale(1, .35);
//    
    
    skyTexture.setRepeated(true);
    horizonBgTexture.setRepeated(true);
    imBgTexture.setRepeated(true);
    groundTexture.setRepeated(true);
    
    /*put textures into background rect objects*/
    sky.setTexture(skyTexture);
    horizonBg.setTexture(horizonBgTexture);
    imBg.setTexture(imBgTexture);
    ground.setTexture(groundTexture);
    paper.setTexture(paperTexture);
    
    horizonBg.setTextureRect({ 0, 0, static_cast<int>(window.getSize().x*10), static_cast<int>(horizonBgTexture.getSize().y) });
    imBg.setTextureRect({ 0, 0, static_cast<int>(window.getSize().x*2), static_cast<int>(window.getSize().y*3/5)});
    horizonBg.setTextureRect({ 0, 0, static_cast<int>(window.getSize().x), static_cast<int>(horizonBgTexture.getSize().y) });
    
    
    sky.setPosition(0,0);
    horizonBg.setPosition(0,window.getSize().y*3/16);
    imBg.setPosition(0,window.getSize().y*3/16+15);
    ground.setPosition(0,window.getSize().y*10/16+15);
    
    
    
    //sf::Event event;
    

    sf::Texture monsterTexture;
    sf::Texture playerTexture;
    if (!monsterTexture.loadFromFile("resources/monster.png"))
    {
        return -1;
    }
    if (!playerTexture.loadFromFile("resources/player.png"))
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
    
