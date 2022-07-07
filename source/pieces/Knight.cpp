#include "chess/pieces/Knight.hpp"

namespace chess {

Knight::Knight(Color color) : APiece{Piece_type::knight, color} {}

bool Knight::is_valid_move(const Move& move, const Board& board) const {
    (void)move;
    (void)board;
    return {};
}

} // namespace chess