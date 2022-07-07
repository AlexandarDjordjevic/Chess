#include "chess/pieces/Pawn.hpp"
#include "chess/Movement_validators.hpp"

namespace chess {

Pawn::Pawn(Color color) : APiece{Piece_type::pawn, color} {}

bool Pawn::is_valid_move(const Move& move, const Board& board) const {
    return chess::Movement_validators::is_valid_destination(move, board)
           && chess::Movement_validators::is_valid_vertical_move(move, board);
}


} // namespace chess