#include "Skippable.hpp"
#include <SFML/Graphics.hpp>

int Skippable::getTestValue() {
    return testID;
}

Skippable::Skippable(int id) {
    testID = id;
}

Skippable::Skippable(const Skippable& orig) {
    
}

Skippable::~Skippable() {
    
}