#include "Blackjack.h"

Blackjack::Blackjack() {
    if(!font.loadFromFile("OpenSans-Bold.ttf")) {
        exit(28);
    }

    has3 = false;

    run();

    //Buttons
    replay = Button("Play Again?", {160, 50}, font);
    replay.setPosition({165, 300});
    replay.enableState(HIDDEN);
    hit = Button("Hit", {60, 30}, font);
    hit.setPosition({320, 180});
    play = Button("Play", {60, 30}, font);
    play.setPosition({400, 180});

    //Winner text
    text.setFont(font);
    text.setPosition({175, 240});
    text.setCharacterSize(25);

    //Dealer cover
    cover.setSize({200., 150});
    cover.setPosition({80, 50});
    cover.setFillColor(sf::Color(64, 64 ,64));
}

void Blackjack::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(dealerHand);
    window.draw(playerHand);
    window.draw(replay);
    window.draw(hit);
    window.draw(play);
    window.draw(text);
    window.draw(cover);
}

void Blackjack::eventHandler(sf::RenderWindow &window, sf::Event event) {
    replay.eventHandler(window, event);
    play.eventHandler(window, event);
    hit.eventHandler(window, event);
}

void Blackjack::update() {
    if (replay.update()) {
        dealer.removeCard();
        dealer.removeCard();
        player.removeCard();
        player.removeCard();
        if (has3) {
            player.removeCard();
            has3 = false;
        }
        run();
        replay.enableState(HIDDEN);
        hit.disableState(HIDDEN);
        play.disableState(HIDDEN);
        text.setString("");
        cover.setFillColor(sf::Color(64, 64 ,64));
    }

    if (play.update()) {
        if (playerTotal > 21) {
            text.setString("You busted!");
        } else if (playerTotal == (D1+D2)) {
            text.setString("Tie!");
        } else if (playerTotal > (D1+D2)) {
            text.setString("You won :)");
        } else {
            text.setString("You lost :(");
        }
        replay.disableState(HIDDEN);
        hit.enableState(HIDDEN);
        play.enableState(HIDDEN);
        cover.setFillColor(sf::Color(64, 64 ,64, 0));
    }

    if (hit.update()) {
        hit.enableState(HIDDEN);
        has3 = true;

        player.addCard(deck.dealCard());
        P3 = player.getCardHand(3);

        pHand.push(P1);
        pHand.push(P2);
        pHand.push(P3);

        int aces = 0;
        for (int i = 1; i < 7; i+=2) {
            if (pHand.front().getRankValue() == 1) {
                aces += i;
            }
            pHand.pop();
        }

        playerTotal = P1.getRankValue() + P2.getRankValue() + P3.getRankValue();
        if (aces == 1) {
            if ((P3 + P2) <= 10) {
                playerTotal = P3 + P2 + 11;
            } else {
                playerTotal = P3 + P2 + 1;
            }
        } else if (aces == 3) {
            if ((P1 + P3) <= 10) {
                playerTotal = P1 + P3 + 11;
            } else {
                playerTotal = P1 + P3 + 1;
            }
        } else if (aces == 5) {
            if ((P1 + P2) <= 10) {
                playerTotal = P1 + P2 + 11;
            } else {
                playerTotal = P1 + P2 + 1;
            }
        } else if (aces == 4 || aces == 6 || aces == 8) {
            if (playerTotal + 10 <= 21) {
                playerTotal += 10;
            }
        }

        playerHand = DrawCard(P1, P2, P3, 320, 50, playerTotal, "Your Hand");
    }
}

void Blackjack::run() {
    dealer.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    player.addCard(deck.dealCard());

    D1 = dealer.getCardHand(1);
    D2 = dealer.getCardHand(2);
    P1 = player.getCardHand(1);
    P2 = player.getCardHand(2);
    playerTotal = P1 + P2;

    dealerHand = DrawCard(D1, D2, 80, 50, D1 + D2, "Dealer's Hand");;
    playerHand = DrawCard(P1, P2, 320, 50, playerTotal, "Your Hand");;
}