#pragma once

#include "chess/pieces/APiece.hpp"

namespace chess {

class Rook : public APiece {
public:
    /*
     * Construct white/black rook
     */
    explicit Rook(Color color);

    /**
     * Prevent unwanted copy/move operations
     */
    Rook(const Rook& Rook) = delete;
    Rook(Rook&& Rook) = delete;
    Rook& operator=(const Rook& Rook) = delete;
    Rook& operator=(Rook&& Rook) = delete;

    bool is_valid_move(const Move& move, const Board& board) const override;

private:
};


} // namespace chess