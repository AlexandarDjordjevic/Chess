#include "chess/Game.hpp"
#include "chess/Move.hpp"
#include <string>
#include <iostream>

namespace {
/*
 * Input move string length. Input example a1:a4
 */
constexpr auto k_input_move_string_len{5};

/*
 * White player position in player array
 */
constexpr auto k_white_player_position{0};

/*
 * Black player position in player array
 */
constexpr auto k_black_player_position{1};
} // namespace

namespace chess {

Game::Game()
    : m_players{std::make_shared<Player>(Color::white), std::make_shared<Player>(Color::black)},
      m_active_player{m_players[k_white_player_position]} {}

void Game::change_turn() {
    m_active_player = m_active_player->get_color() == Color::white
                        ? m_players[k_black_player_position]
                        : m_players[k_white_player_position];
}

std::string Game::get_player_turn_color() const { return to_string(m_active_player->get_color()); }

void Game::update_game_state(const std::string& input) {
    const auto move{Move(input, m_active_player->get_color())};

    m_board.move_piece(move);
    change_turn();
}

} // namespace chess