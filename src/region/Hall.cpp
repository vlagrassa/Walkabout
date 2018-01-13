#include "Hall.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "../player/Player.hpp"

// <editor-fold defaultstate="collapsed" desc=" Con/Destructors ">

/* Constructor - takes optional argument s */
Hall::Hall(Player& p, sf::Window& window, unsigned int s) : window(window), seed(s), totalLength(0), player(p) {}

/* Default constructor */
Hall::Hall(const Hall& orig) : Hall(orig.getPlayer(), orig.window, orig.getSeed()) {} // orig.gamescreen.window

/* Default destructor */
Hall::~Hall() {}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Getter Methods ">

/* Basic getter methods */

unsigned int Hall::getSeed() const {
    return seed;
}

/* Return the Room at the given index */
Room* Hall::getRoom(unsigned int index) const {
    return at(index);
}

unsigned int Hall::getRoomPos(unsigned int index, unsigned int steps) {
    unsigned l = 0;
    for (unsigned int i = 0; i < index; i++) {
        l += at(i)->getLength();
    }
    return l + steps;
}

std::vector<Room*> Hall::getRange(unsigned int start, unsigned int end) const {
    //std::cout << "Getting range from " << std::to_string(start) << " to " << std::to_string(end) << "\n";
    if (start > size() || start > end) {
        //std::cout << "Start index invalid";
    }
    if (end > size() || end < start) {
        //std::cout << "End index invalid";
    }
    
    std::vector<Room*> temp;
    for (unsigned int i = start; i < end; i++) {
        temp.push_back(at(i));
    }
    return temp;
}

/* Get vector of the Rooms with space within the window's borders */
std::vector<Room*> Hall::getOnscreenRooms() const {
    return getRange((static_cast<int>(getActiveIndex()-1) < 0) ? 0 : getActiveIndex()-1, std::min(static_cast<unsigned int>(size()), getActiveIndex()+2));
}

Player& Hall::getPlayer() const {
    return player;
}

bool Hall::canEncounter() {
    return player.getPosInRoom() == at(activeIndex)->getLength()-1;
}

EncounterScreen* Hall::getEncounterScreen() {
    return at(activeIndex)->getScreen();
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Setter Methods ">

void Hall::setActiveRoom(unsigned int index) {
    at(getActiveIndex())->deactivate();
    setActiveIndex(index);
    at(getActiveIndex())->activate();
}

void Hall::setActiveRoom() {
    at(getActiveIndex())->activate();
}

void Hall::setActiveRoomPlayerX(unsigned int n) {
    player.setPosInRoom(n);
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Adder Methods ">

/* Add a Room to the Hall */
void Hall::addRoom(Room* r) {
    push_back(r);
    totalLength += r->getLength();
    r->getEncounter()->setPosition( (totalLength-player.getX()) * player.getStepSize(), 100); //Ideally the Room itself should handle this
    setActiveRoom();
}

/* Generate a random Room from the seed */
void Hall::addRoom() {
    srand(seed); //reset srand
    for (unsigned i = 0; i < size(); i++) {
        rand();
    }
    Room* r = new Room(static_cast<unsigned int>(rand()), window);
    addRoom(r);
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Graphical Methods ">

void Hall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (Room* r : getOnscreenRooms()) {
        target.draw(*r);
    }
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Print Methods ">

std::string Hall::printDistances() const {
    std::string output = "";
    output += "|";
    for (unsigned i = 0; i < size(); i++) {
        for (unsigned j = 0; j < (at(i)->getLength())-1; j++) {
            if (i == getActiveIndex() && j == player.getPosInRoom()) {
                output += "o";
            } else {
                output += "_";
            }
        }
        if (i == getActiveIndex() && at(i)->getLength()-1 == player.getPosInRoom()) {
            output += "A|";
        } else {
            output += "X|";
        }
    }
    output += "\n";
    return output;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Recalc and Update Methods ">

void Hall::recalcLength() {
    totalLength = 0;
    for(unsigned i = 0; i < size(); i++) {
        totalLength += at(i)->getLength();
    }
}

/* Calculate playerIndex based on playerX */
void Hall::updateIndex(const Player& p) {
    at(getActiveIndex())->deactivate();
    unsigned l = 0;
    for (unsigned int i = 0; i < size(); i++) {
        l += at(i)->getLength();
        if (l > p.getX()) {
            setActiveRoom(i);
            setActiveRoomPlayerX(at(i)->getLength() - (l - p.getX()));
            return;
        }
    }
}

void Hall::updateIndex() {
    updateIndex(getPlayer());
}

void Hall::updateRoomPositions() {
    for (Room* r : *this) {
        if (player.isMovingRight()) {
            r->getEncounter()->move(-player.getStepSize(), 0);
        } else {
            r->getEncounter()->move(player.getStepSize(), 0);
        }
    }
    if (size() - getActiveIndex() < 3) {
        addRoom();
    }
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Gen Methods ">

/* Generate seed based on the current time */
unsigned int Hall::genRandomSeed() {
    return std::time(NULL);
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Friend Methods ">

/* Return Hall for a stream */
std::ostream& operator<<(std::ostream &strm, const Hall &h) {
    return strm << h.operator std::string();
}

// </editor-fold>
