#ifndef CHESS_SCORE_BOARD_H
#define CHESS_SCORE_BOARD_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace graphics {

class Score_board {
public:
    Score_board() = default;
    void draw(const std::shared_ptr<sf::RenderWindow>& window);
};

}

#endif // CHESS_SCORE_BOARD_H
