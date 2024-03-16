#include "CardHand.h"

CardHand::CardHand() {

}

void CardHand::addCard(Card card) {
    cardHand.push_back(card);
}

void CardHand::removeCard() {
    cardHand.pop_back();
}

Card CardHand::getCardHand(int index) {
    if (index == 1) {
        return cardHand[0];
    } else if (index == 2) {
        return cardHand[1];
    } else {
        return cardHand[2];
    }
}