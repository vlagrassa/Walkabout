#include "Encounterable.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

// <editor-fold defaultstate="collapsed" desc=" Con/Destructors ">

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Default constructor method - can't be used anyways, this
 * is an abstract class.
 */
Encounterable::Encounterable() {
    screen = new EncounterScreen();
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Default constructor method.
 */
Encounterable::Encounterable(const Encounterable& orig) {
    
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Default destructor method. Deletes:
 *   -EncounterScreen screen
 */
Encounterable::~Encounterable() {
    delete screen;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" Inherited Methods ">

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Get the list of Items held by the Encounterable - as far
 * as I can tell, all Encounterable subclasses will have one
 * @return vector of Items held by the Encounterable
 */
std::vector<int> Encounterable::getReward() const {
    return reward;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * 
 * Get the EncounterScreen associated with the Encounterable.
 * Will be overwritten by each subclass.
 * @return EncounterScreen representing the encounter
 */
EncounterScreen* Encounterable::getEncounterScreen() const {
    std::cout << "Returning default encounter screen!" << "\n";
    return screen;
}

// </editor-fold>
