#include "Encounterable.hpp"
#include "Region.hpp"
#include <SFML/Graphics.hpp>

Encounterable::Encounterable() {
    
}
Encounterable::Encounterable(const Encounterable& orig) {
    
}
Encounterable::~Encounterable() {
    
}

bool Encounterable::isSkippable() {
    return skippable;
}