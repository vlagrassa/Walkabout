#ifndef GAMEINFO_H
#define GAMEINFO_H

class Player;
class Ambience;

struct GameInfo {
    Player& player;
    sf::RenderWindow& window;
    sf::Clock& gameclock;
    Ambience& ambience;
};

#endif /* GAMEINFO_H */