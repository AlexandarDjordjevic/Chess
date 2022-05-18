#include <gtest/gtest.h>
#include "chess/movement/Pawn_regular.hpp"

TEST(Pawn_single_forward_test, white_valid_moves) {
    chess::movement::Pawn_regular pawn{chess::Color::white};
    ASSERT_TRUE(pawn.move_piece({"a2"}, {"a3"}));
}

TEST(Pawn_single_forward_test, white_invalid_moves) {
    chess::movement::Pawn_regular pawn{chess::Color::white};
    ASSERT_FALSE(pawn.move_piece({"a2"}, {"a4"}));
}

TEST(Pawn_single_forward_test, black_valid_moves) {
    chess::movement::Pawn_regular pawn{chess::Color::black};
    ASSERT_TRUE(pawn.move_piece({"a7"}, {"a6"}));
}

TEST(Pawn_single_forward_test, black_invalid_moves) {
    chess::movement::Pawn_regular pawn{chess::Color::black};
    ASSERT_FALSE(pawn.move_piece({"a7"}, {"a5"}));
}