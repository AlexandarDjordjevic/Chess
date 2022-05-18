#include "chess/Move.hpp"
#include "chess/Board.hpp"

namespace chess {
struct Movement_validators {
    /**
     * Check if move is valid diagonal move
     * @param move Move with x and y
     * @param board Chess board reference
     * @return true if move is diagonal, otherwise false
     */
    static bool is_valid_diagonal_move(const Move& move, const Board& board);

    /**
     * Check if move is valid vertical move
     * @param move Move with x and y
     * @param board Chess board reference
     * @return true if move is vertical, otherwise false
     */
    static bool is_valid_vertical_move(const Move& move, const Board& board);

    /**
     * Check if move is valid horizontal move
     * @param move Move with x and y
     * @param board Chess board reference
     * @return true if move is horizontal, otherwise false
     */
    static bool is_valid_horizontal_move(const Move& move, const Board& board);

    /**
     * Check if move destination is valid
     * @param move Move with x and y
     * @param board Chess board reference
     * @return true if destination is valid, otherwise false
     */
    static bool is_valid_destination(const Move& move, const Board& board);

private:
    static std::tuple<uint8_t, uint8_t> get_start_and_end_positions(uint8_t start, uint8_t end);
};

} // namespace chess
