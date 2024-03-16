#ifndef CS8_MOUSEEVENTS_CPP
#define CS8_MOUSEEVENTS_CPP
#include "MouseEvents.h"

namespace MouseEvents {
    template<typename T>
    bool isHovered(const T &obj, sf::RenderWindow& window) {
        sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
        return obj.getGlobalBounds().contains(mpos);
    }

    template<typename T>
    bool isClicked(const T &obj, sf::RenderWindow &window) {
        return isHovered(obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
    }

} // MouseEvents

#endif