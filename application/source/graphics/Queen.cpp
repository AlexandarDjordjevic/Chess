#include "graphics/Queen.hpp"

#define RESOURCES "/home/syrmia/Documents/work/Chess/application/resources/"

namespace graphics {

Queen::Queen() {
    m_black_texture.loadFromFile(std::string{RESOURCES} + "images/black_queen.png");
    m_white_texture.loadFromFile(std::string{RESOURCES} + "images/white_queen.png");
}

void Queen::draw(const std::shared_ptr<sf::RenderWindow>& render_window, float x, float y,
                 bool black) {
    static Queen queen;
    sf::Sprite sprite;
    if (black) {
        sprite.setTexture(queen.m_black_texture);
    } else {
        sprite.setTexture(queen.m_white_texture);
    }
    sprite.setPosition(x, y);
    render_window->draw(sprite);
}

} // namespace graphics