#ifndef CS8_IMAGE_H
#define CS8_IMAGE_H

#include <SFML/Graphics.hpp>

class Image {
private:
    static sf::Texture texture;
    static void loadTexture();

public:
    static sf::Texture& getImage();
};

#endif //CS8_IMAGE_H
