#include <thread>
#include <iostream>
#include "graphics/Window.hpp"
#include "graphics/Pawn.hpp"
#include "graphics/Board.hpp"

#define RESOURCES_PATH "/home/syrmia/Documents/work/Chess/application/resources/"

namespace graphics {

Window::Window()
    : m_window{std::make_shared<sf::RenderWindow>(sf::VideoMode(900, 900), "Chess")},
      m_resources{std::make_shared<Resources>(RESOURCES_PATH)}, m_artist{std::make_unique<Artist>(
                                                                  m_resources)} {}

void Window::worker() {
    Board board{m_window, m_resources};
    board.draw();
    Pawn p1{m_window, m_resources->textures.black_pawn};
    Pawn p2{m_window, m_resources->textures.black_pawn};
    Pawn p3{m_window, m_resources->textures.black_pawn};
    p1.draw(60, 160);
    p2.draw(160, 160);
    p3.draw(260, 160);


    while (m_window->isOpen()) {
        sf::Event event;
        m_window->waitEvent(event);
        switch (event.type) {
        case sf::Event::EventType::Closed:
            std::cout << "Window is closed" << std::endl;
            m_window->close();
            break;
        case sf::Event::EventType::MouseButtonPressed:
            std::cout << "Mouse button pressed!" << std::endl;
            break;
        case sf::Event::EventType::MouseButtonReleased:
            std::cout << "Mouse button released!" << std::endl;
            break;
        case sf::Event::EventType::MouseMoved:
            break;
        default:
            break;
        }
        m_window->display();
    }
}

} // namespace graphics