cmake_minimum_required(VERSION 3.8)

set(target Chess)

set(
    source
        Chess.cpp
        main.cpp
)

add_executable(${target} ${source})

target_link_libraries(
    ${target}
    chess
    pthread
)