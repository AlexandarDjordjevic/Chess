#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace graphics{

class Bishop {
public:
    static void draw(const std::shared_ptr<sf::RenderWindow>& render_window, float x, float y,
                     bool black);

private:
    Bishop();
    sf::Texture m_black_texture;
    sf::Texture m_white_texture;
};

}


#endif // CHESS_BISHOP_H
