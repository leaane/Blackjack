#include "Blackjack.h"

int main () {
    std::srand(std::time(0));
    sf::VideoMode videoMode(520, 420, 32);
    sf::RenderWindow window(videoMode,"Blackjack");
    window.setFramerateLimit(60);

    Blackjack blackjack;

        while (window.isOpen()) {
            sf::Event event;

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                blackjack.eventHandler(window, event);
                blackjack.update();
            }

            window.clear(sf::Color(64, 64, 64));
            window.draw(blackjack);
            window.display();
        }

    return 0;
}