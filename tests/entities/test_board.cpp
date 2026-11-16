#include "tictactoe/entities/board.hpp"

#include <doctest/doctest.h>
#include <cstddef>

TEST_CASE("Board: Constructor por defecto") {
    naidu::Board board;

    for (std::size_t i = 0; i < board.size(); ++i)
        CHECK_EQ(board[i], naidu::State::Empty);
}

TEST_CASE("Board: Operador []") {
    naidu::Board board;

    CHECK_EQ(board[3], naidu::State::Empty);

    board[3] = naidu::State::X;

    CHECK(board[3] == naidu::State::X);

    CHECK_NE(board[2], naidu::State::X);
    CHECK_NE(board[4], naidu::State::X);
}

TEST_CASE("Board: Operador [] de solo lectura") {
    const naidu::Board board;

    auto state = board[4];
    
    CHECK_EQ(state, naidu::State::Empty);
}