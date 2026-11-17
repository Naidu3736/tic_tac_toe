#include "tictactoe/entities/player.hpp"

namespace naidu {
    Player::Player(std::string_view name)
        : m_name(name)
        , m_wins(0) {}

    void Player::add_wins() {
        m_wins++;
    }

    const std::string& Player::name() const {
        return m_name;
    }

    unsigned int Player::wins() const {
        return m_wins;
    }
}