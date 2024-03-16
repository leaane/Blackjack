#ifndef CS8_CARDHAND_H
#define CS8_CARDHAND_H

#include <vector>
#include "Card.h"

class CardHand {
private:
    std::vector<Card> cardHand;

public:
    CardHand();
    void addCard(Card card);
    void removeCard();
    Card getCardHand(int index);
};


#endif //CS8_CARDHAND_H
