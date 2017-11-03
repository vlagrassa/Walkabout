#ifndef SKIPPABLE_H
#define SKIPPABLE_H

#include <SFML/Graphics.hpp>


class Skippable {
public:
    Skippable(int id);
    Skippable(const Skippable& orig);
    virtual ~Skippable();
    int getTestValue();
private:
    int testID;
};


#endif /* SKIPPABLE_H */