#include "Constructs.hpp"

void ButtonLine::fitButtonsToRect(LinkedList<LinkedButton&>& buttons) {

    unsigned int length = ((horizontal?width:height) - (gap * (buttons.size-1))) / buttons.size;

    for (unsigned int i = 0; i < buttons.size; i++) {
        LinkedButton& current = buttons.get(i);

        if (horizontal) {
            current.outline.setPosition(left + i * (length + gap), top);
            current.outline.setSize(sf::Vector2f(length, height));
        } else {
            current.outline.setPosition(left, top + i * (length + gap));
            current.outline.setSize(sf::Vector2f(width, length));
        }

        float scaleX = current.title.getGlobalBounds().width / current.outline.getSize().x / 2;
        float scaleY = current.title.getGlobalBounds().height / current.outline.getSize().y;

        current.title.setPosition(current.getCenter().x - (scaleX*current.outline.getSize().x), current.getCenter().y - (scaleY*current.outline.getSize().y));
    }
};


void FrameRate::updateFrames(sf::Clock clock, sf::Event event) {
    int newUpdateTime = clock.getElapsedTime().asMilliseconds();
    if (prevUpdateTime + frameRate <= newUpdateTime) {
        prevUpdateTime = newUpdateTime;
        run(event);
    }
};
