#include "chess/pieces/Rook.hpp"
#include "chess/Movement_validators.hpp"

namespace chess {

Rook::Rook(Color color) : APiece{Piece_type::rook, color} {}

bool Rook::is_valid_move(const Move& move, const Board& board) const {
    return chess::Movement_validators::is_valid_destination(move, board)
             && chess::Movement_validators::is_valid_horizontal_move(move, board)
           || chess::Movement_validators::is_valid_vertical_move(move, board);
}

} // namespace chess