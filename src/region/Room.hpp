#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Encounterable.hpp"

class Room {
public:
    /* Con/Destructors */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Constructor method. Initializes:
     *   -encounter
     *   -length
     *   -playerX
     *   -active
     * 
     * @param size The size of the Room
     * @param enc The Encounterable held in the Room
     */
    Room(unsigned int size, Encounterable* enc);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Constructor method. Generates a random Room from a passed
     * integer (as a seed).
     * 
     * @param seed The seed for the Room
     */
    Room(unsigned int seed);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default constructor method. Currently preserves length of
     * the original Room only.
     * 
     * @param Original Room
     */
    Room(const Room& orig);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default destructor method. Deletes:
     *   -(nothing)
     */
    virtual ~Room();
    
    
    /* Getter methods */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the length of the Room.
     * 
     * @return Size of Room
     */
    unsigned int getLength() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the distance between the Player and the Encounterable.
     * 
     * @return Distance
     */
    //@TODO Implement this method
    unsigned int getDistance() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get RoomType enumerator value representing the subclass
     * of Encounterable held in the Room.
     * 
     * @return Type of Encounterable in Room
     */
    RoomType getType() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the x position of the Player within the Room.
     * 
     * Note that this is distinct from the Player's own x value,
     * which is within the Hall as a whole - this is relative to
     * the Room.
     * 
     * @return Player's x coordinate within Room
     */
    int getPlayerX() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the Encounterable of the Room.
     * 
     * @return The Room's Encounterable
     */
    Encounterable* getEncounter() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get EncounterScreen subclass from the Encounterable held
     * in the Room.
     * 
     * @return EncounterScreen of Encounterable
     */
    EncounterScreen* getScreen() const;
    
    
    /* Setter methods */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Sets the x position of the Player within the Room.
     * 
     * Note that this is distinct from the Player's own x value,
     * which is within the Hall as a whole - this is relative to
     * the Room.
     * 
     * @param New Player x coordinate within Room
     */
    void setPlayerX(int n);
    
    
    /* Methods for variable `active` */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Tells whether the Player is in the current Room, based on
     * its x coordinate. This is set by Hall:
     * 
     *   -True: Player is within this Room
     *   -False: Player is in another Room
     * 
     * @return Whether Player is in this Room
     */
    bool isActive() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Sets the Room's active value.
     * 
     * The second parameter is optional, and defaults to 0. If a
     * value is given, the Player's x coordinate within the Room
     * will be set to this value IF the coordinate is currently
     * -1, the default value for a non-active Room. This ensures
     * calling active on an already-active room won't affect the
     * Player's position. When deactivated, the x coordinate is
     * set to -1 by default.
     * 
     * @param b The boolean value to set active to
     * 
     * @param n The x coordinate to send Player to
     */
    void setActive(const bool& b, int n = 0);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Set active boolean value to true. This means the Player
     * is not within this Room.  Equivalent to:
     * 
     *   setActive(true);
     * 
     * See setActive() for more details.
     */
    void activate();
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Set active boolean value to false. This means the Player
     * is not within this Room.  Equivalent to:
     * 
     *   setActive(false);
     * 
     * See setActive() for more details.
     */
    void deactivate();
    
private:
    /* Encounterable held by the Room */
    Encounterable* encounter;
    
    /* Number of tics in the Room */
    const unsigned int length;
    
    /* Position (in tics) of player within Room - only used if Active */
    int playerX;
    
    /* Whether the Room is the current active room of its Hall */
    bool active;
    
    /* Whether the Room has been "defeated" or not */
    bool passed;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Private method to generate a random Encounterable object.
     * Utilized in the constructor.
     * 
     * @return Random Encounterable
     */
    static Encounterable* genRandomEncounterable(unsigned int seed);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Friend method to return Room for an output stream. Mostly
     * for printing the Room.
     * 
     * @return Room for a stream
     */
    friend std::ostream& operator<<(std::ostream &strm, const Room&);
    
};

#endif /* ROOM_H */
