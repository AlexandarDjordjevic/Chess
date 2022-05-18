#pragma once

#include "chess/Default_board_initializer.hpp"
#include "chess/Move.hpp"
#include "chess/pieces/APiece.hpp"

#include <memory>

/* _______________________________
 1 |___|___|___|___|___|___|___|___|
 2 |___|___|___|___|___|___|___|___|
 3 |___|___|___|___|___|___|___|___|
 4 |___|___|___|___|___|___|___|___|
 5 |___|___|___|___|___|___|___|___|
 6 |___|___|___|___|___|___|___|___|
 7 |___|___|___|___|___|___|___|___|
 8 |___|___|___|___|___|___|___|___|
     A   B   C   D   E   F   G   H
*/
namespace {
/**
 * Chess board height
 */
constexpr auto k_board_height{8};
/**
 * Chess board width
 */
constexpr auto k_board_width{8};
} // namespace

namespace chess {

class APiece;

class Board {
public:
    Board(const std::shared_ptr<ABoard_initializer>& board_init = nullptr);

    /**
     * Prevent unwanted copy/move operations
     */
    Board(const Board&) = delete;
    Board(Board&&) = delete;
    Board& operator=(const Board&) = delete;
    Board& operator=(Board&&) = delete;

    std::shared_ptr<APiece>& operator[](const Position& position);
    std::shared_ptr<APiece> operator[](const Position& position) const;

    /**
     * Validate and move piece
     * @param move Start + end coords
     * @return
     */
    void move_piece(const Move& move);

private:
    /**
     * Chess board filed matrix
     */
    std::shared_ptr<APiece> m_fields[k_board_height][k_board_width];

    /**
     * Object used to initialize board
     */
    std::shared_ptr<ABoard_initializer> m_board_initializer;
};

} // namespace chess
