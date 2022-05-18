#include "chess/pieces/Bishop.hpp"
#include "chess/Movement_validators.hpp"

namespace chess {

Bishop::Bishop(Color color) : APiece{Piece_type::bishop, color} {}

bool Bishop::is_valid_move(const Move& move, const Board& board) const {
    return chess::Movement_validators::is_valid_destination(move, board)
           && chess::Movement_validators::is_valid_diagonal_move(move, board);
}

} // namespace chess