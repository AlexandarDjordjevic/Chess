#include "graphics/Bishop.hpp"

#define RESOURCES "/home/syrmia/Documents/work/Chess/application/resources/"

namespace graphics {

Bishop::Bishop() {
    m_black_texture.loadFromFile(std::string{RESOURCES} + "images/black_bishop.png");
    m_white_texture.loadFromFile(std::string{RESOURCES} + "images/white_bishop.png");
}

void Bishop::draw(const std::shared_ptr<sf::RenderWindow>& render_window, float x, float y,
                  bool black) {
    static Bishop bishop;
    sf::Sprite sprite;
    if (black) {
        sprite.setTexture(bishop.m_black_texture);
    } else {
        sprite.setTexture(bishop.m_white_texture);
    }
    sprite.setPosition(x, y);
    render_window->draw(sprite);
}

} // namespace graphics