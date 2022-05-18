#pragma once

#include "chess/pieces/APiece.hpp"

namespace chess {

class King : public APiece {
public:
    /*
     * Construct white/black king
     */
    explicit King(Color color);

    /**
     * Prevent unwanted copy/move operations
     */
    King(const King& King) = delete;
    King(King&& King) = delete;
    King& operator=(const King& King) = delete;
    King& operator=(King&& King) = delete;

    bool is_valid_move(const Move& move, const Board& board) const;
};

} // namespace chess