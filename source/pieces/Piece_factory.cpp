#include "chess/pieces/Piece_factory.hpp"
#include "chess/pieces/Queen.hpp"
#include "chess/pieces/King.hpp"
#include "chess/pieces/Pawn.hpp"
#include "chess/pieces/Bishop.hpp"
#include "chess/pieces/Rook.hpp"
#include "chess/pieces/Knight.hpp"
#include "chess/Exceptions.hpp"

namespace chess {

std::unique_ptr<APiece> Piece_factory::create(Piece_type type, Color color) {
    switch (type) {
    case Piece_type::queen: {
        return std::make_unique<Queen>(color);
    }
    case Piece_type::king: {
        return std::make_unique<King>(color);
    }
    case Piece_type::pawn: {
        return std::make_unique<Pawn>(color);
    }
    case Piece_type::bishop: {
        return std::make_unique<Bishop>(color);
    }
    case Piece_type::rook: {
        return std::make_unique<Rook>(color);
    }
    case Piece_type::knight: {
        return std::make_unique<Knight>(color);
    }
    default: {
        throw chess::exceptions::Unexpected_state();
    }
    }
}

} // namespace chess
