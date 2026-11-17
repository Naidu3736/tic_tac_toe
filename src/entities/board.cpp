#include "tictactoe/entities/board.hpp"

namespace naidu {

    Board::Board() {
        clear();
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

    std::size_t Board::dim() const {
        return k_max_dim;
    }

    void Board::clear() {
        for (auto& cell : m_board) 
            cell = State::Empty;
    }

}