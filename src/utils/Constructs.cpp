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


void Oscillator::run(sf::Event event) {
    attackSlider.currentPos += attackSlider.dir;
    if (attackSlider.currentPos >= outline.getPosition().x + outline.getSize().x - attackSlider.getSize().x) {
        attackSlider.dir = std::abs(attackSlider.dir) * -1;
        attackSlider.currentPos = outline.getPosition().x + outline.getSize().x - attackSlider.getSize().x;
    } else if (attackSlider.currentPos <= outline.getPosition().x) {
        attackSlider.dir = std::abs(attackSlider.dir);
        attackSlider.currentPos = outline.getPosition().x;
    }
    attackSlider.setPosition(sf::Vector2f(attackSlider.currentPos, attackSlider.getPosition().y));
}

void Oscillator::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(areas, 16, sf::TriangleStrip);
    target.draw(outline);
    target.draw(attackSlider);
}

float Oscillator::getStrength() {
    return 1.0;
}

void Oscillator::scramble() {
    srand(DEFAULT_GAMECLOCK.getElapsedTime().asMilliseconds());
    bool attackOnLeft = rand()%2;
    sf::Color colors[] = {
        sf::Color::Black,
        sf::Color::Black,
        (attackOnLeft) ? sf::Color::Green : sf::Color::Red,
        sf::Color::Black,
        sf::Color::Black,
        (attackOnLeft) ? sf::Color::Red : sf::Color::Green,
        sf::Color::Black,
        sf::Color::Black,
    };
    for (unsigned int i = 0; i < 16; i+=2) {
        areas[i]   = sf::Vertex(sf::Vector2f(outline.getPosition().x + outline.getSize().x/7*i/2, outline.getPosition().y                      ), colors[i/2]);
        areas[i+1] = sf::Vertex(sf::Vector2f(outline.getPosition().x + outline.getSize().x/7*i/2, outline.getPosition().y + outline.getSize().y), colors[i/2]);
    }
}

void Oscillator::initShapes(sf::Vector2f pos) {
    attackSlider.setFillColor(sf::Color::Cyan);
    attackSlider.setOutlineColor(sf::Color::Black);
    attackSlider.setOutlineThickness(3);
    attackSlider.setPosition(pos);
    outline.setFillColor(sf::Color::Transparent);
    outline.setOutlineColor(sf::Color::Black);
    outline.setOutlineThickness(3);
    outline.setPosition(pos);
}

void Oscillator::updateArea() {
    
}
