#ifndef CHESS_ROOK_HPP
#define CHESS_ROOK_HPP

#include <SFML/Graphics.hpp>
#include <memory>

namespace graphics{

class Rook {
public:
    static void draw(const std::shared_ptr<sf::RenderWindow>& render_window, float x, float y,
                     bool black);

private:
    Rook();
    sf::Texture m_black_texture;
    sf::Texture m_white_texture;
};

}


#endif // CHESS_ROOK_HPP
