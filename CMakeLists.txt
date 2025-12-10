cmake_minimum_required(VERSION 3.15)

project(BlackjackSim LANGUAGES CXX)

# Use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Main executable
add_executable(blackjack_sim
    src/main.cpp
    src/Card.cpp
)

# Where we'll put headers later
target_include_directories(blackjack_sim PRIVATE include)
