#ifndef CS8_BLACKJACK_H
#define CS8_BLACKJACK_H

#include <SFML/Graphics.hpp>
#include <queue>
#include "DrawCard.h"
#include "Deck.h"
#include "CardHand.h"
#include "Button.h"

class Blackjack : public sf::Drawable {
private:
    sf::Text text;
    sf::Font font;
    sf::RectangleShape cover;
    Card D1, D2, P1, P2, P3;
    Deck deck;
    CardHand dealer, player;
    Button replay, hit, play;
    DrawCard playerHand, dealerHand;
    bool has3;
    int playerTotal;
    std::queue<Card> pHand;

public:
    Blackjack();
    virtual void draw(sf::RenderTarget& window , sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void run();

};


#endif //CS8_BLACKJACK_H
