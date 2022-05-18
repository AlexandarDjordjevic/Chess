cmake_minimum_required(VERSION 3.8)

project(Chess CXX)

set(target chess)

set(CMAKE_CXX_STANDARD 20)

set(
    source
        source/Exceptions.cpp
        source/Game.cpp
        source/Move.cpp
        source/Player.cpp
        source/Position.cpp
        source/Board.cpp
        source/pieces/APiece.cpp
        source/Default_board_initializer.cpp
        source/pieces/Piece_factory.cpp

        source/pieces/Rook.cpp
        source/pieces/Bishop.cpp
        source/pieces/Knight.cpp
        source/pieces/Queen.cpp
        source/pieces/Pawn.cpp
        source/pieces/King.cpp
        source/Movement_validators.cpp
)

add_library(${target} SHARED ${source})

target_include_directories(${target} PUBLIC include)

target_link_libraries(
    ${target}
    PRIVATE pthread
)

add_subdirectory(application)
add_subdirectory(tests)


