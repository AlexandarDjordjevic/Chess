#include "graphics/Resources.hpp"

namespace graphics {

Resources::Resources(const std::string& resource_path) : m_path{resource_path} {
    textures.black.pawn->loadFromFile(resource_path + "images/black_pawn.png");
    textures.white.pawn->loadFromFile(resource_path + "images/white_pawn.png");
    fonts.montserrat_semi_bold->loadFromFile(resource_path + "fonts/Montserrat-SemiBold.ttf");
}

} // namespace graphics