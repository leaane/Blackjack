#ifndef CS8_DECK_H
#define CS8_DECK_H

#include <iostream>
#include "Card.h"

class Deck {
private:
    const int DECK_SIZE = 52;
    int cardIndex = 0;
    Card deck[52];

public:
    Deck();
    void shuffle();
    Card dealCard();
    bool empty();

};


#endif //CS8_DECK_H
