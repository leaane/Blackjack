#include "Deck.h"

Deck::Deck() {
    shuffle();
}

void Deck::shuffle() {
    Card unshuffledDeck[52];

    //Initialize deck
    int cardIndex = 0;
    for (int rank = 0; rank < 13; rank++) {
        for (int suit = 0; suit < 4; suit++) {
            unshuffledDeck[cardIndex] = Card(static_cast<Rank>(rank), static_cast<Suit>(suit));
            cardIndex++;
        }
    }

    //Shuffle deck
    for (int i = DECK_SIZE - 1; i >= 0; --i) {
        int randomIndex = std::rand() % (i + 1);
        deck[i] = unshuffledDeck[randomIndex];
        std::swap(unshuffledDeck[randomIndex], unshuffledDeck[i]);
    }
}

Card Deck::dealCard() {
    Card temp = deck[cardIndex];
    if (empty()) {
        cardIndex = 0;
        shuffle();
    } else {
        cardIndex++;
    }
    return temp;
}

bool Deck::empty() {
    return cardIndex >= DECK_SIZE;
}