#ifndef CHESS_IARTIST_HPP
#define CHESS_IARTIST_HPP

#include "chess/Common.hpp"
#include "chess/Position.hpp"
#include "chess/pieces/IPeace.hpp"

namespace chess {

class IArtist {
public:
    virtual void draw_field(const Position& position) = 0;

    virtual void draw_piece(const Position& position, const IPiece* piece) = 0;

    virtual ~IArtist() = default;
};

} // namespace chess


#endif // CHESS_IARTIST_HPP
