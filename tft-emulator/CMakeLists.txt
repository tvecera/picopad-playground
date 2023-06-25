cmake_minimum_required(VERSION 3.25)
project(tft-emulator C CXX)

set(CMAKE_CXX_STANDARD 17)

# set(SFML_STATIC_LIBRARIES TRUE)

# set(SFML_DIR "c:/picopad/SFML-2.6.0/lib/cmake/SFML")

add_executable(tft-emulator main.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(tft-emulator sfml-graphics sfml-audio)
