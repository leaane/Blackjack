#ifndef CS8_BUTTON_H
#define CS8_BUTTON_H

#include <SFML/Graphics.hpp>
#include "Position.h"
#include "MouseEvents.h"
#include "States.h"

class Button : public sf::Drawable, public States {
private:
    sf::Text text;
    sf::Font font;
    sf::RectangleShape rectangle;
    sf::Color defaultColor, clickColor;
    void setUpText(const std::string& text, sf::Font& font);
    void setUpButton(sf::Vector2f size);
    void setCharacterSize();

public:
    Button();
    Button(const std::string& text);
    Button(const std::string& text, sf::Vector2f size);
    Button(const std::string& text, sf::Vector2f size, sf::Font& font);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void setPosition(sf::Vector2f position);
    bool update();
    sf::FloatRect getGlobalBounds() const;

};


#endif //CS8_BUTTON_H
