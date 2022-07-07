#ifndef CHESS_KING_H
#define CHESS_KING_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace graphics{

class King {
public:
    static void draw(const std::shared_ptr<sf::RenderWindow>& render_window, float x, float y,
                     bool black);

private:
    King();
    sf::Texture m_black_texture;
    sf::Texture m_white_texture;
};

}


#endif // CHESS_KING_H
