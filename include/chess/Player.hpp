#pragma once

#include "Common.hpp"

namespace chess {

class Player {
public:
    Player(Color color);

    Player(const Player&) = delete;
    Player(Player&&) = delete;
    Player& operator=(const Player&) = delete;
    Player& operator=(Player&&) = delete;

    bool is_checked() const;
    Color get_color() const;

private:
    Color m_color;
    bool m_checked;
};

} // namespace chess
