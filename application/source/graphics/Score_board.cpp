#include "graphics/Score_board.hpp"

namespace graphics {

void Score_board::draw(const std::shared_ptr<sf::RenderWindow>& window) {
    sf::RectangleShape board(sf::Vector2f(600, 900));
    board.setFillColor({186, 140, 99});
    board.setPosition(900, 0);
    board.setOutlineColor(sf::Color::Black);
    board.setOutlineThickness(4);

    sf::Text label_turn;
    sf::Font font;
    font.loadFromFile(
      "/home/syrmia/Documents/work/Chess/application/resources/fonts/Montserrat-SemiBold.ttf");
    label_turn.setString("Turn: ");
    label_turn.setFont(font);
    label_turn.setCharacterSize(30);
    label_turn.setPosition(950, 50);
    window->draw(board);
    window->draw(label_turn);
}

} // namespace graphics