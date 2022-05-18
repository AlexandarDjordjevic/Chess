#include <gtest/gtest.h>
#include "chess/movement/Horizontal.hpp"

TEST(Horizontal_movement_tests, Move_in_positive_x) {
    chess::movement::Horizontal horizontal_movement;
    ASSERT_TRUE(horizontal_movement.move_piece({"a1"}, {"h1"}));
    ASSERT_TRUE(horizontal_movement.move_piece({"a8"}, {"h8"}));
}

TEST(Horizontal_movement_tests, Move_in_negative_x) {
    chess::movement::Horizontal horizontal_movement;
    ASSERT_TRUE(horizontal_movement.move_piece({"h5"}, {"a5"}));
}

TEST(Horizontal_movement_tests, Invalid_horizontal_moves) {
    chess::movement::Horizontal horizontal_movement;
    ASSERT_FALSE(horizontal_movement.move_piece({"a1"}, {"a1"}));
    ASSERT_FALSE(horizontal_movement.move_piece({"h1"}, {"a2"}));
    ASSERT_FALSE(horizontal_movement.move_piece({"b1"}, {"c2"}));
}