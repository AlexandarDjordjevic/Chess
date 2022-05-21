cmake_minimum_required(VERSION 3.8)

set(target chess_tests)

set(CMAKE_CXX_FLAGS "-fPIE")

set(
    source
        source/Position_tests.cpp
        source/Rook_tests.cpp
        source/Queen_tests.cpp
        source/Bishop_tests.cpp
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${target} ${source})

target_link_libraries(
    ${target}
    ${GTEST_BOTH_LIBRARIES}
    pthread
    chess
)

add_test(
    NAME ${target}
    COMMAND ${target}
)