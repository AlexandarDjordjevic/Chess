#include "chess/Movement_validators.hpp"

namespace chess {

bool Movement_validators::is_valid_diagonal_move(const Move& move, const Board& board) {
    if (std::abs(move.start->get_x() - move.end->get_x())
        != std::abs(move.start->get_y() - move.end->get_y())) {
        return false;
    }

    const auto num_of_fields_to_check{std::abs(move.start->get_x() - move.end->get_x()) - 1};

    std::vector<uint8_t> x_coords(num_of_fields_to_check);
    std::vector<uint8_t> y_coords(num_of_fields_to_check);
    std::generate(x_coords.begin(), x_coords.end(), [n = move.start->get_x(), &move]() mutable {
        if (move.start->get_x() > move.end->get_x()) {
            return --n;
        }
        return ++n;
    });

    std::generate(y_coords.begin(), y_coords.end(), [n = move.start->get_y(), &move]() mutable {
        if (move.start->get_y() > move.end->get_y()) {
            return --n;
        }
        return ++n;
    });

    for (auto i{0}; i < num_of_fields_to_check; ++i) {
        if (board[{x_coords[i], y_coords[i]}]) {
            return false;
        }
    }

    return true;
}

std::tuple<uint8_t, uint8_t> Movement_validators::get_start_and_end_positions(uint8_t start,
                                                                              uint8_t end) {
    return (start > end) ? std::pair<int, int>{end, start - 1}
                         : std::pair<int, int>{start + 1, end};
}


bool Movement_validators::is_valid_vertical_move(const Move& move, const Board& board) {
    if (move.start->get_x() != move.end->get_x()) {
        return false;
    }
    const auto x{move.start->get_x()};
    uint8_t y_start{0};
    uint8_t y_end{0};

    std::tie(y_start, y_end) = get_start_and_end_positions(move.start->get_y(), move.end->get_y());

    // check if destination contains figure with same piece_color
    if (board[{x, y_end}] && board[{x, y_end}]->get_color() == move.piece_color) {
        return false;
    }

    for (auto y{y_start}; y < y_end; ++y) {
        if (board[{x, y}]) {
            return false;
        }
    }
    return true;
}

bool Movement_validators::is_valid_horizontal_move(const Move& move, const Board& board) {
    if (move.start->get_y() != move.end->get_y()) {
        return false;
    }
    const auto y{move.start->get_y()};
    uint8_t x_start{0};
    uint8_t x_end{0};

    std::tie(x_start, x_end) = get_start_and_end_positions(move.start->get_x(), move.end->get_x());

    // check if destination contains figure with same piece_color
    if (board[{x_end, y}] && board[{x_end, y}]->get_color() == move.piece_color) {
        return false;
    }

    for (auto x{x_start}; x < x_end; ++x) {
        if (board[{x, y}]) {
            return false;
        }
    }
    return true;
}

bool Movement_validators::is_valid_destination(const Move& move, const Board& board) {
    // check if destination contains figure with the same piece_color
    if (board[{move.end->get_x(), move.end->get_y()}]
        && board[{move.end->get_x(), move.end->get_y()}]->get_color() == move.piece_color) {
        return false;
    }
    return true;
}

} // namespace chess
