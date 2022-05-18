#pragma once

#include "chess/Position.hpp"
#include "Common.hpp"
#include <memory>

namespace chess {

struct Move {
    Move(const std::string& input, const Color& color);
    std::unique_ptr<Position> start;
    std::unique_ptr<Position> end;
    Color piece_color;
};

} // namespace chess
