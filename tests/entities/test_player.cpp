#include "tictactoe/entities/player.hpp"

#include <doctest/doctest.h>

TEST_CASE("Player: Constructor por defecto") {
    naidu::Player player("player_1");

    CHECK_EQ(player.name(), "player_1");
    CHECK_EQ(player.symbol(), std::nullopt);
    CHECK_EQ(player.wins(), 0u);
}

TEST_CASE("Player: add_wins() incrementa el contador") {
    naidu::Player player("player_1");

    // Sin victorias
    CHECK_EQ(player.wins(), 0u);
    
    // Primera victoria
    player.add_wins();
    CHECK_EQ(player.wins(), 1u);
    
    // Segunda victoria
    player.add_wins();
    CHECK_EQ(player.wins(), 2u);
}


TEST_CASE("Player: symbol() devuelve el símbolo del jugador") {
    naidu::Player player("player_1");

    CHECK_EQ(player.symbol(), std::nullopt);
}

TEST_CASE("Player: set_symbol() asignal el símbolo al jugador") {
    naidu::Player player("player_1");

    player.set_symbol(naidu::State::O);
    auto symbol = player.symbol();

    CHECK_EQ(*symbol, naidu::State::O);
}

TEST_CASE("Player: wins() devuelva el valor actual del contador") {
    naidu::Player player("player_1");

    CHECK_EQ(player.wins(), 0u);
}

TEST_CASE("Player: name() devuelva el nombre del jugador") {
    naidu::Player player("player_1");

    CHECK_EQ(player.name(), "player_1");
}