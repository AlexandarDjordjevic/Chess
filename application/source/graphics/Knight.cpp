#include "graphics/Knight.hpp"

#define RESOURCES "/home/syrmia/Documents/work/Chess/application/resources/"

namespace graphics {

Knight::Knight() {
    m_black_texture.loadFromFile(std::string{RESOURCES} + "images/black_knight.png");
    m_white_texture.loadFromFile(std::string{RESOURCES} + "images/white_knight.png");
}

void Knight::draw(const std::shared_ptr<sf::RenderWindow>& render_window, float x, float y,
                  bool black) {
    static Knight knight;
    sf::Sprite sprite;
    if (black) {
        sprite.setTexture(knight.m_black_texture);
    } else {
        sprite.setTexture(knight.m_white_texture);
    }
    sprite.setPosition(x, y);
    render_window->draw(sprite);
}

} // namespace graphics