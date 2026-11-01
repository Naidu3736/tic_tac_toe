#ifndef UI_HPP
#define UI_HPP

#include "game_state.hpp"

namespace naidu {
    class Ui {
        public:
            void clear_screen() const;

            void show_title() const;

            void show_state(const GameState &state) const;

            void show_info(const GameState &state) const;

            void show_current_player(const GameState &state) const;

            void show_table(const GameState &state) const;
    };
}

#endif // UI_HPP