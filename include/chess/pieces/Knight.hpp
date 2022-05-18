#pragma once

#include "chess/pieces/APiece.hpp"

namespace chess {

class Knight : public APiece {
public:
    /*
     * Construct white/black knight
     */
    explicit Knight(Color color);

    /**
     * Prevent unwanted copy/move operations
     */
    Knight(const Knight& Knight) = delete;
    Knight(Knight&& Knight) = delete;
    Knight& operator=(const Knight& Knight) = delete;
    Knight& operator=(Knight&& Knight) = delete;

    bool is_valid_move(const Move& move, const Board& board) const;
};

} // namespace chess