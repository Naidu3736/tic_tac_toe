add_library(tictactoe_core)

target_sources(tictactoe_core
    PRIVATE
        core/game_loop.cpp
        core/game_state.cpp
        entities/board.cpp
        entities/player.cpp
        ui/input.cpp
        ui/tui.cpp

    PUBLIC
        FILE_SET HEADERS
        TYPE HEADERS
        BASE_DIRS ${CMAKE_SOURCE_DIR}/include
        FILES
            ${CMAKE_SOURCE_DIR}/include/tictactoe/entities/board.hpp
            ${CMAKE_SOURCE_DIR}/include/tictactoe/entities/player.hpp
            ${CMAKE_SOURCE_DIR}/include/tictactoe/ui/input.hpp
            ${CMAKE_SOURCE_DIR}/include/tictactoe/ui/tui.hpp
            ${CMAKE_SOURCE_DIR}/include/tictactoe/core/game_state.hpp
            ${CMAKE_SOURCE_DIR}/include/tictactoe/core/game_loop.hpp
)