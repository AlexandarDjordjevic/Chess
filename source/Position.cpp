#include "chess/Position.hpp"
#include <stdexcept>

namespace {

/**
 * @brief Length of input string
 *
 */
constexpr auto k_position_string_size{2};

/**
 * @brief This offset is used to convert from "a", "b", .. "h"
 * into coord value (0, 1,...7)
 */
constexpr auto k_normalize_offset_for_x_coord{'a'};

/**
 * @brief X cord position inside the input string
 */
constexpr auto k_x_coord_position{0};

/**
 * @brief This offset is used to convert from "a", "b", .. "h"
 * into coord value (0, 1,...7)
 */
constexpr auto k_normalize_offset_for_y_coord{'1'};

/**
 * @brief Y cord position inside the input string
 */
constexpr auto k_y_coord_position{1};

/**
 * @brief Max coord value, used to detect invalid coordinate input
 *
 */
constexpr auto k_coord_max_val{8};

/**
 * @brief Min coord value, used to detect invalid coordinate input
 *
 */
constexpr auto k_coord_min_val{0};
} // namespace

namespace chess {

inline bool Position::is_coord_valid(const uint8_t coord) {
    return coord >= k_coord_min_val && coord < k_coord_max_val;
}

Position::Position(const std::string& input) {
    auto x{input[k_x_coord_position] - k_normalize_offset_for_x_coord};
    auto y{input[k_y_coord_position] - k_normalize_offset_for_y_coord};


    if (input.length() != k_position_string_size || !is_coord_valid(x) || !is_coord_valid(y)) {
        throw std::invalid_argument("Invalid input position " + input);
    }

    m_x = x;
    m_y = y;
}

Position::Position(uint8_t x, uint8_t y) {
    if (!is_coord_valid(x) || !is_coord_valid(y)) {
        throw std::invalid_argument("Invalid input position");
    }
    m_x = x;
    m_y = y;
}

uint8_t Position::get_x() const noexcept { return m_x; }

uint8_t Position::get_y() const noexcept { return m_y; }

} // namespace chess