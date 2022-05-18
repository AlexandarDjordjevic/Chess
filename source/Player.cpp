#include "chess/Player.hpp"

namespace chess {

Player::Player(Color color) : m_color{color}, m_checked{false} {}

Color Player::get_color() const { return m_color; }

bool Player::is_checked() const { return m_checked; }

} // namespace chess