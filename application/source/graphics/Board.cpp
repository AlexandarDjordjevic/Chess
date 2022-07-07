#include "graphics/Board.hpp"

namespace {
constexpr auto k_mark_font_size{40};
/*
______________________
|       frame        |
|  ________________  |
|  |              |  |
|  |    fields    |  |
|  |     8x8      |  |
|  |              |  |
|  |              |  |
|  |              |  |
|  |______________|  |
|____________________|
*/

constexpr auto k_frame_width{900};
constexpr auto k_frame_height{900};

constexpr auto k_frame_x{0};
constexpr auto k_frame_y{0};

constexpr auto k_board_width{800};
constexpr auto k_board_height{800};

constexpr auto k_frame_fill_color_r{186};
constexpr auto k_frame_fill_color_g{140};
constexpr auto k_frame_fill_color_b{99};

constexpr auto k_mark_frame_size{50};
constexpr auto k_fields_width{100.0f};
constexpr auto k_fields_height{100.0f};

constexpr auto k_top_horizontal_mark_position{25};
constexpr auto k_bottom_horizontal_mark_position{875};
constexpr auto k_left_vertical_mark_position{25};
constexpr auto k_right_vertical_mark_position{875};
} // namespace

namespace graphics {

Board::Board(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Resources> resources)
    : m_window{window}, m_resources{resources} {}

void Board::draw() {
    sf::Texture texture;
    sf::Image image;
    sf::Sprite sprite;

    sf::RectangleShape frame(sf::Vector2f(k_frame_width, k_frame_height));
    frame.setFillColor({k_frame_fill_color_r, k_frame_fill_color_g,
                            k_frame_fill_color_b});
    frame.setPosition(k_frame_x, k_frame_y);
    m_window->draw(frame);

    draw_side_marks();
    draw_fields();
}

void Board::draw_fields() {
    sf::Texture texture;
    sf::Image image;
    sf::Sprite sprite;
    bool white{true};

    sf::Color painting_color;
    for (auto y{0}; y < 8; ++y) {
        for (auto x{0}; x < 8; ++x) {
            painting_color =
              white ? sf::Color(145, 96, 45) : sf::Color(237, 213, 192);
            white = !white;
            image.create(k_fields_width, k_fields_height, painting_color);
            texture.loadFromImage(image);
            sprite.setPosition(x * k_fields_width + 50, y * k_fields_height + k_mark_frame_size);
            sprite.setTexture(texture);
            m_window->draw(sprite);
        }
        white = !white;
    }
}

void Board::draw_side_marks() {
    sf::Text text;
    text.setFont(*m_resources->fonts.montserrat_semi_bold);
    text.setCharacterSize(k_mark_font_size);
    text.setFillColor(sf::Color::Black);

    auto draw_mark{[this, &text](char mark, float x, float y) {
        text.setString(mark);
        auto bounds = text.getLocalBounds();
        text.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
        text.setPosition(x, y);
        m_window->draw(text);
    }};

    auto draw_horizontal_marks{[&](float y) {
        auto x{k_mark_frame_size + k_fields_width / 2};
        for (auto i{'A'}; i <= 'H'; ++i) {
            draw_mark(i, x, y);
            x += k_fields_width;
        }
    }};

    auto draw_vertical_marks{[&](float x) {
        auto y{k_mark_frame_size + k_fields_height/ 2};
        for (auto i{'1'}; i <= '8'; ++i) {
            draw_mark(i, x, y);
            y += k_fields_height;
        }
    }};

    draw_horizontal_marks(k_mark_frame_size / 2.0f);
    draw_horizontal_marks(k_frame_height - k_mark_frame_size / 2.0f);
    draw_vertical_marks(k_mark_frame_size / 2.0f);
    draw_vertical_marks(k_frame_width - k_mark_frame_size / 2.0f);
}

} // namespace graphics
