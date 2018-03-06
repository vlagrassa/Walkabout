#include "Ambience.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>




Ambience::Ambience(std::string resources) {
     if (!skyTexture.loadFromFile(resources + "sky.png"))
    {
         std::cout << "Failed to load image sky.png from directory " << resources << "\n";
    }
    if (!horizonBgTexture.loadFromFile(resources + "horizon_background.png"))
    {
        std::cout << "Failed to load image horizon_background.png from directory " << resources << "\n";
    }
    if (!imBgTexture.loadFromFile(resources + "immidiate_background.png"))
    {
        std::cout << "Failed to load image immidiate_background.png from directory " << resources << "\n";
    }
    if (!groundTexture.loadFromFile(resources + "ground_outside.png"))
    {
        std::cout << "Failed to load image ground_outside.png from directory " << resources << "\n";
    }
     
    if (!monsterStanding.loadFromFile(resources + "spritesheets/monster_standing.png"))
    {
        std::cout<< "\n" << "monster standing error" << "\n";
    }
     std::cout<<"\n pow pow";
//     if (!monsterAttack.loadFromFile(resources + "spritesheets/monster_attack.png"))
//    {
//        std::cout<< "\n" << "monster attack error" << "\n";
//    }
//    if (!monsterDie.loadFromFile(resources + "spritesheets/monster_die.jpg"))
//    {
//        std::cout<< "\n monster die error \n";
//    }
//    if (!monsterHit.loadFromFile(resources + "spritesheets/monster_hit.png"))
//    {
//       std::cout<< "\n monster hit error \n";
//    }
     initTextures();
}

Ambience::Ambience(sf::Texture& sky, sf::Texture& horizon, sf::Texture& immediate, sf::Texture& ground) {
    skyTexture = sky;
    horizonBgTexture = horizon;
    imBgTexture = immediate;
    groundTexture = ground;
    
    initTextures();
}

Ambience::Ambience( const Ambience& orig){
    
}

Ambience::~Ambience(){
    
}

sf::Texture* Ambience::getSky(){
    return &skyTexture;
}

sf::Texture* Ambience::getHorizonBg(){
    return &horizonBgTexture;
}

sf::Texture* Ambience::getImBg(){
    return &imBgTexture;
}

sf::Texture* Ambience::getGround(){
    return &groundTexture;
}

//sf::Texture& Ambience::getMonsterAttack() {
//    return monsterAttack;
//}
//
//sf::Texture& Ambience::getMonsterDie() {
//    return monsterDie;
//}
//
//sf::Texture& Ambience::getMonsterHit() {
//    return monsterHit;
//}
//
//sf::Texture& Ambience::getMonsterStanding() {
//    return monsterStanding;
//}

void Ambience::initTextures() {
    skyTexture.setRepeated(true);
    horizonBgTexture.setRepeated(true);
    imBgTexture.setRepeated(true);
    groundTexture.setRepeated(true);
}


