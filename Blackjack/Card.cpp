#include "Card.h"

Card::Card () {

}

Card::Card (Rank rank, Suit suit): rank(rank), suit(suit){

}

std::ostream& operator<<(std::ostream& out, const Card& card) {
    out << card.rankToString() << " of " << card.suitToString();
    return out;
}

std::string Card::rankToString() const {
    switch(rank) {
        case ACE: return "Ace";
        case TWO: return "Two";
        case THREE: return "Three";
        case FOUR: return "Four";
        case FIVE: return "Five";
        case SIX: return "Six";
        case SEVEN: return "Seven";
        case EIGHT: return "Eight";
        case NINE: return "Nine";
        case TEN: return "Ten";
        case JACK: return "Jack";
        case QUEEN: return "Queen";
        case KING: return "King";
    }
}

std::string Card::suitToString() const {
    switch(suit) {
        case HEARTS: return "Hearts";
        case SPADES: return "Spades";
        case DIAMONDS: return "Diamonds";
        case CLUBS: return "Clubs";
    }
}

const Rank& Card::getRank() const {
    return rank;
}

const Suit& Card::getSuit() const {
    return suit;
}

int Card::getRankValue() const {
   return rank < 10 ? rank + 1 : 10;
}

int operator+(const Card& card1, const Card& card2) {
    int total = card1.getRankValue() + card2.getRankValue();

    if (card1.getRankValue() == 1 && card2.getRankValue() == 1) {
        total = 12;
    } else if (card1.getRankValue() == 1 && card2.getRankValue() != 1) {
        if (card2.getRankValue() <= 10) {
            total = card2.getRankValue() + 11;
        } else {
            total = card2.getRankValue() + 1;
        }
    } else if (card2.getRankValue() == 1 && card1.getRankValue() != 1) {
        if (card1.getRankValue() <= 10) {
            total = card1.getRankValue() + 11;
        } else {
            total = card1.getRankValue() + 1;
        }
    }

    return total;
}