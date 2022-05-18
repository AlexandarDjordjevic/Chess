#pragma once

#include "chess/pieces/APiece.hpp"
#include <memory>

namespace chess {

/**
 * Factory used to create pieces
 */
class Piece_factory {
private:
public:
    /**
     * Create desired piece
     * @param type Piece type
     * @param color Color
     * @return Pointer to piece
     */
    static std::unique_ptr<APiece> create(Piece_type type, Color color);
};

} // namespace chess
