
#include "chess/Board.hpp"
#include "chess/pieces/Piece_factory.hpp"
#include "chess/Exceptions.hpp"

namespace chess {

class APiece;

Board::Board(const std::shared_ptr<ABoard_initializer>& board_initializer)
    : m_board_initializer{board_initializer ? board_initializer
                                            : std::make_shared<Default_board_initializer>()} {
    for (auto y{0}; y < k_board_height; ++y) {
        for (auto x{0}; x < k_board_width; ++x) {
            if (m_board_initializer->get_piece_type(x, y).has_value()
                && m_board_initializer->get_piece_color(x, y).has_value()) {
                m_fields[x][y] =
                  Piece_factory::create(m_board_initializer->get_piece_type(x, y).value(),
                                        m_board_initializer->get_piece_color(x, y).value());
            } else {
                m_fields[x][y].reset();
            }
        }
    }
}

std::shared_ptr<APiece>& Board::operator[](const Position& position) {
    return m_fields[position.get_x()][position.get_y()];
}

std::shared_ptr<APiece> Board::operator[](const Position& position) const {
    return m_fields[position.get_x()][position.get_y()];
}

void Board::move_piece(const Move& move) {
    auto piece{(*this)[*move.start]};
    if (piece == nullptr) {
        throw exceptions::Invalid_move();
    }

    if (piece->get_color() != move.piece_color) {
        throw exceptions::Wrong_piece_selected();
    }

    if (move.start == move.end) {
        throw exceptions::Invalid_move("Start position == End position");
    }

    if (!piece->is_valid_move(move, *this)) {
        throw exceptions::Invalid_move();
    }

    m_fields[move.end->get_x()][move.end->get_y()] =
      m_fields[move.start->get_x()][move.start->get_y()];
    m_fields[move.start->get_x()][move.start->get_y()].reset();
}

} // namespace chess