#include "graphics/King.hpp"

#define RESOURCES "/home/syrmia/Documents/work/Chess/application/resources/"

namespace graphics {

King::King() {
    m_black_texture.loadFromFile(std::string{RESOURCES} + "images/black_king.png");
    m_white_texture.loadFromFile(std::string{RESOURCES} + "images/white_king.png");
}

void King::draw(const std::shared_ptr<sf::RenderWindow>& render_window, float x, float y,
                bool black) {
    static King king;
    sf::Sprite sprite;
    if (black) {
        sprite.setTexture(king.m_black_texture);
    } else {
        sprite.setTexture(king.m_white_texture);
    }
    sprite.setPosition(x, y);
    render_window->draw(sprite);
}

} // namespace graphics