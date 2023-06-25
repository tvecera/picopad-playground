cmake_minimum_required(VERSION 3.25)
project(tft-emulator C CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(tft-emulator scd4x.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(tft-emulator sfml-graphics sfml-audio)
