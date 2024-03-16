#include "Image.h"

sf::Texture Image::texture;

void Image::loadTexture() {
    texture.loadFromFile("Deck.png");
}

sf::Texture& Image::getImage() {
    loadTexture();
    return texture;
}