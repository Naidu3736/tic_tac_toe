add_executable(tests_tictactoe test_main.cpp)

target_link_libraries(tests_tictactoe PRIVATE tictactoe_core)

add_test(NAME TicTacToeTests COMMAND tests_tictactoe)