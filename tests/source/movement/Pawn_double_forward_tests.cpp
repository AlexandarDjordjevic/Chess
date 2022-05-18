#include <gtest/gtest.h>
#include "chess/movement/Pawn_double_move.hpp"

TEST(Pawn_double_forward_test, white_valid_moves) {
    chess::movement::Pawn_double_move pawn{chess::Color::white};
    ASSERT_TRUE(pawn.move_piece({"a2"}, {"a4"}));
}

TEST(Pawn_double_forward_test, white_invalid_moves) {
    chess::movement::Pawn_double_move pawn{chess::Color::white};
    ASSERT_FALSE(pawn.move_piece({"a2"}, {"a5"}));
    ASSERT_FALSE(pawn.move_piece({"a3"}, {"a5"}));
    ASSERT_FALSE(pawn.move_piece({"a4"}, {"a6"}));
}

TEST(Pawn_double_forward_test, black_valid_moves) {
    chess::movement::Pawn_double_move pawn{chess::Color::black};
    ASSERT_TRUE(pawn.move_piece({"a7"}, {"a5"}));
}

TEST(Pawn_double_forward_test, black_invalid_moves) {
    chess::movement::Pawn_double_move pawn{chess::Color::black};
    ASSERT_FALSE(pawn.move_piece({"a7"}, {"a4"}));
    ASSERT_FALSE(pawn.move_piece({"a6"}, {"a4"}));
    ASSERT_FALSE(pawn.move_piece({"a6"}, {"a3"}));
}