cmake_minimum_required(VERSION 3.24)
project(CS8)

set(CMAKE_CXX_STANDARD 17)

add_executable(CS8 
        Blackjack.cpp 
        Blackjack.h 
        Button.cpp 
        Button.h 
        Card.cpp 
        Card.h 
        CardGraphic.cpp 
        CardGraphic.h 
        CardHand.cpp 
        CardHand.h 
        Deck.cpp 
        Deck.h 
        DrawCard.cpp 
        DrawCard.h 
        Image.cpp 
        Image.h 
        mainBlackjack.cpp 
        MouseEvents.cpp 
        MouseEvents.h 
        Position.cpp 
        Position.h 
        Rank.h 
        States.cpp 
        States.h 
        StatesEnum.h 
        Suit.h)

target_link_libraries(CS8 sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
