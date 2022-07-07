#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace graphics{

class Queen {
public:
    static void draw(const std::shared_ptr<sf::RenderWindow>& render_window, float x, float y,
                     bool black);

private:
    Queen();
    sf::Texture m_black_texture;
    sf::Texture m_white_texture;
};

}


#endif // CHESS_QUEEN_H
