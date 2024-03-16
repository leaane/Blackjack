cmake_minimum_required(VERSION 3.24)
project(CS8)

set(CMAKE_CXX_STANDARD 17)

add_executable(CS8 Blackjack/Blackjack.cpp
        Blackjack/Blackjack.h
        Blackjack/Button.cpp
        Blackjack/Button.h
        Blackjack/Card.cpp
        Blackjack/Card.h
        Blackjack/CardGraphic.cpp
        Blackjack/CardGraphic.h
        Blackjack/CardHand.cpp
        Blackjack/CardHand.h
        Blackjack/Deck.cpp
        Blackjack/Deck.h
        Blackjack/DrawCard.cpp
        Blackjack/DrawCard.h
        Blackjack/Image.cpp
        Blackjack/Image.h
        Blackjack/mainBlackjack.cpp
        Blackjack/MouseEvents.cpp
        Blackjack/MouseEvents.h
        Blackjack/Position.cpp
        Blackjack/Position.h
        Blackjack/Rank.h
        Blackjack/States.cpp
        Blackjack/States.h
        Blackjack/StatesEnum.h
        Blackjack/Suit.h)

target_link_libraries(CS8 sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)