#include "graphics/Rook.hpp"

#define RESOURCES "/home/syrmia/Documents/work/Chess/application/resources/"

namespace graphics {

Rook::Rook() {
    m_black_texture.loadFromFile(std::string{RESOURCES} + "images/black_rook.png");
    m_white_texture.loadFromFile(std::string{RESOURCES} + "images/white_rook.png");
}

void Rook::draw(const std::shared_ptr<sf::RenderWindow>& render_window, float x, float y,
                bool black) {
    static Rook rook;
    sf::Sprite sprite;
    if (black) {
        sprite.setTexture(rook.m_black_texture);
    } else {
        sprite.setTexture(rook.m_white_texture);
    }
    sprite.setPosition(x, y);
    render_window->draw(sprite);
}

} // namespace graphics