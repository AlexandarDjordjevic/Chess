#pragma once

#include <thread>
#include <map>
#include "chess/Game.hpp"

namespace chess {
class Chess : public std::thread {
public:

    Chess();
    ~Chess();

    Chess(const Chess&) = delete;
    Chess(Chess&&) = delete;
    Chess& operator=(const Chess&) = delete;
    Chess& operator=(Chess&&) = delete;

    void run();
private:
    /*
     * Prompt and handle user input
     */
    void handle_input();

    /*
     * Resign the game
     */
    void resign();

    /*
     * Restart the game
     */
    void restart();

    /*
     * Quit the game
     */
    void quit();

private:
    /*
     * Worker thread
     */
    std::thread m_thread;

    /*
     * Game is running
     */
    bool m_running{false};

    /*
     * Game logic
     */
    std::unique_ptr<Game> m_game;

    /*
     * List of available commands (quit, restart, resign)
     */
    std::map<std::string, void (Chess::*)()> m_command_list;
};
} // namespace chess