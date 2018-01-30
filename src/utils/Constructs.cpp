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


HealthBar::HealthBar(sf::Vector2f pos, sf::Vector2f size, unsigned int& source, unsigned int& max) : outline(size), health(size), source(source), max(max) {
    outline.setPosition(pos);
    outline.setFillColor(sf::Color::Transparent);
    outline.setOutlineColor(sf::Color::Black);
    outline.setOutlineThickness(2);
    health.setPosition(pos);
    health.setFillColor(sf::Color::Green);
    health.setOutlineThickness(0);
}

HealthBar::HealthBar(const HealthBar& orig) : outline(orig.outline), health(orig.health), source(orig.source), max(orig.max) {};

void HealthBar::update() {
    //std::cout << "Health: " << source << "/" << max << "\n";
    if (max == 0) {
        health.setSize(sf::Vector2f(0, health.getSize().y));
    } else {
        health.setSize(sf::Vector2f(source/static_cast<float>(max)*outline.getSize().x, health.getSize().y));
    }
}

void HealthBar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(health);
    target.draw(outline);
};
