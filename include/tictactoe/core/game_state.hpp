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
            /**
             * @brief Valida si el jugador con el simbolo ha ganado.
             * 
             * @param symbol 
             * @return true Si el jugador con el símbolo ha ganado
             * @return false Si el jugador con el símbolo no ha ganado
             */
            bool check_win(State symbol) const;

            /**
             * @brief Valida si la partida ha terminado en empate
             * 
             * @return true Si se ha llenado el tablero sin un ganador
             * @return false Si ha habido un ganador o no se ha llenado el tablero
             */
            bool check_tie() const;

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
             * @return const Player& Jugador de solo lectura
             */
            const Player& current_player() const;

            /**
             * @brief Devuelve el estado actual del tablero
             * 
             * @return const Board& Tablero de solo lectura
             */
            const Board& board() const;

            /**
             * @brief Devuelve el estado actual de la partida
             * 
             * @return Status Estado actual de la partida 
             */
            Status status() const;

            /**
             * @brief Devuelve la ronda actual de la partida
             * 
             * @return Ronda actual de la partida
             */
            std::size_t round() const;
            
            
            /**
             * @brief Valida si el moviento es permitido
             * 
             * @param index 
             * @return true Si es un movimiento legal
             * @return false Si no es un movimiento legal
             */
            bool make_move(std::size_t index);

            /**
             * @brief Restablece el estado del juego
             */
            void reset();

        private:
            /** @brief Tablero de la partida en curso */
            Board m_board;

            /** @brief Par de jugadores de la partida */
            std::array<Player, 2> m_players;    

            /** @brief Índice al jugador actual de la ronda */
            std::size_t m_current_player_idx;

            /** @brief Acumulador de rondas de la partida */
            unsigned int m_round;
    };
    
}