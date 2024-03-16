#include "DrawCard.h"

sf::Font DrawCard::font;
DrawCard::DrawCard() {

}

DrawCard::DrawCard(CardGraphic card1, CardGraphic card2, float x, float y, int total, std::string name) {
    this->card1 = card1;
    this->card2 = card2;

    if(!font.loadFromFile("OpenSans-Bold.ttf")) {
        exit(28);
    }

    text.setFont(font);
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    text.setString(name + "\n" + std::to_string(total));
    setPosition(x,y);
}

DrawCard::DrawCard(CardGraphic card1, CardGraphic card2, CardGraphic card3, float x, float y, int total, std::string name) {
    this->card1 = card1;
    this->card2 = card2;
    this->card3 = card3;

    has3 = true;

    if(!font.loadFromFile("OpenSans-Bold.ttf")) {
        exit(28);
    }

    text.setFont(font);
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    text.setString(name + "\n" + std::to_string(total));
    setPosition(x,y);
}


void DrawCard::setPosition(float x, float y) {
    card1.setPosition(x, y);
    card2.setPosition(x+50, y);
    if (has3) {
        card3.setPosition(x+100,y);
    }
    text.setPosition(x, y+80);
}

void DrawCard::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    window.draw(card1);
    window.draw(card2);
    window.draw(text);

    if (has3) {
        window.draw(card3);
    }
}