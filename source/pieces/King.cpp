#include "chess/pieces/King.hpp"

namespace chess {

King::King(Color color) : APiece{Piece_type::king, color} {}

bool King::is_valid_move(const Move& move, const Board& board) const { return {}; }

} // namespace chess