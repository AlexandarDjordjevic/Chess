#pragma once

#include "chess/pieces/APiece.hpp"

namespace chess {

class Queen : public APiece {
public:
    /*
     * Construct white/black queen
     */
    explicit Queen(Color color);

    /**
     * Prevent unwanted copy/move operations
     */
    Queen(const Queen& Queen) = delete;
    Queen(Queen&& Queen) = delete;
    Queen& operator=(const Queen& Queen) = delete;
    Queen& operator=(Queen&& Queen) = delete;

    bool is_valid_move(const Move& move, const Board& board) const override;
};

} // namespace chess