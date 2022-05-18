#include <gtest/gtest.h>
#include "chess/movement/Vertical.hpp"

class MockBoardInitializer : public chess::ABoard_initializer {
public:
    MockBoardInitializer() {
        // Rook at a1 and a8
        m_data[0][0].first = chess::Piece_type::rook;
        m_data[0][0].second = chess::Color::white;
        m_data[0][7].first = chess::Piece_type::rook;
        m_data[0][7].second = chess::Color::white;

        // King at b3 and b8
        m_data[1][2].first = chess::Piece_type::king;
        m_data[1][2].second = chess::Color::white;
        m_data[1][7].first = chess::Piece_type::king;
        m_data[1][7].second = chess::Color::white;

        // Queen at d1 and d7
        m_data[4][0].first = chess::Piece_type::queen;
        m_data[4][0].second = chess::Color::white;
        m_data[4][6].first = chess::Piece_type::queen;
        m_data[4][6].second = chess::Color::white;
    };
};

TEST(Vertical_movement_tests, Move_in_positive_y_direction) {
    chess::movement::Vertical vertical_move;
    chess::Board board{std::make_shared<MockBoardInitializer>()};
    board.initialize();
    // Move rook a1 -> a7
    ASSERT_TRUE(vertical_move.is_valid_move({"a1:a7"}, board));
    // Move king b3 -> b4
    ASSERT_TRUE(vertical_move.is_valid_move({"b3:b4"}, board));
    // Move queen d1 -> d4
    ASSERT_TRUE(vertical_move.is_valid_move({"d1:d4"}, board));
}

TEST(Vertical_movement_tests, Move_in_negative_y_direction) {
    chess::movement::Vertical vertical_move;
    chess::Board board{std::make_shared<MockBoardInitializer>()};
    board.initialize();
    // Move rook a8 -> a2
    ASSERT_TRUE(vertical_move.is_valid_move({"a8:a2"}, board));
    // Move king b3 -> b2
    ASSERT_TRUE(vertical_move.is_valid_move({"b3:b2"}, board));
    // Queen at d7 and d2
    ASSERT_TRUE(vertical_move.is_valid_move({"d7:d2"}, board));
}

TEST(Vertical_movement_tests, Invalid_movement) {
    chess::movement::Vertical vertical_move;
    chess::Board board{std::make_shared<MockBoardInitializer>()};
    board.initialize();
    // Move rook a1 -> a8 (a8 occupied)
    ASSERT_FALSE(vertical_move.is_valid_move({"a1:a8"}, board));
    // Move king b8 -> b1
    ASSERT_FALSE(vertical_move.is_valid_move({"b8:b1"}, board));
}