#include "chess/pieces/APiece_movement.hpp"
#include "chess/Move.hpp"
#include "chess/Board.hpp"

namespace chess {

bool APiece_movement::is_valid_move(const Move& move, Board& board) const {
    return std::any_of(m_movements.begin(), m_movements.end(),
                       [&move, &board](auto& m) { return m->is_valid_move(move, board); });
}

} // namespace chess