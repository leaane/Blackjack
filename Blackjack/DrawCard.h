#ifndef CS8_DRAWCARD_H
#define CS8_DRAWCARD_H

#include "CardGraphic.h"

class DrawCard : public sf::Drawable{
private:
    CardGraphic card1, card2, card3;
    sf::Text text;
    static sf::Font font;
    bool has3;

public:
    DrawCard();
    DrawCard(CardGraphic card1, CardGraphic card2, float x, float y, int total, std::string name);
    DrawCard(CardGraphic card1, CardGraphic card2, CardGraphic card3, float x, float y, int total, std::string name);
    void setPosition(float x, float y);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CS8_DRAWCARD_H
