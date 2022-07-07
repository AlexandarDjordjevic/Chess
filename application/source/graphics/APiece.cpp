#include "graphics/APiece.hpp"

namespace graphics{

APiece::APiece(const std::shared_ptr<sf::RenderWindow> render_window,
               std::shared_ptr<Resources> resources,
               chess::Piece_type type,
               chess::Color color)
    : m_render_window{render_window}, m_resources{resources}, m_type{type}, m_color{color} {}

void APiece::draw(float x, float y) {
    auto texture{m_color == chess::Color::white ? m_resources->textures. }
    m_sprite.setTexture(*m_texture);
    m_sprite.setPosition(x, y);
    m_render_window->draw(m_sprite);
}

void APiece::move(float x, float y) {
    m_sprite.setPosition(x, y);
    m_render_window->draw(m_sprite);
}

}
