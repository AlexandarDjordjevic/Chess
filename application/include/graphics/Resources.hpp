#ifndef CHESS_RESOURCES_HPP
#define CHESS_RESOURCES_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

namespace graphics{

class Resources {
public:
    struct Textures{
        struct Color {
            Color() : pawn{std::make_shared<sf::Texture>()}{}
            std::shared_ptr<sf::Texture> pawn;
        };
        Color white;
        Color black;
    };

    struct Fonts{
        Fonts() : montserrat_semi_bold{std::make_shared<sf::Font>()}{}
        std::shared_ptr<sf::Font> montserrat_semi_bold;
    };

    explicit Resources(const std::string& resource_path);

public:
    Textures textures;
    Fonts fonts;

private:
    std::string m_path;
};

}


#endif // CHESS_RESOURCES_HPP
