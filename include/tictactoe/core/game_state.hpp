#pragma once

#include "tictactoe/entities/board.hpp"
#include "tictactoe/entities/player.hpp"

#include <array>

namespace naidu {

    enum class Status {
        IN_PROGRESS,
        PLAYER1_WINNER,
        PLAYER2_WINNER,
        TIE,
    };

    class GameState {
        private:
            Board m_board;

            std::array<Player, 2> m_players;    

            Player *m_current_player;

            Status m_status;

            unsigned int m_round;

        public:
            GameState(const std::string &player1_name, const std::string &player2_name);

            const Player& current_player() const;
            const Board& board() const;
            const Status status() const;
            const unsigned int round() const; 
    };
    
}