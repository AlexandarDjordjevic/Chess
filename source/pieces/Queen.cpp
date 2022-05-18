#include "chess/pieces/Queen.hpp"
#include "chess/Movement_validators.hpp"

namespace chess {

Queen::Queen(Color color) : APiece{Piece_type::queen, color} {}

bool Queen::is_valid_move(const Move& move, const Board& board) const {
    return chess::Movement_validators::is_valid_destination(move, board)
             && chess::Movement_validators::is_valid_horizontal_move(move, board)
           || chess::Movement_validators::is_valid_vertical_move(move, board)
           || chess::Movement_validators::is_valid_diagonal_move(move, board);
}

} // namespace chess