#include "CardGraphic.h"

CardGraphic::CardGraphic() : CardGraphic(ACE, CLUBS) {

}

CardGraphic::CardGraphic(const Card& card) : CardGraphic(card.getRank(), card.getSuit()) {


}

CardGraphic::CardGraphic(Rank rank, Suit suit) : CardGraphic(Image::getImage(), rank, suit) {

}

CardGraphic::CardGraphic(sf::Texture& image, Rank rank, Suit suit) {
    sf::IntRect intRect;
    intRect.width = image.getSize().x/13;
    intRect.height = image.getSize().y/4;

    intRect.left = intRect.width * rank;
    intRect.top = intRect.height * suit;

    sprite.setTexture(image);
    sprite.setTextureRect(intRect);
}

void CardGraphic::draw(sf::RenderTarget& window, sf::RenderStates state) const {
    window.draw(sprite);
}

void CardGraphic::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}