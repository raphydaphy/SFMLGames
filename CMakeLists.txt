cmake_minimum_required(VERSION 3.7)
project(SFMLGames)

set(CMAKE_CXX_STANDARD 17)


# SFML
set(SFML_DIR "${PROJECT_SOURCE_DIR}/SFML")
set(SFML_ROOT ${SFML_DIR})
set(CMAKE_MODULE_PATH "${SFML_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)

include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES main.cpp)
add_executable(SFMLGames ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})