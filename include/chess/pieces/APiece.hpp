#pragma once

#include "chess/Common.hpp"
#include "chess/Move.hpp"
#include "chess/Board.hpp"

#include <memory>
#include <vector>

namespace chess {

class Board;

class APiece {
public:
    /**
     * Abstract piece class
     * @param type Piece type (rook, pawn, queen ...)
     * @param color Piece piece_color (white, black)
     * @param movement_type Piece movement type
     */
    explicit APiece(Piece_type type, chess::Color color);

    /**
     * Default virtual destructor
     */
    virtual ~APiece() = default;

    /**
     * Method used to check if move is valid. Trows exception if move is invalid
     * @param start Start position
     * @param end End position
     */
    virtual bool is_valid_move(const Move& move, const Board& board) const = 0;

    /**
     * Get piece type
     * @return Piece type (check enum Piece_type)
     */
    Piece_type get_type() const;

    /*
     * Get piece piece_color
     * @return Piece piece_color (white or black)
     */
    Color get_color() const;

protected:
    /*
     * Piece current position
     */
    std::unique_ptr<Position> m_position;

    /**
     * Piece type (rook, pawn, bishop...)
     */
    Piece_type m_type;

    /**
     * Piece piece_color (white/black)
     */
    Color m_color;
};

} // namespace chess