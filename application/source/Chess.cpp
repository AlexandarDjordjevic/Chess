#include "../include/Chess.hpp"
#include "chess/Exceptions.hpp"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

namespace chess {

Chess::Chess() : m_running{true}, m_game{std::make_unique<Game>()} {
    m_command_list.emplace("quit", &Chess::quit);
    m_command_list.emplace("restart", &Chess::restart);
    m_command_list.emplace("resign", &Chess::resign);
}

void Chess::run() {
    m_thread = std::thread([&]() {
        while (m_running) {
            handle_input();
        }
    });
}

Chess::~Chess() { m_thread.join(); }

void Chess::handle_input() {
    std::string input;
    std::cout << "[" << m_game->get_player_turn_color() << "]: ";
    std::cin >> input;

    if (m_command_list.contains(input)) {
        (this->*m_command_list[input])();
    } else {
        try {
            m_game->update_game_state(input);
        } catch (const std::exception& e) { std::cout << e.what() << std::endl; }
    }
}

void Chess::resign() {
    std::cout << "[" << m_game->get_player_turn_color() << " resign the game!]" << std::endl;
    m_running = false;
}

void Chess::restart() { m_game.reset(); }

void Chess::quit() {
    std::cout << "[Game over!]" << std::endl;
    m_running = false;
}

} // namespace chess