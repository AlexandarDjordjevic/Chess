#include <gtest/gtest.h>
#include "chess/Position.hpp"

class Input_position_tests : public testing::Test {
    struct Test_case {
        Test_case(std::string in, int x, int y)
            : input{std::move(in)}, expected_x{x}, expected_y{y} {}
        std::string input;
        int expected_x;
        int expected_y;
    };

public:
    std::vector<Test_case> valid_inputs;
    const std::vector<std::string> invalid_inputs{"A1", "LL", "A0", "A9", "AF",  "F0",
                                                  "F9", "99", "9F", "G1", "A11", "Invalid Input"};

    void SetUp() override {
        valid_inputs.reserve(64);
        for (auto ch : {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}) {
            for (auto i{1}; i < 9; ++i) {
                valid_inputs.emplace_back(Test_case{ch + std::to_string(i), ch - 'a', i - 1});
            }
        }
    }
};

TEST_F(Input_position_tests, test_valid_inputs) {
    for (const auto& input : valid_inputs) {
        ASSERT_NO_THROW({
            auto pos{chess::Position(input.input)};
            ASSERT_EQ(input.expected_x, pos.get_x());
            ASSERT_EQ(input.expected_y, pos.get_y());
        });
    }
}

TEST_F(Input_position_tests, test_invalid_inputs) {
    for (const auto& input : invalid_inputs) {
        ASSERT_THROW((chess::Position(input)), std::invalid_argument);
    }
}
