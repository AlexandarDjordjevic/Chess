#include "graphics/Artist.hpp"
#include "graphics/Pawn.hpp"
#include "graphics/King.hpp"
#include "graphics/Queen.hpp"
#include "graphics/Bishop.hpp"
#include "graphics/Rook.hpp"
#include "graphics/Knight.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace graphics {

Artist::Artist(std::shared_ptr<Resources> resources) : m_resources{resources} {}

void Artist::draw_board(const std::shared_ptr<sf::RenderWindow>&) {}

void Artist::draw_field(const std::shared_ptr<sf::RenderWindow>& window, sf::Color color, size_t x,
                        size_t y) {
    sf::Texture texture;
    sf::Image image;
    sf::Sprite sprite;

    sf::Color painting_color;

    if (color == sf::Color::Black) {
        painting_color = sf::Color(145, 96, 45);
    } else {
        painting_color = sf::Color(237, 213, 192);
    }


    image.create(100, 100, painting_color);
    texture.loadFromImage(image);
    sprite.setPosition(x, y);
    sprite.setTexture(texture);
    window->draw(sprite);
}

void Artist::draw_piece(const std::shared_ptr<sf::RenderWindow>& window, sf::Color color, size_t,
                        size_t) {
    (void)window;
    (void)color;
    //    sf::Texture texture;
    //    sf::Image image;
    //    sf::Sprite sprite;
    //    (void)color;
    //
    //    Rook::draw(window, 60, 60, false);
    //    Knight::draw(window, 160, 60, false);
    //    Bishop::draw(window, 260, 60, false);
    //    King::draw(window, 360, 60, false);
    //    Queen::draw(window, 460, 60, false);
    //    Bishop::draw(window, 560, 60, false);
    //    Knight::draw(window, 660, 60, false);
    //    Rook::draw(window, 760, 60, false);
    //
    //
    //    for (auto x{0}; x < 800; x += 100) {
    //        Pawn::draw(window, 50 + x + 10, 150 + 10, false);
    //    }
    //
    //    Rook::draw(window, 60, 760, true);
    //    Knight::draw(window, 160, 760, true);
    //    Bishop::draw(window, 260, 760, true);
    //    King::draw(window, 360, 760, true);
    //    Queen::draw(window, 460, 760, true);
    //    Bishop::draw(window, 560, 760, true);
    //    Knight::draw(window, 660, 760, true);
    //    Rook::draw(window, 760, 760, true);
    //
    //    for (auto x{0}; x < 800; x += 100) {
    //        Pawn::draw(window, x + 60, 650 + 10, true);
    //    }
}

void Artist::move_piece(const std::shared_ptr<sf::RenderWindow>& window, float, float) {
    (void)window;
    //    Pawn::draw(window, x + 60, 650 + 10, true);
}

} // namespace graphics