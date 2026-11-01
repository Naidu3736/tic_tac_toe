#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <cstddef>

namespace naidu {
    /**
     * @enum State
     * @brief Representa el contenido de una celda.
     * @details Indica el estado actual de una celda.
     *          Se usa para determinar si una celda esta vacía o 
     *          marcada por un jugador.
     */
    enum class State {
        Empty, /**< Celda vacía */
        X, /**< Celda con símbolo X */
        O, /**< Celda con símbolo O */
    };

    /**
     * @class Board
     * @brief Representa el tablero 3x3 del juego.
     * @details Almacena el estado de cada celda ('X', 'O' o vacío),
     *          además de consultar y modificar el estado durante
     *          la partida.
     * @date 26-08-2026
     * @version 2.0
     */
    class Board {
        private:
            /** @brief Tablero de NxN celdas */
            std::vector<State> m_board;

        public:
            /** 
             * @brief Constructor que incializa el tablero
             *        con todas sus celdas vacias  .
             */
            Board();

            /**
             * @brief Accede al estado de una celda.
             * @param index Posición de la celda en el tablero.
             * @return Estado de la celda en la posición indicada.
             */
            State& operator[](std::size_t index);

            /**
             * @brief Accede al estado de una celda en modo lectura.
             * @param index Posición de la celda en el tablero.
             * @return Estado de la celda en modo lectura en la posición.
             *         indicada
             */
            const State& operator[](std::size_t index) const;

            /**
             * @brief Obtener el número total de celdas del tablero.
             * @return Tamaño del tablero (9);
             */
            std::size_t size() const;

            /**
             * @brief Vaciar todas las celdas del tablero.
             */
            void clear();
    };
}

#endif // BOARD_HPP