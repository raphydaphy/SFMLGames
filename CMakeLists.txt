cmake_minimum_required(VERSION 3.7)
project(SFMLGames)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(SFMLGames ${SOURCE_FILES})

add_subdirectory(SFML)
find_package(SFML COMPONENTS graphics window system)
target_link_libraries(SFMLGames sfml-graphics sfml-window sfml-system)