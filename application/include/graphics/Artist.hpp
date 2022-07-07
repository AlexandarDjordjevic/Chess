#ifndef CHESS_DRAWER_HPP
#define CHESS_DRAWER_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "Resources.hpp"

namespace graphics{

class Artist {
public:
    explicit Artist(std::shared_ptr<Resources> resources);

    static void draw_scoreboard(const std::shared_ptr<sf::RenderWindow>& window);
    static void draw_field(const std::shared_ptr<sf::RenderWindow>& window, sf::Color color, size_t x, size_t y);
    static void draw_piece(const std::shared_ptr<sf::RenderWindow>& window, sf::Color color,
                           size_t x, size_t y);
    static void draw_board(const std::shared_ptr<sf::RenderWindow>& window);
    static void move_piece(const std::shared_ptr<sf::RenderWindow>& window, float x, float y);
private:
    std::shared_ptr<Resources> m_resources;
};

}

#endif // CHESS_DRAWER_HPP
