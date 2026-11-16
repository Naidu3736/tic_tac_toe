#include "tictactoe/entities/board.hpp"
#include <stdexcept>

namespace naidu {

    Board::Board() {
        for (auto& cell : m_board) 
            cell = State::Empty;
    }

    State& Board::operator[](std::size_t index) {
        
    }

    const State& Board::operator[](std::size_t index) const {
        
    }

    std::size_t Board::size() const {

    }

    void Board::clear() {

    }

}