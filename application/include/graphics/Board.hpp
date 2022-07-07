#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include "graphics/Pawn.hpp"
#include "Resources.hpp"
#include <array>

namespace graphics{

class Board{
public:
    struct Piece_set{
        std::array<Pawn, 8> pawns;
    };
    Board(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Resources> resources);

    void draw();

private:
    void draw_fields();
    void draw_side_marks();
private:
    std::shared_ptr<Piece_set> black_set;
    std::shared_ptr<Piece_set> white_set;
    std::shared_ptr<sf::RenderWindow> m_window;
    std::shared_ptr<Resources> m_resources;
};

}

#endif // CHESS_BOARD_HPP
