#include <gtest/gtest.h>
#include "chess/Board.hpp"
#include "chess/pieces/Piece_factory.hpp"
#include "chess/Exceptions.hpp"


class Rook_movement : public testing::Test {
    class Test_board_init : public chess::ABoard_initializer {
    public:
        Test_board_init() = default;
    };

public:
    chess::Board board{std::make_shared<Test_board_init>()};
};

TEST_F(Rook_movement, illegal_diagonal_move) {
    board[{"a1"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);
    ASSERT_THROW(board.move_piece({"a1:c7", chess::Color::white}), chess::exceptions::Invalid_move);
    ASSERT_NE(board[{"a1"}], nullptr);
}

TEST_F(Rook_movement, valid_vertical_move) {
    board[{"a1"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);
    ASSERT_NE(board[{"a1"}], nullptr);
    ASSERT_NO_THROW(board.move_piece({"a1:a7", chess::Color::white}));
    ASSERT_EQ(board[{"a1"}], nullptr);
    ASSERT_NE(board[{"a7"}], nullptr);

    ASSERT_NO_THROW(board.move_piece({"a7:a1", chess::Color::white}));
    ASSERT_EQ(board[{"a7"}], nullptr);
    ASSERT_NE(board[{"a1"}], nullptr);
}

TEST_F(Rook_movement, vertical_move_destination_occupied_with_ally) {
    board[{"a1"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);
    board[{"a7"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);

    ASSERT_THROW(board.move_piece({"a1:a7", chess::Color::white}), chess::exceptions::Invalid_move);
    ASSERT_NE(board[{"a1"}], nullptr);
    ASSERT_NE(board[{"a7"}], nullptr);
}

TEST_F(Rook_movement, vertical_move_with_ally_figure_between_start_and_end) {
    board[{"c1"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);
    board[{"c4"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);

    ASSERT_THROW(board.move_piece({"c1:c7", chess::Color::white}), chess::exceptions::Invalid_move);
    ASSERT_NE(board[{"c1"}], nullptr);
    ASSERT_NE(board[{"c4"}], nullptr);
}

TEST_F(Rook_movement, vertical_move_with_enemy_figure_between_start_and_end) {
    board[{"d1"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);
    board[{"d2"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::black);

    ASSERT_THROW(board.move_piece({"d1:d5", chess::Color::white}), chess::exceptions::Invalid_move);
    ASSERT_NE(board[{"d1"}], nullptr);
    ASSERT_NE(board[{"d2"}], nullptr);
    ASSERT_EQ(board[{"d5"}], nullptr);
}

TEST_F(Rook_movement, vertical_move_kill_black_enemy_figure) {
    board[{"a1"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);
    board[{"a4"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::black);

    ASSERT_NO_THROW(board.move_piece({"a1:a4", chess::Color::white}));
    ASSERT_EQ(board[{"a1"}], nullptr);
    ASSERT_NE(board[{"a4"}], nullptr);
    ASSERT_EQ(board[{"a4"}]->get_color(), chess::Color::white);
}

TEST_F(Rook_movement, vertical_move_kill_white_enemy_figure) {
    board[{"a8"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::black);
    board[{"a4"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);

    ASSERT_NO_THROW(board.move_piece({"a8:a4", chess::Color::black}));
    ASSERT_EQ(board[{"a8"}], nullptr);
    ASSERT_NE(board[{"a4"}], nullptr);
    ASSERT_EQ(board[{"a4"}]->get_color(), chess::Color::black);
}

TEST_F(Rook_movement, valid_horizontal_move) {
    board[{"f3"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);
    ASSERT_NE(board[{"f3"}], nullptr);
    ASSERT_NO_THROW(board.move_piece({"f3:a3", chess::Color::white}));
    ASSERT_NE(board[{"a3"}], nullptr);
    ASSERT_EQ(board[{"f3"}], nullptr);
}

TEST_F(Rook_movement, horizontal_move_destination_occupied_with_ally_figure) {
    board[{"b1"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);
    board[{"f1"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);

    ASSERT_THROW(board.move_piece({"b1:f1", chess::Color::white}), chess::exceptions::Invalid_move);
    ASSERT_NE(board[{"b1"}], nullptr);
    ASSERT_NE(board[{"f1"}], nullptr);
}

TEST_F(Rook_movement, horizontal_move_with_ally_figure_between_start_and_end) {
    board[{"a1"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);
    board[{"c1"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);

    ASSERT_THROW(board.move_piece({"a1:e1", chess::Color::white}), chess::exceptions::Invalid_move);
    ASSERT_NE(board[{"a1"}], nullptr);
    ASSERT_NE(board[{"c1"}], nullptr);
    ASSERT_EQ(board[{"e1"}], nullptr);
}

TEST_F(Rook_movement, horizontal_move_with_enemy_figure_between_start_and_end) {
    board[{"a1"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);
    board[{"c1"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::black);

    ASSERT_THROW(board.move_piece({"a1:e1", chess::Color::white}), chess::exceptions::Invalid_move);
    ASSERT_NE(board[{"a1"}], nullptr);
    ASSERT_NE(board[{"c1"}], nullptr);
}

TEST_F(Rook_movement, horizontal_move_kill_enemy_figure) {
    board[{"a1"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::white);
    board[{"c1"}] = chess::Piece_factory::create(chess::Piece_type::rook, chess::Color::black);

    ASSERT_NO_THROW(board.move_piece({"a1:c1", chess::Color::white}));
    ASSERT_EQ(board[{"a1"}], nullptr);
    ASSERT_NE(board[{"c1"}], nullptr);
    ASSERT_EQ(board[{"c1"}]->get_color(), chess::Color::white);
}
