#include "tictactoe/entities/player.hpp"
#include <optional>

namespace naidu {

    Player::Player(std::string_view name)
        : m_name(name)
        , m_symbol(std::nullopt)
        , m_wins(0) {}

    void Player::add_wins() {
        m_wins++;
    }

    const std::string& Player::name() const {
        return m_name;
    }

    std::optional<State> Player::symbol() const {
        return m_symbol;
    }

    void Player::set_symbol(State symbol) {
        m_symbol = symbol;
    }

    unsigned int Player::wins() const {
        return m_wins;
    }

    bool Player::operator==(const Player &other) const {
        if (this == &other)
            return true;

        return m_name == other.name();
    }
 
    bool Player::operator!=(const Player &other) const {
        return !(*this == other);
    }

}