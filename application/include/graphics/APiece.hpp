#ifndef CHESS_APIECE_HPP
#define CHESS_APIECE_HPP

#include <SFML/Graphics.hpp>
#include <chess/Common.hpp>
#include <memory>
#include "Resources.hpp"

namespace graphics{

class APiece{
public:
    explicit APiece(const std::shared_ptr<sf::RenderWindow> render_window,
                    std::shared_ptr<Resources> resources,
                    chess::Piece_type,
                    chess::Color);
    void draw(float x, float y);
    void move(float x, float y);
private:
    std::shared_ptr<sf::RenderWindow> m_render_window;
    std::shared_ptr<Resources> m_resources;
    sf::Sprite m_sprite;
    chess::Piece_type m_type;
    chess::Color m_color;
};

}

#endif // CHESS_APIECE_HPP
