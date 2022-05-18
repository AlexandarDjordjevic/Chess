#pragma once

#include "chess/Position.hpp"
#include "chess/Common.hpp"
#include <optional>

namespace chess {

class ABoard_initializer {
public:
    std::optional<Piece_type> get_piece_type(int x, int y) { return m_data[x][y].first; }

    std::optional<Color> get_piece_color(int x, int y) { return m_data[x][y].second; }

    virtual ~ABoard_initializer() = default;

protected:
    std::pair<std::optional<Piece_type>, std::optional<Color>> m_data[8][8];
};

} // namespace chess
