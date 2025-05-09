cmake_minimum_required(VERSION 3.15)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 17)

add_executable(ConnectFour
        ConnectFour.cpp
        Game.cpp
        Board.cpp
        Checker.cpp
)