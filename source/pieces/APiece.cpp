#include "chess/pieces/APiece.hpp"
#include "chess/Board.hpp"

namespace chess {

class Board;

APiece::APiece(Piece_type type, chess::Color color) : m_type{type}, m_color{color} {}

Piece_type APiece::get_type() const { return m_type; }

Color APiece::get_color() const { return m_color; }

} // namespace chess