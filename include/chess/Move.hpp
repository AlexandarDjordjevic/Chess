#pragma once

#include "chess/Position.hpp"
#include "Common.hpp"
#include <memory>
#include <iostream>

namespace chess {

struct Move {
    Move(const std::string& input, const Color& color);
    std::unique_ptr<Position> start;
    std::unique_ptr<Position> end;
    Color piece_color;
};

[[maybe_unused]] static std::string to_string(const Move& move) {
    return to_string(*move.start) + " -> " + to_string(*move.end);
}

} // namespace chess
