#pragma once

#include "chess/Player.hpp"
#include "chess/Board.hpp"
#include <thread>
#include <functional>
#include <map>

namespace chess {
class Game {
public:
    Game();
    ~Game() = default;

    Game(const Game&) = delete;
    Game(Game&&) = delete;
    Game& operator=(const Game&) = delete;
    Game& operator=(Game&&) = delete;

    std::string get_player_turn_color() const;
    void update_game_state(const std::string& input);

private:
    /*
     * Switch turn from black to white and vice versa
     */
    void change_turn();

private:
    /*
     * Array of players
     */
    std::array<std::shared_ptr<Player>, 2> m_players;

    /*
     * Current player with turn to play
     */
    std::shared_ptr<Player> m_active_player;

    /*
     * Chess board
     */
    Board m_board;

    /*
     * Map with available commands
     */
    std::map<std::string, void (Game::*)()> m_command_list;
};
} // namespace chess