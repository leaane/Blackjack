#include "Button.h"

Button::Button() : Button("0") {}

Button::Button(const std::string &text) : Button(text, {10,10}) {}

Button::Button(const std::string &text, sf::Vector2f size)
: defaultColor(212, 115, 40), clickColor(34, 15, 74) {
    if(!font.loadFromFile("OpenSans-Bold.ttf")) {
        exit(28);
    }

    setUpButton(size);
    setUpText(text, font);
}

Button::Button(const std::string &text, sf::Vector2f size, sf::Font& font)
: defaultColor(212, 115, 40), clickColor(34, 15, 74) {
    setUpButton(size);
    setUpText(text, font);
}

void Button::setUpText(const std::string &text, sf::Font &font) {
    this->text.setFont(font);
    this->text.setString(text);
    setCharacterSize();
    Position::centerText(rectangle, this->text);
}

void Button::setUpButton(sf::Vector2f size) {
    rectangle.setSize(size);
    rectangle.setFillColor(defaultColor);
}

void Button::setCharacterSize() {
    float width = rectangle.getSize().x;
    unsigned int size = static_cast<unsigned int>((2.f / 12) * width);
    this->text.setCharacterSize(size);
}

bool Button::update() {
    if (getState(CLICKED)) {
        rectangle.setFillColor(clickColor);
        return true;
    } else {
        rectangle.setFillColor(defaultColor);
        return false;
    }
}


void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(!getState(HIDDEN)) {
        states.transform = rectangle.getTransform();
        window.draw(rectangle);
        window.draw(text, states);
    }
}

void Button::setPosition(sf::Vector2f position) {
    rectangle.setPosition(position);
}

void Button::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents::isClicked(rectangle, window)) {
        enableState(CLICKED);
    } else {
        disableState(CLICKED);
    }
}

sf::FloatRect Button::getGlobalBounds() const {
    return rectangle.getGlobalBounds();
}