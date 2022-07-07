#ifndef CHESS_WINDOW_HPP
#define CHESS_WINDOW_HPP
#include <SFML/Graphics.hpp>

#include "Artist.hpp"
#include "Score_board.hpp"
#include "Resources.hpp"

namespace graphics{

class Window {
public:
    Window();
    void worker();
private:
    std::shared_ptr<sf::RenderWindow> m_window;
    std::shared_ptr<Resources> m_resources;
    std::unique_ptr<Artist> m_artist;
    Score_board m_score_board;
};

}

#endif // CHESS_WINDOW_HPP
