#ifndef CHESS_IPEACE_HPP
#define CHESS_IPEACE_HPP

#include "chess/Common.hpp"

namespace chess {
class IPiece {
public:
    virtual Piece_type get_type() const = 0;

    virtual Color get_color() const = 0;

    virtual ~IPiece() = default;
};
} // namespace chess

#endif // CHESS_IPEACE_HPP
