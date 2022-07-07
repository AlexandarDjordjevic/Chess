#pragma once

#include <string>

namespace chess {

/**
 * Piece types
 */
enum class Piece_type { pawn, rook, knight, bishop, queen, king };

/**
 * Players and peaces colors
 */
enum class Color { white, black };

/**
 * Get color as string
 * @param color
 * @return string Color (white or black)
 */
[[maybe_unused]] static std::string to_string(Color color) {
    return color == Color::white ? "White" : "Black";
}

} // namespace chess
