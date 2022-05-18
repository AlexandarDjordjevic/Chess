#include "chess/Move.hpp"
#include "chess/Exceptions.hpp"
#include <regex>

namespace chess {

Move::Move(const std::string& input, const Color& clr) {
    std::regex rgx{"([a-h][1-8]):([a-h][1-8]){1}$"};
    std::smatch match;

    if (!std::regex_search(input.begin(), input.end(), match, rgx)) {
        throw exceptions::Invalid_move(input);
    }

    start = std::make_unique<Position>(match[1]);
    end = std::make_unique<Position>(match[2]);
    piece_color = clr;
}

} // namespace chess