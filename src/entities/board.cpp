#include "tictactoe/entities/board.hpp"
#include <stdexcept>

namespace naidu {

    Board::Board() {
        for (auto& cell : m_board) 
            cell = State::Empty;
    }

    State& Board::operator[](std::size_t index) {
        return m_board[index];
    }

    const State& Board::operator[](std::size_t index) const {
        return m_board[index];
    }

    std::size_t Board::size() const {
        return m_board.size();
    }

    void Board::clear() {

    }

}