#include <gtest/gtest.h>
#include "chess/movement/Diagonal.hpp"

TEST(Diagonal_movement_tests, Move_in_first_quadrant_direction) {
    chess::movement::Diagonal diagonal_move;
    ASSERT_TRUE(diagonal_move.move_piece({"a1"}, {"c3"}));
    ASSERT_TRUE(diagonal_move.move_piece({"d2"}, {"g5"}));
    ASSERT_TRUE(diagonal_move.move_piece({"a1"}, {"h8"}));

    ASSERT_FALSE(diagonal_move.move_piece({"a2"}, {"b4"}));
}

TEST(Diagonal_movement_tests, Move_in_second_quadrant_direction) {
    chess::movement::Diagonal diagonal_move;
    ASSERT_TRUE(diagonal_move.move_piece({"h1"}, {"a8"}));
    ASSERT_TRUE(diagonal_move.move_piece({"g2"}, {"c6"}));
    ASSERT_TRUE(diagonal_move.move_piece({"h4"}, {"d8"}));

    ASSERT_FALSE(diagonal_move.move_piece({"h1"}, {"a7"}));
}

TEST(Diagonal_movement_tests, Move_in_third_quadrant_direction) {
    chess::movement::Diagonal diagonal_move;
    ASSERT_TRUE(diagonal_move.move_piece({"h8"}, {"a1"}));
    ASSERT_TRUE(diagonal_move.move_piece({"g6"}, {"c2"}));
    ASSERT_TRUE(diagonal_move.move_piece({"h8"}, {"d4"}));

    ASSERT_FALSE(diagonal_move.move_piece({"h7"}, {"a1"}));
}

TEST(Diagonal_movement_tests, Move_in_fourth_quadrant_direction) {
    chess::movement::Diagonal diagonal_move;
    ASSERT_TRUE(diagonal_move.move_piece({"a8"}, {"h1"}));
    ASSERT_TRUE(diagonal_move.move_piece({"c6"}, {"g2"}));
    ASSERT_TRUE(diagonal_move.move_piece({"d8"}, {"h4"}));

    ASSERT_FALSE(diagonal_move.move_piece({"a7"}, {"h1"}));
}