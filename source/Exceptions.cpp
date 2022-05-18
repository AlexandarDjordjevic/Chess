#include "chess/Exceptions.hpp"

namespace {
const std::string k_color_reset{"\x1B[0m"};
const std::string k_color_red{"\x1B[31m"};

} // namespace


namespace chess::exceptions {

Invalid_move::Invalid_move() noexcept = default;
Invalid_move::Invalid_move(const std::string& msg) noexcept : m_message{msg} {
    m_message = k_color_red + "[Error]: Invalid move. " + msg + k_color_reset;
}
const char* Invalid_move::what() const noexcept { return m_message.c_str(); }

Empty_field_selected::Empty_field_selected() noexcept = default;
Empty_field_selected::Empty_field_selected(const std::string& msg) noexcept : m_message{msg} {
    m_message = k_color_red + "[Error]: Empty field selected. " + msg + k_color_reset;
}

const char* Empty_field_selected::what() const noexcept { return m_message.c_str(); }


Unexpected_state::Unexpected_state() noexcept = default;
Unexpected_state::Unexpected_state(const std::string& msg) noexcept : m_message{msg} {
    m_message = k_color_red + "[Error]: Unexpected program state. " + msg + k_color_reset;
}

const char* Unexpected_state::what() const noexcept { return m_message.c_str(); }

Wrong_piece_selected::Wrong_piece_selected() noexcept = default;
Wrong_piece_selected::Wrong_piece_selected(const std::string& msg) noexcept : m_message{msg} {
    m_message = k_color_red + "[Error]: Invalid piece selected. " + msg + k_color_reset;
}

const char* Wrong_piece_selected::what() const noexcept { return m_message.c_str(); }

} // namespace chess::exceptions