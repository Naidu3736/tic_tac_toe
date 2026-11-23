add_executable(tests_tictactoe
    test_main.cpp
    entities/test_board.cpp
    entities/test_player.cpp
    core/test_game_state.cpp
)

target_link_libraries(tests_tictactoe PRIVATE tictactoe_core)

add_test(NAME TicTacToeTests COMMAND tests_tictactoe)
