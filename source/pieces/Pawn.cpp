#include "chess/pieces/Pawn.hpp"

namespace chess {

Pawn::Pawn(Color color) : APiece{Piece_type::pawn, color} {}

bool Pawn::is_valid_move(const Move& move, const Board& board) const { return {}; }


} // namespace chess