#ifndef HALL_H
#define HALL_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Room.hpp"
#include "../player/Player.hpp"

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
    unsigned int getActiveIndex() const {
        return activeIndex;
    }
    void setActiveIndex(unsigned int n) {
        activeIndex = n;
    }
    
private:
    unsigned int activeIndex;
};


class Hall : private activeVector<Room*>, public sf::Drawable {
public:
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Base constructor method. Initializes:
     *   -activeIndex
     *   -seed
     *   -totalLength
     *   -player
     * 
     * If seed is not specified, it defaults to a random value.
     * 
     * @param p The Player object - saved to player
     * @param s The seed for the Hall - saved to seed
     */
    Hall(const Player& p, unsigned int s = genRandomSeed());
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default constructor method. Copies player and seed fields
     * from original Hall.
     * 
     * @TODO How should this preserve player?
     * 
     * @param Original Hall
     */
    Hall(const Hall& orig);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default destructor method. Deletes:
     *   -(nothing)
     */
    virtual ~Hall();
    
    /* Getter methods */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the seed of the Hall.
     * 
     * @return The seed of the Hall
     */
    unsigned int getSeed() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the Room at a given index.
     * 
     * @param index The index 
     * 
     * @return The Room at that index
     */
    Room* getRoom(unsigned int index) const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the Player of the Hall.
     * 
     * @return The player
     */
    const Player& getPlayer() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get a vector of Rooms within a certain range.
     * 
     * @param start The start index
     * 
     * @param end The end index
     * 
     * @return Vector of Rooms
     */
    std::vector<Room*> getRange(unsigned int start, unsigned int end) const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get a vector of the Rooms within the given window borders.
     * Use this to draw only the relevant Rooms when rendering
     * the Hall.
     * 
     * @param w The RenderTarget the Rooms are on.
     * 
     * @return Vector of Rooms
     */
    vector<Room*> getOnscreenRooms(sf::RenderTarget& w) const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Changes the active Room to the specified index. Involves
     * deactivating the previous Room and activating the new one.
     * 
     * @param index The index of the new Room to make active
     */
    void setActiveRoom(unsigned int index);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Activate the Room currently referenced by activeIndex.
     * Equivalent to:
     * 
     *     at(activeIndex)->activate();
     */
    void setActiveRoom();
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Set the value of playerX for the active Room. Note that
     * this is relative to the Room, and thus is distinct from
     * the player's x coordinate. Equivalent to:
     * 
     *     getActiveRoom()->setPlayerX(n);
     * 
     * @param n The value to set playerX to
     */
    void setActiveRoomPlayerX(int n);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Add a specific Room to the Hall. Note that this should be
     * used in place of vector::push_back().
     * 
     * @param r The Room to add
     */
    void addRoom(Room* r);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Add a random Room to the Hall, generated from the Hall's
     * seed variable.
     */
    void addRoom();
    
    /* Get x position for number of steps into given Room (absolute) */
    unsigned int goToRoom(unsigned int index, unsigned int steps);
    unsigned int goToRoom(unsigned int index);

    /* Get x position for number of steps into given Room (relative) */
    unsigned int stepRoom(unsigned int index, unsigned int steps);
    unsigned int stepRoom(unsigned int index);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Print a visual representation of the Hall, like such:
     * 
     *                  _ _ o _ X | _ _ _ X
     * 
     * ...where:
     * 
     *   _ is a blank space
     *   o is the Player
     *   X is an Encounterable
     *   | divides Rooms
     * 
     * Note that Rooms will not actually be separated, the way |
     * might suggest.
     */
    void printDistances() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Recalculate values based on other conditions
     */
    void updateIndex(Player& p);
    
    /* Recalculate the totalLength variable - shouldn't have to use at any point */
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Recalculate the totalLength variable in case of a change 
     * in the Rooms. Not necessary after calling AddRoom(). Note
     * that in normal operation, this shouldn't have to be used.
     * It currently a backup mechanism.
     */
    void recalcLength();
    
    
    using vector<Room*>::begin;
    using vector<Room*>::end;
    
    using activeVector<Room*>::getActive;
    using activeVector<Room*>::getActiveIndex;
    using activeVector<Room*>::setActiveIndex;
    
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

#endif /* HALL_H */
