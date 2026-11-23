#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "tictactoe/entities/board.hpp"

#include <optional>
#include <string>
#include <string_view>

namespace naidu {
    /**
     * @class Player
     * @brief Metadata del jugador.
     * @details Almacena el nombre y el número de victorias del jugador,
     *          permitiendo consultar estos datos y actualizar las victorias.
     * @author Francisco Aparicio Martínez
     * @date 26-08-2026
     * @version 1.0
     */
    class Player {
        public:
            /** 
             * @brief Constructor que inicializa un jugador
             * @param name Nombre del jugador
             */
            explicit Player(std::string_view name);

            /** 
             * @brief Incrementa el contador de victorias en uno
             */
            void add_wins();

            /** 
             * @brief Obtiene el nombre del jugador
             * @return Nombre del jugador
             */
            const std::string& name() const;

            /**
             * @brief Devuelve el símbolo con el que juega el jugador 
             * 
             * @return State: Símbolo asignado al jugador (X u O)
             */
            std::optional<State> symbol() const;

            /**
             * @brief Asigna un símbolo al jugador (X y O)
             * 
             * @param symbol 
             */
            void set_symbol(State symbol);

            /**
             * @brief Obteniene el número de victorias
             * @return Número de victorias
             */
            unsigned int wins() const;

            /**
             * @brief Compara si dos jugadores son iguales
             * 
             * @param other 
             * @return true Si son el mismo jugador
             * @return false Si no son el mismo jugador
             */
            bool operator==(const Player &other) const;

            /**
             * @brief Compara si dos jugadores no son iguales
             * 
             * @param other 
             * @return true Si no son el mismo jugador
             * @return false Si son el mismo jugador
             */
            bool operator!=(const Player &other) const;

        private:
            /** @brief Nombre del jugador */
            std::string m_name;

            /** @brief Simbolo vinculado al jugador */
            std::optional<State> m_symbol;

            /** @brief Número de victorias del jugador */
            unsigned int m_wins;
    };
}

#endif // PLAYER_HPP