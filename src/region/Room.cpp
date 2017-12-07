#include "Room.hpp"
#include "Monster.hpp"
#include "Treasure.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// <editor-fold defaultstate="collapsed" desc=" Con/Destructors ">

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
Room::Room(unsigned int size, Encounterable* enc) : encounter(enc), length(size), playerX(-1), active(false) {}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Constructor method. Generates a random Room from a passed
 * integer (as a seed).
 * 
 * @param seed The seed for the Room
 */
Room::Room(unsigned int seed) : Room((seed%15)+2, genRandomEncounterable(seed)) {}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Default constructor method. Currently preserves length of
 * the original Room only.
 * 
 * @param Original Room
 */
Room::Room(const Room& orig) : length(orig.getLength()) {}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Default destructor method. Deletes:
 *   -(nothing)
 */
Room::~Room() {}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Getters ">

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Get the length of the Room.
 * 
 * @return Size of Room
 */
unsigned int Room::getLength() const {
    return length;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Get the distance between the Player and the Encounterable.
 * 
 * @return Distance
 */
unsigned int getDistance() {
    return 0; //Temporary default value
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Get RoomType enumerator value representing the subclass
 * of Encounterable held in the Room.
 * 
 * @return Type of Encounterable in Room
 */
RoomType Room::getType() const {
    return encounter->getType();
}

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
int Room::getPlayerX() const {
    return playerX;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Get the Encounterable of the Room.
 * 
 * @return The Room's Encounterable
 */
Encounterable* Room::getEncounter() const {
    return encounter;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Get EncounterScreen subclass from the Encounterable held
 * in the Room.
 * 
 * @return EncounterScreen of Encounterable
 */
EncounterScreen* Room::getScreen() const {
    return getEncounter()->getEncounterScreen();
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Setters ">

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
void Room::setPlayerX(int n) {
    playerX = n;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Methods for variable `active` ">

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
bool Room::isActive() const {
    return active;
}

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
void Room::setActive(const bool& b, int n) {
    active = b;
    if (b) {
        if (playerX == -1) {
            playerX = n;
        }
    } else {
        playerX = -1;
    }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Set active boolean value to false. This means the Player
 * is not within this Room.  Equivalent to:
 * 
 *   setActive(true);
 * 
 * See setActive() for more details.
 */
void Room::activate() {
    setActive(true);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Set active boolean value to false. This means the Player
 * is not within this Room.  Equivalent to:
 * 
 *   setActive(false);
 * 
 * See setActive() for more details.
 */
void Room::deactivate() {
    setActive(false);
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Private Methods ">

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Private method to generate a random Encounterable object.
 * Utilized in the constructor.
 * 
 * @return Random Encounterable
 */
Encounterable* Room::genRandomEncounterable(unsigned int seed) {
    RoomType temp = static_cast<RoomType>(seed % 2);
    if (temp == monster) {
        return new Monster(dinosaur);
    }
    if (temp == treasure) {
        return new Treasure();
    }
    std::cout << "Something went wrong in Room::genRandomEncounterable\n";
    return NULL;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Friend Methods ">

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Friend method to return Room for an output stream. Mostly
 * for printing the Room.
 * 
 * @return Room for a stream
 */
std::ostream& operator<<(std::ostream &strm, const Room &r) {
    if (r.isActive()) {
        strm << "*  ACTIVE ";
    } else {
        strm << " Inactive ";
    }
    strm << "size " << std::to_string(r.getLength()) << " " << r.getEncounter()->getTypeName() << " at tic " << r.getPlayerX();
    return strm;
}

// </editor-fold>
