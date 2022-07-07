#ifndef CHESS_KNIGHT_HPP
#define CHESS_KNIGHT_HPP

#include <SFML/Graphics.hpp>
#include <memory>

namespace graphics{

class Knight {
public:
    static void draw(const std::shared_ptr<sf::RenderWindow>& render_window, float x, float y,
                     bool black);

private:
    Knight();
    sf::Texture m_black_texture;
    sf::Texture m_white_texture;
};

}


#endif // CHESS_KNIGHT_HPP
