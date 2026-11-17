#ifndef PLAYER_HPP
#define PLAYER_HPP

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
        private:
            /** @brief Nombre del jugador */
            std::string m_name;

            /** @brief Número de victorias del jugador */
            unsigned int m_wins;

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
             * @brief Obteniene el número de victorias
             * @return Número de victorias
             */
            unsigned int wins() const;
    };
}

#endif // PLAYER_HPP