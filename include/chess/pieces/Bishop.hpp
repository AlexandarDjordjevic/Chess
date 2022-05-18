#pragma once

#include "chess/pieces/APiece.hpp"
#include "chess/Board.hpp"

namespace chess {

/**
 * Bishop implementation
 */
class Bishop : public APiece {
public:
    /*
     * Construct white/black bishop
     */
    explicit Bishop(Color color);

    /**
     * Prevent unwanted copy/move operations
     */
    Bishop(const Bishop& bishop) = delete;
    Bishop(Bishop&& bishop) = delete;
    Bishop& operator=(const Bishop& bishop) = delete;
    Bishop& operator=(Bishop&& bishop) = delete;

    bool is_valid_move(const Move& move, const Board& board) const override;
};


} // namespace chess