#include "tictactoe/core/game_state.hpp"
#include "tictactoe/entities/board.hpp"

#include <cstddef>
#include <stdexcept>
#include <string_view>

namespace {

    bool check_diagonals(const naidu::Board& board, naidu::State symbol) {        
        auto n = board.dim();
        
        bool firts_diagonal = true;
        bool second_diagonal = true;

        for (std::size_t i = 0; i < n; ++i) {
            if (board[i + i * n] != symbol)
                firts_diagonal = false;
            if (board[(n - 1 - i) + i * n] != symbol)
                second_diagonal = false;
        }

        return firts_diagonal || second_diagonal;
    }

    bool check_rows_cols(const naidu::Board& board, naidu::State symbol) {
        auto n = board.dim();
        
        bool row;
        bool col;
        
        for (std::size_t i = 0; i < n; ++i) {
            row = true;
            col = true;

            for (std::size_t j = 0; j < n; ++j) {
                if (board[i + j * n] != symbol)
                    row = false;
                if (board[j + i * n] != symbol)
                    col = false;
            }

            if (row || col)
                return true;
        }

        return false;
    }

}

namespace naidu {

    bool GameState::check_win(State symbol)const  {
        return check_diagonals(m_board, symbol) || 
               check_rows_cols(m_board, symbol);
    }

    bool GameState::check_tie() const {
        if (check_win(State::O) || check_win(State::X))
            return false;

        for (std::size_t i = 0; i < m_board.size(); ++i) 
            if (m_board[i] == State::Empty)
                return false;

        return true;
    }

    GameState::GameState(std::string_view player1_name, std::string_view player2_name) 
        : m_board()
        , m_players{Player(player1_name), Player(player2_name)} 
        , m_current_player_idx{0}
        , m_round{1} 
    {
        m_players[0].set_symbol(State::O);
        m_players[1].set_symbol(State::X);
    }

    const Player& GameState::current_player() const {
        return m_players[m_current_player_idx];
    } 

    const Board& GameState::board() const {
        return m_board;
    }

    Status GameState::status() const {
        auto p1_symbol = m_players[0].symbol();
        auto p2_symbol = m_players[1].symbol();

        if (!p1_symbol || !p2_symbol) 
            throw std::runtime_error("Player without symbol");

        if (check_win(*p1_symbol))
            return Status::PLAYER1_WINNER;

        if (check_win(*p2_symbol))
            return Status::PLAYER2_WINNER;

        if (check_tie())
            return Status::TIE;

        return Status::IN_PROGRESS;
    }

    std::size_t GameState::round() const {
        return m_round;
    }


    bool GameState::make_move(std::size_t index) {
        if (index >= m_board.size())
            return false;

        if (m_board[index] != State::Empty)
                return false;
        
        auto symbol = current_player().symbol();

        if (!symbol)
            throw std::runtime_error("Player without symbol");

        m_board[index] = *symbol;
        m_current_player_idx = (m_current_player_idx + 1) % m_players.size();
        ++m_round;      
        
        return true;
    }

    void GameState::reset() {
        m_board.clear();
        m_round = 1;
    }
}