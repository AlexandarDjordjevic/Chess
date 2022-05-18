#include "chess/Default_board_initializer.hpp"

namespace {
struct Piece_setup {
    chess::Position position;
    chess::Piece_type type;
    chess::Color color;
};

const Piece_setup k_init_data[] = {
  {.position = {"a1"}, .type = chess::Piece_type::rook, .color = chess::Color::white},
  {.position = {"b1"}, .type = chess::Piece_type::knight, .color = chess::Color::white},
  {.position = {"c1"}, .type = chess::Piece_type::bishop, .color = chess::Color::white},
  {.position = {"d1"}, .type = chess::Piece_type::queen, .color = chess::Color::white},
  {.position = {"e1"}, .type = chess::Piece_type::king, .color = chess::Color::white},
  {.position = {"f1"}, .type = chess::Piece_type::bishop, .color = chess::Color::white},
  {.position = {"g1"}, .type = chess::Piece_type::knight, .color = chess::Color::white},
  {.position = {"h1"}, .type = chess::Piece_type::rook, .color = chess::Color::white},
  {.position = {"a2"}, .type = chess::Piece_type::pawn, .color = chess::Color::white},
  {.position = {"b2"}, .type = chess::Piece_type::pawn, .color = chess::Color::white},
  {.position = {"c2"}, .type = chess::Piece_type::pawn, .color = chess::Color::white},
  {.position = {"d2"}, .type = chess::Piece_type::pawn, .color = chess::Color::white},
  {.position = {"e2"}, .type = chess::Piece_type::pawn, .color = chess::Color::white},
  {.position = {"f2"}, .type = chess::Piece_type::pawn, .color = chess::Color::white},
  {.position = {"g2"}, .type = chess::Piece_type::pawn, .color = chess::Color::white},
  {.position = {"h2"}, .type = chess::Piece_type::pawn, .color = chess::Color::white},
  {.position = {"a7"}, .type = chess::Piece_type::pawn, .color = chess::Color::black},
  {.position = {"b7"}, .type = chess::Piece_type::pawn, .color = chess::Color::black},
  {.position = {"c7"}, .type = chess::Piece_type::pawn, .color = chess::Color::black},
  {.position = {"d7"}, .type = chess::Piece_type::pawn, .color = chess::Color::black},
  {.position = {"e7"}, .type = chess::Piece_type::pawn, .color = chess::Color::black},
  {.position = {"f7"}, .type = chess::Piece_type::pawn, .color = chess::Color::black},
  {.position = {"g7"}, .type = chess::Piece_type::pawn, .color = chess::Color::black},
  {.position = {"h7"}, .type = chess::Piece_type::pawn, .color = chess::Color::black},
  {.position = {"a8"}, .type = chess::Piece_type::rook, .color = chess::Color::black},
  {.position = {"b8"}, .type = chess::Piece_type::knight, .color = chess::Color::black},
  {.position = {"c8"}, .type = chess::Piece_type::bishop, .color = chess::Color::black},
  {.position = {"d8"}, .type = chess::Piece_type::queen, .color = chess::Color::black},
  {.position = {"e8"}, .type = chess::Piece_type::king, .color = chess::Color::black},
  {.position = {"f8"}, .type = chess::Piece_type::bishop, .color = chess::Color::black},
  {.position = {"g8"}, .type = chess::Piece_type::knight, .color = chess::Color::black},
  {.position = {"h8"}, .type = chess::Piece_type::rook, .color = chess::Color::black},
};

} // namespace

namespace chess {

Default_board_initializer::Default_board_initializer() {
    for (auto& field : k_init_data) {
        auto x{field.position.get_x()};
        auto y{field.position.get_y()};
        m_data[x][y].first = field.type;
        m_data[x][y].second = field.color;
    }
}

} // namespace chess