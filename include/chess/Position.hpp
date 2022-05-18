#pragma once

#include <string>

namespace chess {
/**
 * @brief This class is used to validate and transform input string into
 * coordinates on X&Y axis. It is used to store current piece position.
 */
class Position {
public:
    /**
     * @brief Construct Position. Throw invalid_argument exception if conversion
     * is unsuccessful
     * @param input Input string in format "a1" and in range {"a1", "a2" ... "f7", "f8"}
     */
    Position(const std::string& input);

    /**
     * @brief Construct Position. Throw invalid_argument exception if conversion
     * is unsuccessful
     * @param x coord
     * @param y coord
     */
    Position(uint8_t x, uint8_t y);

    Position(const Position&) = delete;
    Position(Position&&) = delete;
    Position& operator=(const Position&) = delete;
    Position& operator=(Position&&) = delete;

    /**
     * @brief Get the value for the x axis
     *
     * @return int x axis value
     */
    uint8_t get_x() const noexcept;

    /**
     * @brief Get the value for the y axis
     *
     * @return int y axis value
     */
    uint8_t get_y() const noexcept;

private:
    /**
     * Check if coordinate is valid
     * @param coord
     * @return true if coord is valid, false otherwise
     */
    static inline bool is_coord_valid(uint8_t coord);

private:
    /**
     * @brief Position on x axis. Valid values are in range 0-7
     *
     */
    uint8_t m_x;

    /**
     * @brief Position on y axis. Valid values are in range 0-7
     *
     */
    uint8_t m_y;
};

} // namespace chess