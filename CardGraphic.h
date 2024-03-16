#ifndef CS8_CARDGRAPHIC_H
#define CS8_CARDGRAPHIC_H

#include <SFML/Graphics.hpp>
#include "Card.h"
#include "Image.h"

class CardGraphic : public sf::Drawable {
private:
    sf::Sprite sprite;

public:
    CardGraphic();
    CardGraphic(const Card& card);
    CardGraphic(Rank rank, Suit suit);
    CardGraphic(sf::Texture& image, Rank rank, Suit suit);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates state) const;
    void setPosition(float x, float y);
};


#endif //CS8_CARDGRAPHIC_H
