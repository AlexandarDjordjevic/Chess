cmake_minimum_required(VERSION 3.8)

set(target Chess)

set(
    source
        source/Chess.cpp
        source/graphics/Window.cpp
        source/graphics/Artist.cpp
        source/graphics/APiece.cpp
        source/graphics/King.cpp
        source/graphics/Queen.cpp
        source/graphics/Bishop.cpp
        source/graphics/Rook.cpp
        source/graphics/Knight.cpp
        source/graphics/Score_board.cpp
        source/graphics/Resources.cpp
        source/graphics/Board.cpp
        main.cpp
)

add_executable(${target} ${source})

target_link_libraries(
    ${target}
    chess
    pthread
    sfml-graphics
    sfml-system
    sfml-window
)

target_include_directories(
        ${target}
        PRIVATE include
)
