#ifndef HALL_H
#define HALL_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Room.hpp"
#include "../player/Player.hpp"


class Hall : private std::vector<Room*>, public sf::Drawable {
public:
    /* Constructor */
    Hall(Player& p, unsigned int s = genRandomSeed());
    
    /* Default constructor */
    Hall(const Hall& orig);
    
    /* Default destructor */
    virtual ~Hall();
    
    /* Getter methods */
    unsigned int getActiveIndex() const;
    unsigned int getSeed() const;
    Room* getRoom(unsigned int index) const;
    Room* getActiveRoom() const;
    const Player& getPlayer() const;
    
    /* Update playerIndex and corresponding Rooms */
    void setActiveRoom(unsigned int index);
    void setActiveRoom();
    
    void setPlayerT(int n);
    
    /* Add a room to the Hall */
    void addRoom(Room* r);
    void addRoom();
    
    /* Get x position for number of steps into given Room (absolute) */
    unsigned int goToRoom(unsigned int index, unsigned int steps);
    unsigned int goToRoom(unsigned int index);

    /* Get x position for number of steps into given Room (relative) */
    unsigned int stepRoom(unsigned int index, unsigned int steps);
    unsigned int stepRoom(unsigned int index);
    
    void recalcLength();
    void printDistances() const;
    
    /* Recalculate values based on other conditions */
    void updateIndex(Player& p);
    
    /* Get vector of the Rooms with space within the window's borders */
    vector<Room*> getOnscreenRooms(sf::RenderTarget& w) const;
    
    /* Get vector of Rooms within a certain range of indeces */
    std::vector<Room*> getRange(unsigned int start, unsigned int end) const;
    
    using vector<Room*>::begin;
    using vector<Room*>::end;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
private:
    /* Index of the current active Room */
    unsigned int activeIndex;
    
    /* The seed to generate new Rooms */
    const unsigned int seed;
    
    /* The sum of all the room lengths */
    int totalLength;
    
    /* Pointer to the Player object */
    const Player& player;
    
    /* Generate seed based on the current time */
    static unsigned int genRandomSeed();
    
    /* Return Hall for a stream */
    friend std::ostream& operator<<(std::ostream &strm, const Hall&);
};

template<class T> class activeVector : public std::vector<T> {
public:
    activeVector() {
        activeIndex = 0;
    }
    activeVector(const activeVector& orig) {
        activeIndex = 0;
    }
    virtual ~activeVector() {
        
    }
    
    T getActive() const {
        try {
            return this->at(activeIndex);
        } catch (std::out_of_range e) {
            return T();
        }
    }
    int getActiveIndex() const {
        return activeIndex;
    }
    void setActiveIndex(unsigned int n) {
        activeIndex = n;
    }
    
private:
    unsigned int activeIndex;
};

#endif /* HALL_H */
