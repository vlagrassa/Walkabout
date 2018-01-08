#ifndef HALL_H
#define HALL_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Room.hpp"
#include "../player/Player.hpp"
#include "../utils/Utils.hpp"

class Hall : private ActiveVector<Room*>, public sf::Drawable {
public:
    /* Con/Destructors */
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Base constructor method. Initializes:
     *   -seed
     *   -totalLength
     *   -player
     * 
     * If seed is not specified, it defaults to a random value.
     * 
     * @param p The Player object - saved to player
     * @param s The seed for the Hall - saved to seed
     */
    Hall(Player& p, unsigned int s = genRandomSeed());
    
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
     * Get x position for the number of steps into the Room at a
     * given index. For example...
     * 
     *   getRoomPos(1, 1);
     * 
     * ...returns the absolute x coordinate for 1 step into the
     * the Room at index 1. Note that indexing starts from 0. If
     * the steps parameter is not given, it defaults to 0.
     * 
     * Note that if `steps` exceeds the length of the given Room,
     * an error is not currently thrown. The method will instead
     * perform the math as though the Room were that long. This
     * may need to be changed.
     * 
     * @param index The index of the Room
     * 
     * @param steps The number of steps into the Room (default 0)
     */
    unsigned int getRoomPos(unsigned int index, unsigned int steps = 0);
    
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
    vector<Room*> getOnscreenRooms() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the Player of the Hall.
     * 
     * @return The player
     */
    Player& getPlayer() const;
    
    
    /* Setter methods */
    
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
    void setActiveRoomPlayerX(unsigned int n);
    
    
    /* Adder methods */
    
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
    
    
    /* Graphics methods */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Inherited method from sf::Drawable to draw the Hall to a
     * RenderTarget.
     * 
     * @param target The target to draw the Hall to
     * 
     * @param states Not used, but necessary for SFML
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    
    /* Print methods */
    
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
    std::string printDistances() const;
    
    
    /* Recalc and Update methods */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Recalculate the totalLength variable in case of a change 
     * in the Rooms. Not necessary after calling AddRoom(). Note
     * that in normal operation, this shouldn't have to be used.
     * It currently a backup mechanism.
     */
    void recalcLength();
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Sets a new active Room and Player x coordinate within it
     * based on the given Player's x coordinate. Probably won't
     * be used for the main program, more a way to sync the Hall
     * to the Player in fringe cases. As in, this is just backup
     * that you shouldn't use unless you have to. Note that this
     * will deactivate the current Room, which erases the Player
     * position in it by default (see Room::setActive()).
     * 
     * Accepts a Player parameter, since it is meant for fringe
     * cases. Use the version with no parameter for the Hall's
     * Player reference.
     * 
     * @param p The player to sync the Hall to
     */
    void updateIndex(const Player& p);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Sets a new active Room and Player x coordinate within it
     * based on the given Player's x coordinate. Probably won't
     * be used for the main program, more a way to sync the Hall
     * to the Player in fringe cases. As in, this is just backup
     * that you shouldn't use unless you have to. Note that this
     * will deactivate the current Room, which erases the Player
     * position in it by default (see Room::setActive()).
     * 
     * Syncs to the Hall's Player reference. Equivalent to:
     * 
     *   updateIndex(getPlayer());
     */
    void updateIndex();
    
    void updateRoomPositions();
    
    
    /* Inherited methods (using) */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Inherited method from vector<Room*> for iterating through
     * the Hall. Probably won't be explicitly called anywhere.
     */
    using vector<Room*>::begin;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Inherited method from vector<Room*> for iterating through
     * the Hall. Probably won't be explicitly called anywhere.
     */
    using vector<Room*>::end;
    
    using ActiveVector<Room*>::getActive;
    using ActiveVector<Room*>::getActiveIndex;
    using ActiveVector<Room*>::setActiveIndex;
    
    operator std::string() const {
        std::string temp;
        temp += "Hall: Room ";
        temp += std::to_string(this->getActiveIndex());
        temp += "\n";
        for (Room* r : this->getOnscreenRooms()) {
            temp += "  ";
            temp += *r;
            temp += "\n";
        }
        temp += this->printDistances();
        temp += "\nDisplaying Rooms ";
        temp += std::to_string((static_cast<int>(getActiveIndex()-1) < 0) ? 0 : getActiveIndex()-1);
        temp += " through ";
        temp += std::to_string(std::min(static_cast<unsigned int>(size()), getActiveIndex()+2));
        temp += ".\n";
        getRange(std::min(static_cast<unsigned>(0), getActiveIndex()-1), std::min(static_cast<unsigned int>(size()), getActiveIndex()+2));
        return temp;
    };
    
private:
    /* The seed to generate new Rooms */
    const unsigned int seed;
    
    /* The sum of all the room lengths */
    int totalLength;
    
    /* Pointer to the Player object */
    Player& player;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Private method to generate a random seed based on current
     * system time. Utilized in the constructor. Equivalent to:
     * 
     *   return std::time(NULL);
     * 
     * @return Random seed
     */
    static unsigned int genRandomSeed();
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Friend method to return Hall for an output stream. Mostly
     * for printing the Hall.
     * 
     * @return Hall for a stream
     */
    friend std::ostream& operator<<(std::ostream &strm, const Hall&);
};

#endif /* HALL_H */
