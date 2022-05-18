#pragma once

#include "chess/pieces/APiece.hpp"

namespace chess {

class Pawn : public APiece {
public:
    /*
     * Construct white/black pawn
     */
    explicit Pawn(Color color);

    /**
     * Prevent unwanted copy/move operations
     */
    Pawn(const Pawn& Pawn) = delete;
    Pawn(Pawn&& Pawn) = delete;
    Pawn& operator=(const Pawn& Pawn) = delete;
    Pawn& operator=(Pawn&& Pawn) = delete;

    bool is_valid_move(const Move& move, const Board& board) const;
};

} // namespace chess