#ifndef AMBIENCE_H
#define AMBIENCE_H

#include <SFML/Graphics.hpp>
#include <stdlib.h> 
#include <iostream>

//void setSpriteSheet(const sf::Texture& spriteSheet, int rowNum, int colNum);

class Ambience {
public:
    Ambience(std::string resources);
    Ambience(sf::Texture& sky, sf::Texture& horizon, sf::Texture& immediate, sf::Texture& ground);
    Ambience(const Ambience& orig);
    virtual ~Ambience();
    sf::Texture* getSky();
    sf::Texture* getHorizonBg();
    sf::Texture* getImBg();
    sf::Texture* getGround();
    sf::Texture* getMonsterAttack();
    sf::Texture* getMonsterDie();
    sf::Texture* getMonsterHit();
    sf::Texture* getMonsterStanding();
    
    //sf::Animation monster1; //create array of frames for monster
    
        
private:
    sf::Texture skyTexture;
    sf::Texture horizonBgTexture;
    sf::Texture imBgTexture;
    sf::Texture groundTexture;
    
    sf::Texture monsterAttack;
    sf::Texture monsterStanding;
    sf::Texture monsterHit;
    sf::Texture monsterDie;

    

    void initTextures();
};

#endif /* AMBIENCE_H */
