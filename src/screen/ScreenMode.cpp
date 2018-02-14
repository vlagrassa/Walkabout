#include "ScreenMode.hpp"

LinkedButton::LinkedButton(ScreenMode& link, sf::RectangleShape rect, sf::Window& window) : link(link), window(window), outline(rect) {
    activate();
    title.setFillColor(sf::Color::Black);
    title.setFont(DEFAULT_FONT);
};

LinkedButton::LinkedButton(ScreenMode* link, sf::RectangleShape rect, sf::Window& window) : LinkedButton(*link, rect, window) {};

LinkedButton::LinkedButton(const LinkedButton& orig) : LinkedButton(orig.link, orig.outline, orig.window) {
    key = orig.key;
    onText = orig.onText;
    offText = orig.offText;
};

LinkedButton::~LinkedButton() {};

void LinkedButton::setKey(sf::Keyboard::Key k) {
    key = k;
}

void LinkedButton::setTitle(std::string text) {
    title.setString(text);
    title.setPosition(
            outline.getPosition().x + outline.getSize().x/2 - title.getGlobalBounds().width/2,
            outline.getPosition().y + outline.getSize().y/2 - title.getGlobalBounds().height*3/4
    );
}

void LinkedButton::setTitles(std::string text1, std::string text2) {
    onText = text1;
    offText = text2;
    if (active) {
        setTitle(onText);
    } else {
        setTitle(offText);
    }
}

sf::Vector2f LinkedButton::getCenter() {
    return sf::Vector2f(outline.getPosition().x + outline.getSize().x/2, outline.getPosition().y + outline.getSize().y/2);
}

bool LinkedButton::touchingMouse() {
    return outline.getGlobalBounds().contains(sf::Mouse().getPosition(window).x, sf::Mouse().getPosition(window).y);
}

bool LinkedButton::clicked() {
    return touchingMouse() && sf::Mouse().isButtonPressed(sf::Mouse().Left) && active;
}

void LinkedButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(outline);
    target.draw(title);
}

bool LinkedButton::isActive() {
    return active;
}

void LinkedButton::setActive(bool b) {
    if (b) {
        activate();
    } else {
        deactivate();
    }
}

void LinkedButton::activate() {
    active = true;
    setTitle(onText);
}

void LinkedButton::deactivate() {
    active = false;
    setTitle(offText);
}


ScreenMode::ScreenMode(sf::Window& window) : window(window) {};

ScreenMode::ScreenMode(const ScreenMode& orig) : window(orig.window) {};

ScreenMode::~ScreenMode() {};

ScreenMode* ScreenMode::update(sf::Event event) {
    return this;
}

ScreenMode* ScreenMode::run(sf::Event event) {
    return checkButtons(event);
};

ScreenMode* ScreenMode::checkButtons(sf::Event event) {
    for (Node<LinkedButton&>* n = buttons.first; n != 0; n = n->next) {
        if (n->data.clicked() || (event.key.code == n->data.key)) {
            return &n->data.link;
        }
    }
    return this;
};

void ScreenMode::addButton(LinkedButton& b) {
    buttons.add(b);
}

void ScreenMode::addButton(std::string title, ScreenMode& link, sf::Keyboard::Key key, sf::Font& font) {
    addButton(title, &link, key, font);
}

void ScreenMode::addButton(std::string title, ScreenMode* link, sf::Keyboard::Key key, sf::Font& font) {
    LinkedButton* temp = new LinkedButton(link, DEFAULT_RECT, window);
    temp->setKey(key);
    temp->setTitles(title, "");
    addButton(*temp);
}

void ScreenMode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (Node<LinkedButton&>* n = buttons.first; n != 0; n = n->next) {
        //if (n->data.isActive()) {
            target.draw(n->data);
        //}
    }
}


TransitionScreen::TransitionScreen(ScreenMode* link, sf::Window& window) : ScreenMode(window), link(link) {
    showPrevious = true;
};

TransitionScreen::TransitionScreen(const TransitionScreen& orig) : TransitionScreen(orig.link, orig.window) {};

TransitionScreen::~TransitionScreen() {};

ScreenMode* TransitionScreen::run(sf::Event event) {
    if (forward) {
        return runForward();
    } else {
        return runBackward();
    }
}

ScreenMode* TransitionScreen::runForward() {
    std::cout << "Transitioning forward...\n";
    forward = false;
    return link;
};

ScreenMode* TransitionScreen::runBackward() {
    forward = true;
    std::cout << "Transitioning backward...\n";
    return NULL;
};
