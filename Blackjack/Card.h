#ifndef CS8_CARD_H
#define CS8_CARD_H

#include <iostream>
#include "Rank.h"
#include "Suit.h"

class Card {
private:
    Suit suit;
    Rank rank;

public:
    Card();
    Card(Rank rank, Suit suit);
    friend std::ostream& operator<<(std::ostream& out, const Card& card);
    std::string rankToString() const;
    std::string suitToString() const;
    const Rank& getRank() const;
    const Suit& getSuit() const;
    int getRankValue() const;
    friend int operator+(const Card& card1, const Card& card2);

};

#endif //CS8_CARD_H