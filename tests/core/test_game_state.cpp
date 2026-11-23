#include "tictactoe/core/game_state.hpp"
#include "tictactoe/entities/board.hpp"

#include <doctest/doctest.h>
#include <cstddef>
#include <initializer_list>

namespace {

    // Ejecuta una secuencia de movimientos alternando jugadores
    void play_moves(naidu::GameState &game_state, std::initializer_list<std::size_t> moves) {
        for (const auto move : moves)
            game_state.make_move(move);
    }

    bool check_empty_board(const naidu::Board &board) {
        for (std::size_t i = 0; i < board.size(); ++i)
            if (board[i] != naidu::State::Empty)
                return false;

        return true;
    }

}

TEST_CASE("GameState: Constructor con nombres de jugadores") {
    naidu::GameState game_state{"player1", "player2"};

    CHECK_EQ(game_state.current_player().name(), "player1");
    CHECK(check_empty_board(game_state.board()));
    CHECK_EQ(game_state.round(), 1);
    CHECK_EQ(game_state.status(), naidu::Status::IN_PROGRESS);
}

TEST_CASE("GameState: Verificar que current_player() devuelve el jugador actual") {
    naidu::GameState game_state{"player1", "player2"};

    CHECK_EQ(game_state.current_player().name(), "player1");

    game_state.make_move(0);
    CHECK_EQ(game_state.current_player().name(), "player2");
}

TEST_CASE("GameState: Verificar que board() devuelva el estado actual del tablero") {
    naidu::GameState game_state{"player1", "player2"};

    // Debe reflejar los cambios posteriores
    const auto &board = game_state.board();
    CHECK(check_empty_board(board));

    auto current_player = game_state.current_player();
    game_state.make_move(0);
    CHECK_EQ(board[0], *current_player.symbol());
}

TEST_CASE("GameState: Verificar que round() devuelva la ronda actual") {
    naidu::GameState game_state{"player1", "player2"};

    CHECK_EQ(game_state.round(), 1);

    game_state.make_move(0);
    CHECK_EQ(game_state.round(), 2);

    game_state.make_move(1);
    CHECK_EQ(game_state.round(), 3);
}

TEST_CASE("GameState: Verificar todos los estados posibles de la partida") {
    SUBCASE("Estado inicial debe ser IN_PROGRESS") {
        naidu::GameState game_state{"player1", "player2"};

        CHECK_EQ(game_state.status(), naidu::Status::IN_PROGRESS);
    }

    SUBCASE("Debe retornar PLAYER1_WINNER si O gana por fila") {
        naidu::GameState game_state{"player1", "player2"};

        // O O O
        // X X .
        // . . .
        play_moves(game_state, {0, 3, 1, 4, 2});

        CHECK_EQ(game_state.status(), naidu::Status::PLAYER1_WINNER);
    }

    SUBCASE("Debe retornar PLAYER2_WINNER si X gana por fila") {
        naidu::GameState game_state{"player1", "player2"};

        // O O .
        // X X X
        // . . O
        play_moves(game_state, {0, 3, 1, 4, 8, 5});

        CHECK_EQ(game_state.status(), naidu::Status::PLAYER2_WINNER);
    }

    SUBCASE("Debe retornar PLAYER1_WINNER si O gana por columna") {
        naidu::GameState game_state{"player1", "player2"};

        // O X .
        // O X .
        // O . .
        play_moves(game_state, {0, 1, 3, 4, 6});

        CHECK_EQ(game_state.status(), naidu::Status::PLAYER1_WINNER);
    }

    SUBCASE("Debe retornar PLAYER1_WINNER si O gana por diagonal") {
        naidu::GameState game_state{"player1", "player2"};

        // O X .
        // . O X
        // . . O
        play_moves(game_state, {0, 1, 4, 5, 8});

        CHECK_EQ(game_state.status(), naidu::Status::PLAYER1_WINNER);
    }

    SUBCASE("Debe retornar IN_PROGRESS a mitad de partida") {
        naidu::GameState game_state{"player1", "player2"};

        // O . .
        // . X .
        // . . .
        play_moves(game_state, {0, 4});

        CHECK_EQ(game_state.status(), naidu::Status::IN_PROGRESS);
    }

    SUBCASE("Debe retornar TIE si el tablero se llena sin ganador") {
        naidu::GameState game_state{"player1", "player2"};

        // O X O
        // O X X
        // X O O
        play_moves(
            game_state,
            {0, 1, 2, 4, 3, 5, 7, 6, 8}
        );

        CHECK_EQ(game_state.status(), naidu::Status::TIE);
    }
}

TEST_CASE("GameState: Verificar que make_move() actualice el estado global correctamente") {
    naidu::GameState game_state{"player1", "player2"};

    auto previous_player = game_state.current_player();
    CHECK(game_state.make_move(0));

    auto current_player = game_state.current_player();
    CHECK_EQ(game_state.round(), 2);
    CHECK_NE(previous_player, current_player);

    // Casilla ocupada el movimiento se rechaza
    CHECK_FALSE(game_state.make_move(0));
}

TEST_CASE("GameState: Verificar que reset() solo reinicia el tablero y el número de rondas") {
    naidu::GameState game_state{"player1", "player2"};

    // Tras 3 jugadas le toca a player2
    play_moves(game_state, {0, 1, 2});
    CHECK_EQ(game_state.round(), 4);
    CHECK_EQ(game_state.current_player().name(), "player2");

    game_state.reset();

    CHECK(check_empty_board(game_state.board()));
    CHECK_EQ(game_state.round(), 1);
    CHECK_EQ(game_state.status(), naidu::Status::IN_PROGRESS);

    // reset() no reinicia el turno
    CHECK_EQ(game_state.current_player().name(), "player2");

    // Las casillas usadas antes vuelven a estar libres
    CHECK(game_state.make_move(0));
}