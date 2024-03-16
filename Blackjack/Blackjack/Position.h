#ifndef CS8_POSITION_H
#define CS8_POSITION_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Position {

public:
    template<typename T, typename S>
    static void left(const S& constObj, T& obj, float spacing = 0);
    template<typename T>
    static void centerText(const T &obj, sf::Text &text);

};

#include "Position.cpp"
#endif //CS8_POSITION_H

