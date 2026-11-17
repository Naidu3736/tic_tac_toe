#pragma once

#include "tictactoe/entities/board.hpp"
#include "tictactoe/entities/player.hpp"

#include <array>
#include <cstddef>
#include <string_view>

namespace naidu {

    /**
     * @enum Status
     * @brief Representa el estado del juego
     * @details Indica el estado actual de la partida.
     *          Se usa para determinar si el juego esta en 
     *          progreso, si hubo ganador o empate entre
     *          ambos jugadores.
     */
    enum class Status {
        IN_PROGRESS,
        PLAYER1_WINNER,
        PLAYER2_WINNER,
        TIE,
    };

    /**
     * @class GameState
     * @brief Representa el estado del juego.
     * @details Almacena el estado del tablero, jugador
     *          turnos, el estado global y verifica si 
     *          hubo empate o quien gano la partida.
     * @date 17-11-2026
     * @version 2.0
     */
    class GameState {
        private:
            Board m_board;
            std::array<Player, 2> m_players;    
            std::size_t m_current_player_idx;
            Status m_status;
            unsigned int m_round;

            /**
             * @brief Valida si el jugador con el simbolo ha ganado.
             * 
             * @param symbol 
             * @return true 
             * @return false 
             */
            bool check_win(State symbol);

            /**
             * @brief Valida si la partida ha terminado en empate
             * 
             * @return true 
             * @return false 
             */
            bool check_tie();

        public:
            /**
             * @brief Constructor que inicializa el estado del juego
             * 
             * @param player1_name 
             * @param player2_name 
             */
            GameState(std::string_view player1_name, std::string_view player2_name);

            /**
             * @brief Devuelve el jugador actual de la ronda
             * 
             * @return const Player& 
             */
            const Player& current_player() const;

            /**
             * @brief Devuelve el estado actual del tablero
             * 
             * @return const Board& 
             */
            const Board& board() const;

            /**
             * @brief Devuelve el estado actual de la partida
             * 
             * @return const Status 
             */
            const Status status() const;

            /**
             * @brief Devuelve la ronda actual de la partida
             * 
             * @return const unsigned int 
             */
            const unsigned int round() const;
            
            
            /**
             * @brief Valida si el moviento es permitido
             * 
             * @param index 
             * @return true 
             * @return false 
             */
            bool make_move(std::size_t index);

            /**
             * @brief Restablece el estado del juego
             */
            void reset();
    };
    
}